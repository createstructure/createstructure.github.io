"""This is the magic bot by Castellani Davide :)
With this programm you can easily create a repository on GitHub with a basic template, personalized for your use.

If there was any type of problem you can contact me on my help email: help@castellanidavide.it
"""
# Some imports
from datetime import datetime as dt
from getpass import getpass
from github import Github
from re import escape, compile
from requests import get as wget
from time import sleep
from threading import Thread, active_count, Lock
from sys import argv

__author__ = "help@castellanidavide.it"
__version__ = "7.1 2021-02-13"

class createstructure:
	def __init__ (self, token=None, souces=['CastellaniDavide'], organization_name="", IGNORE=[], verbose=False, template=False, answers=None):
		"""Main function
		"""
		# Set main variabiles
		self.CONTINUE = True
		self.TOKEN = token
		self.ORGANIZATION_NAME = organization_name
		self.IGNORE = IGNORE
		self.VERBOSE = verbose
		self.TEMPLATE = template
		self.ANSWERS = answers
		self.PUSH = Lock()

		# Initial inputs
		self.initial_inputs()

		if self.CONTINUE:
			self.login() # Login

			# Make questions
			self.asks()

			# Make repo
			Thread(target = self.create_repo()).start()

			# Get template
			self.choose_template()

			# Get changes
			self.change_map()
			
			# Make all
			self.scan_and_elaborate()

	def initial_inputs(self):
		"""Initial input read
		"""

		# Check if there were all argv
		try:
			# Go to documentation if requested
			assert (not("-h" in argv or "--help" in argv))

			# Read arguments
			for arg in argv:
				# find folders and files
				if "--ignore=" in arg or "-i=" in arg:
					self.IGNORE = [i for i in arg.replace("--ignore=", "").replace("-i=", "").replace("'", "").replace('"', "")[1:-1].split(",")]
				# find organization
				if "--organization=" in arg or "-o=" in arg:
					self.ORGANIZATION_NAME = arg.replace("--organization=", "").replace("-o=", "")
				# find token
				if "--token=" in arg or "-t=" in arg:
					self.TOKEN = arg.replace("--token=", "").replace("-t=", "")
				# find verbose
				if "--vebose" in arg or "-v" in arg:
					self.VERBOSE = True
				# find verbose
				if "--template" in arg or "-temp" in arg:
					self.TEMPLATE = True
		
			# Check all data
			assert(self.TOKEN != "TODO" and self.TOKEN != None and self.TOKEN != "***")

			if self.VERBOSE : print(f"{self.get_emoji('i')}self.CONTINUE\t\t\t{self.CONTINUE}\n{self.get_emoji('i')}self.TOKEN\t\t\t{self.TOKEN}\n{self.get_emoji('i')}self.ORGANIZATION_NAME\t{self.ORGANIZATION_NAME}\n{self.get_emoji('i')}self.IGNORE\t\t\t{self.IGNORE}\n{self.get_emoji('i')}self.VERBOSE\t\t\t{self.VERBOSE}")

		except:
			self.CONTINUE = False
			documentation = ["usage createstructure",
							"\t[--ignore= | -i=]",
							"\t[--organization= | -o=]",
							"\t[--sources= | -s=]",
							"\t[--template | -temp]"
							"\t[--token= | -t=]",
							"\t[--verbose | -v]",
							"",
							"These are the createstructure arguments:",
							"\t--ignore= or -i=		(optional) The folders to be ignored",
							"\t--organization= or -o=		(optional) The organization name, leave empty if you want to create repos in your personal account",
							"\t--sources= or -s=		(optional) The array with your favourite sources, for eg. ['CastellaniDavide']",
							"\t--token= or -t=			The GitHub tocken with repo and organization permission",
							"\t--template= or -temp=		Create a template",
							"\t--verbose or -v			Verbose option, you will see the main variabiles and lots more"
							"",
							"Extra situation(s):",
							"\t--help or -h			To see the documentation",
							"",
							"Made with ❤  by Castellani Davide (@DavideC03)",
							""]

			for line in documentation:
				print(line)
	
	def login(self):
		"""Made the login in GitHub
		"""
		self.g = Github(self.TOKEN)
	
	def asks(self):
		"""Manage the run variabiles
		"""
		if self.ANSWERS == None: # Make questions
			questions = [["name",		"Name of the project (es. createstructure): "],
						["template",	"Select the template to use (es. default): "],
						["descr",		"Description of the project: "],
						["prefix",		"Insert a prefix for the repository (or don't insert anything): "],
						["team",		"Do you want insert this repo into a team? [y/N]: "],
						["private",		"Is that private? [y/N]: "],
						]
			self.ANSWERS = {}
			
			# Get infos
			for question_tag, current_quest in questions:
				if question_tag == "team":
					self.ANSWERS["team"] = ""	# default value
					if self.ORGANIZATION_NAME != "":	# If there is an organization
						if createstructure.is_positive(input(f"{self.get_emoji('?')}{current_quest}")):
							self.choose_team()						
				else:
					self.ANSWERS[question_tag] = input(f"{self.get_emoji('?')}{current_quest}")

			if "template" in self.ANSWERS:
				self.ANSWERS["extention"] = self.ANSWERS["template"].replace("/", "-").split("-")[:-1]

			print()

	def choose_team(self):
		"""Choose a team
		"""
		try:
			# Search teams
			teams = self.g.get_organization(self.ORGANIZATION_NAME).get_teams()
			
			nteams = 0
			# Give the option to the user
			for i, team in enumerate(teams):
				nteams += 1
				print(f"\t{i})\t{team.name}")

			assert (nteams != 0)

			# Save answer
			answer = input(f"{self.get_emoji('?')}Insert your team number or the name of a new team: ")

			# Save the team choosen
			try:
				self.ANSWERS["team"] = teams[int(answer)].name
			except:
				try:
					int(answer)
					print("This team didn't exist, try again")
					self.choose_team()
				except:
					self.ANSWERS["team"] = answer	# Create a new team on running
		except:	# No teams
			print("Sorry, you didn't have any team. Create a new team to use this option")

	def create_repo(self):
		"""Create the repo
		"""
		if self.TEMPLATE and not self.ANSWERS['name'].endswith("-template"): # Add -template if not exists
			self.ANSWERS['name'] = self.ANSWERS['name'] + "-template"			

		if self.ORGANIZATION_NAME == "":
			self.repo = self.g.get_user().create_repo(self.ANSWERS['name'] if(self.ANSWERS['prefix'] == "") else f"{self.ANSWERS['prefix']}-{self.ANSWERS['name']}", description=self.ANSWERS['descr'], private=createstructure.is_positive(self.ANSWERS['private']), has_issues=True, has_wiki=False, has_downloads=True, has_projects=False)
		else:
			if self.ANSWERS["team"] == "":
				self.repo = self.g.get_organization(self.ORGANIZATION_NAME).create_repo(self.ANSWERS['name'] if(self.ANSWERS['prefix'] == "") else f"{self.ANSWERS['prefix']}-{self.ANSWERS['name']}", description=self.ANSWERS['descr'], private=createstructure.is_positive(self.ANSWERS['private']), has_issues=True, has_wiki=False, has_downloads=True, has_projects=False)
			else:
				# Create team if not exists
				try: 
					self.g.get_organization(self.ORGANIZATION_NAME).create_team(self.ANSWERS["team"], privacy="closed")
				except: 
					pass

				self.repo = self.g.get_organization(self.ORGANIZATION_NAME).create_repo(self.ANSWERS['name'] if(self.ANSWERS['prefix'] == "") else f"{self.ANSWERS['prefix']}-{self.ANSWERS['name']}", description=self.ANSWERS['descr'], private=createstructure.is_positive(self.ANSWERS['private']), has_issues=True, has_wiki=False, has_downloads=True, has_projects=False, team_id=[i for i in self.g.get_organization(self.ORGANIZATION_NAME).get_teams() if i.name == self.ANSWERS["team"]][0].id)
		
		if self.ANSWERS['name'].endswith("-template"):
			self.ANSWERS['name'] = self.ANSWERS['name'][:len(self.ANSWERS['name']) - len("-template"):]
		print(f"{self.get_emoji('ok')}Repo built")

	def choose_template(self):
		"""This helps to find the correct template
		"""
		# Add -template if not exists
		if not self.ANSWERS['template'].endswith("-template"):
			self.ANSWERS['template'] += "-template"

		if "/" in self.ANSWERS['template']: # If it's yours
			try:
				self.template_name = self.g.get_repo(f"{self.ANSWERS['template']}").full_name
				assert(self.g.get_repo(self.template_name).private == True)
			except:
				print(f"{self.get_emoji('i')}{self.ANSWERS['template']} not founded, now I want to use the default repo")
				self.template_name = "createstructure/default-template"
		else: # If you want to use the template into createstructure Organization
			try:
				self.template_name = self.g.get_repo(f"createstructure/{self.ANSWERS['template']}").full_name
			except:
				print(f"{self.get_emoji('i')}{self.ANSWERS['template']} not founded, now I want to use the default repo")
				self.template_name = "createstructure/default-template"

		self.template = self.g.get_repo(self.template_name)
		print(f"{self.get_emoji('ok')}Template founded ({self.template_name})")
		
	def scan_and_elaborate(self, loc=""):
		"""Scan all files in the repository and push it in the new directory (cahanging the necessary)
		"""
		if self.TEMPLATE and loc == "":
			self.create_file(".createstructure/change.json", self.g.get_repo("createstructure/default-template").get_contents(".createstructure/change.json").decoded_content.decode())

		contents = self.template.get_contents(f"{loc}")
		for content_file in sorted(contents, reverse=True, key=createstructure.name_of_path): # Put .folders at the end
			if not content_file.path in [".createstructure", ""] + self.IGNORE:
				if content_file.path == ".github/workflows": # Wait the end of others before do workflows
					start_waiting = dt.now().timestamp()
					while (active_count() != 2 and dt.now().timestamp() - start_waiting < 60): pass # Wait the end of processes or 60 seconds (a minute)

				if content_file.type == "file":
					try:
						Thread(target = self.create_file, args = (self.change(content_file.path), self.change(self.g.get_repo(self.template_name).get_contents(content_file.path).decoded_content.decode()))).start()
					except: # If it's not a text file (eg. is an image)
						Thread(target = self.create_file, args = (self.change(content_file.path), self.g.get_repo(self.template_name).get_contents(content_file.path).decoded_content)).start()
				else:
					Thread(target = self.scan_and_elaborate, args = (content_file.path, )).start()		

	def name_of_path(item):
		"""For sorting the folders, gives the path attributes
		"""
		if item.path == ".github/workflows":
			return "..." # move to the end
		else:
			return item.path

	def change_map(self):
		"""Returns a map of changes
		"""
		time = dt.now()
		change_map = {}
		change_map_special = {}
		
		# escape value
		change_map["solsol"] = "sol"

		# repo changes
		change_map = eval(self.g.get_repo(self.template_name).get_contents(".createstructure/change.json").decoded_content.decode())

		# answer changes
		for key, value in self.ANSWERS.items():
			change_map_special[f"sol{key}sol"] = value

		# special changes
		change_map_special["time__now"] = f"{str(time.year)}-{str(time.month)}-{str(time.day)}"
		change_map_special["time_now"]  = f"{str(time.year)}{str(time.month)}{str(time.day)}"

		# re dict, because I can use it faster (eg. for changes)
		self.change_map = dict((escape(k), v) for k, v in change_map.items())
		self.change_map_special = dict((escape(k), v) for k, v in change_map_special.items())

	def change(self, text):
		"""Returns the changed page
		Change two times: first one for normal keys, second one for special one
		"""
		return compile("|".join(self.change_map_special.keys())).sub(lambda m: self.change_map_special[escape(m.group(0))], compile("|".join(self.change_map.keys())).sub(lambda m: self.change_map[escape(m.group(0))], text))

	def create_file(self, path, file):
		"""Create the file into the repo
		"""
		try:
			with self.PUSH:
				self.repo.create_file(path, f"Created {path}", file)
				print(f"{self.get_emoji('ok')}Created {path}")
		except:
			print(f"There was an error to this file: {path}")

	def is_positive(answer):
		"""Returns true is the answer is affermative
		"""
		return answer in ["y", "Y", "yes", "Yes"]

	def get_emoji(self, emoji):
		"""Returns the selected emoji
		"""
		if emoji == "?":
			return "\u2753 "
		elif emoji == "i":
			return "\u2139 "
		elif emoji == "ok":
			return "\u2714 "
		return ""

if __name__ == "__main__":
	""" Entry point
	"""
	createstructure() # Entry point	
	