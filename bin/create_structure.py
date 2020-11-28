"""This is the magic "robottino" by Castellani Davide
With this programm you can easly create a repository on GitHub with a basic template, personalized for your use.

If there was any type of problem you can contact me on my help email: help@castellanidavide.it
"""
# Some imports
import os
from datetime import *
from github import Github
import pygit2
from getpass import getpass
import requests

__author__ = "help@castellanidavide.it"
__version__ = "5.0 2020-11-21"

TOKEN = "TODO"
SOUCES_OF_TEMPLATES = ["TODO", "CastellaniDavide"]
ORGANIZATION_NAME = "TODO" # Leave empty if you want to add into your personal GitHub account

class create_structure:
	def __init__ (self):
		"""Main function
		"""
		g = create_structure.login() # Login

		# Make questions
		questions = [["name",		"Name of the project (es. create_structure): "],
					 ["extention",	"Extenction of the main programm (es. py): "],
					 ["descr",		"Description of the project: "],
					 ["prefix",		"Insert the prefix of the repository (or don't insert something): "],
					 ["team",		"Do you want insert this repo into a team? [Y/n]: "],
					 ["private",	"Is that private?(Y/N): "],
					]
		results = {}

		# Get infos
		for question_tag, current_quest in questions:
			if question_tag == "team":
				if ORGANIZATION_NAME != "":	# If there is an organization
					if input(current_quest) == "Y":
						create_structure.choose_team(g, results)
					else:
						results["team"] = ""
			else:
				results[question_tag] = input(current_quest)
		
		print()

		# Make repo
		repo = create_structure.create_repo(results, g)
		print(f"Repo built")

		typerepo = create_structure.choose_template(results, g)
		print(f"Template founded ({typerepo})")

		create_structure.scan_and_elaborate(repo, g.get_repo(typerepo), "", typerepo, results)
	
	def login():
		"""Made the login in GitHub
		"""
		return Github(TOKEN)

	def choose_team(g, results):
		"""Choose a team
		"""
		teams = g.get_organization('CastellaniDavide').get_teams()
		for i, team in enumerate(teams):
			print(f"{i})\t{team.name}")

		try:
			results["team"] = teams[int(input("Insert your team number: "))].id
		except:
			print("This team didn't exist, try again")
			create_structure.choose_team(g, results)

	def create_repo(results, g):
		"""Create the repo in CastellaniDavide repository
		"""
		if ORGANIZATION_NAME == "":
			return g.get_user().create_repo(results['name'] if(results['prefix'] == "") else f"{results['prefix']}-{results['name']}", description=results['descr'], private=results['private'] == "Y", has_issues=True, has_wiki=False, has_downloads=True, has_projects=False)
		else:
			if results["team"] == "":
				return g.get_organization(ORGANIZATION_NAME).create_repo(results['name'] if(results['prefix'] == "") else f"{results['prefix']}-{results['name']}", description=results['descr'], private=results['private'] == "Y", has_issues=True, has_wiki=False, has_downloads=True, has_projects=False)
			else:
				return g.get_organization(ORGANIZATION_NAME).create_repo(results['name'] if(results['prefix'] == "") else f"{results['prefix']}-{results['name']}", description=results['descr'], private=results['private'] == "Y", has_issues=True, has_wiki=False, has_downloads=True, has_projects=False, team_id=results["team"])

	def choose_template(results, g):
		"""This helps to find the correct template
		"""
		# Check if there is my template
		for source in SOUCES_OF_TEMPLATES:
			if source != "TODO":
				try:
					return g.get_repo(f"{source}/{results['extention']}-template").full_name
				except:
					pass

		# Check if there was a default template
		for source in SOUCES_OF_TEMPLATES:
			if source != "TODO":
				try:
					return g.get_repo(f"{source}/default-template").full_name
				except:
					pass

		# If there wasn't any template for your type of extention and no one default into SOURCES list, give my default code
		return "CastellaniDavide\default"

	def scan_and_elaborate(repo, template, loc, typerepo, results):
		"""Scan all files in the repository and push it in the new directory (cahanging the necessary)
		"""
		contents = template.get_contents(f"{loc}")
		for content_file in contents:
			if not content_file.path in [".castellanidavide", "", ".vs"]:
				print(content_file.path)
				if "." in content_file.path and not content_file.path[0] == "." and not "default" in content_file.path:
					try:
						create_structure.scan_and_elaborate(repo, template, content_file.path, typerepo, results)
					except:
						create_structure.elaborate_file(repo, typerepo, content_file.path, results)
				else:
					try:
						create_structure.scan_and_elaborate(repo, template, content_file.path, typerepo, results)
					except:
						create_structure.elaborate_file(repo, typerepo, content_file.path, results)

	def elaborate_file(repo, typerepo, filepath, results):
		"""Elaborate the file
		"""		
		page = requests.get(f"https://raw.githubusercontent.com/{typerepo}/master/{filepath}").text
				
		try:
			page = create_structure.change(page, typerepo, results)
			repo.create_file(filepath.replace("template", results['name']), f"Created {filepath}", f"{page}")
			print(f"Created {filepath.replace('template', results['name'])}")
		except:
			print(f"Error {filepath.replace('template', results['name'])}\t{type(page)}\n{page}")

	def change(page, typerepo, results):
		"""Returns the changed page
		"""
		data = eval(requests.get(f"https://raw.githubusercontent.com/{typerepo}/master/.castellanidavide/change.json").text)
		advanced_values = { f"sol{i}sol" : j for i, j in results.items()}
		time = datetime.now()
		time = f"{str(time.year)}-{str(time.month)}-{str(time.day)}"

		for i in data.keys():
			page = page.replace(i.replace("'''", '"'), data[i].replace("'''", '"'))

		for i in advanced_values.keys():
			page = page.replace(i, advanced_values[i])

		page = page.replace("time__now", time)
		page = page.replace("time_now", time.replace("_", "").replace("-", ""))
		
		return page

if __name__ == "__main__":
	assert TOKEN != "TODO", "You must to put your tocken into TOKEN variable"
	assert ORGANIZATION_NAME != "TODO", "You must to set ORGANIZATION_NAME variable"
	
	try:
		create_structure()
	except:
		print("There is an error, try to check if the repo name is already used.")
