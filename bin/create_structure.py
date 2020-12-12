"""This is the magic "robottino" by Castellani Davide
With this programm you can easly create a repository on GitHub with a basic template, personalized for your use.

If there was any type of problem you can contact me on my help email: help@castellanidavide.it
"""
# Some imports
from datetime import datetime as dt
from getpass import getpass
from github import Github
from re import escape, compile
from requests import get as wget
from threading import Thread
import settings # Import project settings

__author__ = "help@castellanidavide.it"
__version__ = "5.4 2020-12-12"

class create_structure:
	def __init__ (self):
		"""Main function
		"""

		Thread(target = self.login()).start() # Login

		# Make questions
		self.asks()

		# Make repo
		Thread(target = self.create_repo()).start()

		# Get template
		self.choose_template()

		# Get changes
		self.change_map()
		
		# Make all
		Thread(target = self.scan_and_elaborate()).start()
	
	def login(self):
		"""Made the login in GitHub
		"""
		self.g = Github(TOKEN)
	
	def asks(self):
		questions = [["name",		"Name of the project (es. create_structure): "],
					 ["extention",	"Extenction of the main programm (es. py): "],
					 ["descr",		"Description of the project: "],
					 ["prefix",		"Insert the prefix of the repository (or don't insert anything): "],
					 ["team",		"Do you want insert this repo into a team? [Y/n]: "],
					 ["private",	"Is that private? [Y/n]: "],
					]
		self.results = {}
		
		# Get infos
		for question_tag, current_quest in questions:
			if question_tag == "team":
				self.results["team"] = ""	# default value
				if ORGANIZATION_NAME != "":	# If there is an organization
					if input(current_quest) == "Y":
						self.choose_team()						
			else:
				self.results[question_tag] = input(current_quest)

		print()

	def choose_team(self):
		"""Choose a team
		"""
		try:	# No teams
			teams = self.g.get_organization(ORGANIZATION_NAME).get_teams()
			enumerate(teams)[0]
			for i, team in enumerate(teams):
				print(f"{i})\t{team.name}")

			try:
				self.results["team"] = teams[int(input("Insert your team number: "))].id
			except:
				print("This team didn't exist, try again")
				self.choose_team()
		except:
			print("Sorry, you didn't have any team. Create a new team to use this option")

	def create_repo(self):
		"""Create the repo
		"""
		if ORGANIZATION_NAME == "":
			self.repo = self.g.get_user().create_repo(self.results['name'] if(self.results['prefix'] == "") else f"{self.results['prefix']}-{self.results['name']}", description=self.results['descr'], private=self.results['private'] == "Y", has_issues=True, has_wiki=False, has_downloads=True, has_projects=False)
		else:
			if self.results["team"] == "":
				self.repo = self.g.get_organization(ORGANIZATION_NAME).create_repo(self.results['name'] if(self.results['prefix'] == "") else f"{self.results['prefix']}-{self.results['name']}", description=self.results['descr'], private=self.results['private'] == "Y", has_issues=True, has_wiki=False, has_downloads=True, has_projects=False)
			else:
				self.repo = self.g.get_organization(ORGANIZATION_NAME).create_repo(self.results['name'] if(self.results['prefix'] == "") else f"{self.results['prefix']}-{self.results['name']}", description=self.results['descr'], private=self.results['private'] == "Y", has_issues=True, has_wiki=False, has_downloads=True, has_projects=False, team_id=self.results["team"])
		
		print(f"Repo built")

	def choose_template(self):
		"""This helps to find the correct template
		"""
		# If there wasn't any other template for your type of extention and no one default into SOURCES list, give my default code
		self.template_name = "CastellaniDavide/default-template" 

		# Check if there is my template
		for source in SOUCES_OF_TEMPLATES:
			if source != "TODO" and self.template_name == "CastellaniDavide/default-template":
				try:
					self.template_name = self.g.get_repo(f"{source}/{results['extention']}-template").full_name
					break
				except:
					pass

		# Check if there was a default template
		if self.template_name == "CastellaniDavide/default-template":
			for source in SOUCES_OF_TEMPLATES:
				if source != "TODO" and self.template_name == "CastellaniDavide/default-template":
					try:
						self.template_name = self.g.get_repo(f"{source}/default-template").full_name
						break
					except:
						pass
		
		self.template = self.g.get_repo(self.template_name)
		print(f"Template founded ({self.template_name})")
		
	def scan_and_elaborate(self, loc=""):
		"""Scan all files in the repository and push it in the new directory (cahanging the necessary)
		"""
		contents = self.template.get_contents(f"{loc}")
		for content_file in contents:
			if not content_file.path in [".castellanidavide", ""] + IGNORE_FOLDERS:
				if content_file.type == "file":
					Thread(target = self.create_file, args = (self.change(content_file.path), f"{self.change(wget(f'https://raw.githubusercontent.com/{self.template_name}/master/{content_file.path}').text)}")).start()
				else:
					Thread(target = self.scan_and_elaborate, args = (content_file.path, )).start()				
					
	def change_map(self):
		"""Returns a map of changes
		"""
		time = dt.now()
		
		# repo changes
		change_map = eval(wget(f"https://raw.githubusercontent.com/{self.template_name}/master/.castellanidavide/change.json").text)

		# answer changes
		for key, value in self.results.items():
			change_map[f"sol{key}sol"] = value

		# special changes
		change_map["time__now"] = f"{str(time.year)}-{str(time.month)}-{str(time.day)}"
		change_map["time_now"]  = f"{str(time.year)}{str(time.month)}{str(time.day)}"

		# re dict, because I can use it faster (eg. for changes)
		self.change_map = dict((escape(k), v) for k, v in change_map.items())

	def change(self, text):
		"""Returns the changed page
		Change two times for special keys
		"""
		return compile("|".join(self.change_map.keys())).sub(lambda m: self.change_map[escape(m.group(0))], compile("|".join(self.change_map.keys())).sub(lambda m: self.change_map[escape(m.group(0))], text))

	def create_file (self, path, file):
		"""Create the file into the repo
		"""
		try:
			self.repo.create_file(path, f"Created {path}", file)
			print(f"Created {path}")
		except:
			# If it's an error, possible with multitreading, try again
			self.create_file (path, file)

if __name__ == "__main__":
	assert TOKEN != "TODO", "You must to put your tocken into TOKEN variable"
	assert ORGANIZATION_NAME != "TODO", "You must to set ORGANIZATION_NAME variable"
	
	try:
		create_structure()
	except:
		print("There is an error, try to check if the repo name is already used.")
