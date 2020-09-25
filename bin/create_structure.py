"""This is the magic "robottino" by Castellani Davide & Sabaini Chiara
"""
# Imports
import os
from datetime import *
from github import Github
import pygit2
from getpass import getpass
import requests

__author__ = "help@castellanidavide.it"
__version__ = "4.0 2020-09-25"

TOKEN = "<INSERT_YOUR_TOKEN>"

class create_structure:
	def __init__ (self):
		"""Main function
		"""
		questions = [	"Inserisci nome progetto (es. create_structure): ",																	#0
						"Inserisci estensione file principale (es. py): ",																	#1
						"Inserisci una descrizione del progetto: ",																			#2
						"Il progetto è con Boscaini (<nome della classe>-<numero consegna>), Bellini (b) o qualcunaltro(lasciare vuoto)? ",	#3
						"Questo progetto è con la Chiara?(Y/N): ",																			#4
						"Questo progetto è privato?(Y/N): ",																				#5																		#7
					]
		results = []

		for i, current_quest in enumerate(questions):
			"""if i == len(questions) - 1:
				results.append(getpass(prompt=current_quest))
			else:
				results.append(input(current_quest))"""
			results.append(input(current_quest))
		
		print()

		g = create_structure.login(results)
		print(f"Credentials OK")

		folder_name = f"./{results[0].lower()}_01_01" if (results[3] == "b") else (f"./{results[0]}" if(results[3] == "") else f"./{results[3]}-{results[0]}")
		if results[5] == "N":
			create_structure.create_folder(folder_name)
			print(f"Folder built")

		repo = create_structure.create_repo(results, g)
		print(f"Repo built")

		typerepo = create_structure.choose_template(results, g)
		print(f"Template founded ({typerepo})")

		template = g.get_repo(f"CastellaniDavide/{typerepo}-template")
		create_structure.scan_and_elaborate(repo, template, "", typerepo, results)

		os.system(f"git clone git@github.com:CastellaniDavide/{results[0]}.git", shell=False)
		print(f"repo downloaded")
	
	def login(results):
		"""Made the login in GitHub
		"""
		return Github(TOKEN)

	def create_folder(directory):
		"""Creates a folder
		"""
		try:
			if not os.path.exists(directory):
				os.makedirs(directory)
		except OSError:
			print ('Error: Creating directory. ' +  directory)

	def create_repo(results, g):
		"""Create the repo in CastellaniDavide repository
		"""
		if results[4] == "Y":
			repo = g.get_organization("CastellaniDavide").create_repo(results[0] if(results[3] == "" or results[3] == "b") else f"{results[3]}-{results[0]}", description=results[2], private=results[5] == "Y", has_issues=True, has_wiki=False, has_downloads=True, has_projects=False, team_id=4008430)
		else:
			repo = g.get_organization("CastellaniDavide").create_repo(results[0] if(results[3] == "" or results[3] == "b") else f"{results[3]}-{results[0]}", description=results[2], private=results[5] == "Y", has_issues=True, has_wiki=False, has_downloads=True, has_projects=False)
			
		return repo

	def choose_template(results, g):
		"""This helps to find the correct template
		"""
		try:
			g.get_repo(f"CastellaniDavide/{results[1]}-template")
			return f"{results[1]}"
		except:
			return "default"

	def scan_and_elaborate(repo, template, loc, typerepo, results):
		"""Scan all files in the repository and push it in the new directory (cahanging the necessary)
		"""
		contents = template.get_contents(f"{loc}")
		for content_file in contents:
			if not content_file.path in [".castellanidavide", "", ".vs"]:
				if "." in content_file.path and not content_file.path[0] == ".":
					create_structure.elaborate_file(repo, typerepo, content_file.path, results)
				else:
					try:
						create_structure.scan_and_elaborate(repo, template, content_file.path, typerepo, results)
					except:
						create_structure.elaborate_file(repo, typerepo, content_file.path, results)

	def elaborate_file(repo, typerepo, filepath, results):
		"""Elaborate the file
		"""
		try:
			page = requests.get(f"https://raw.githubusercontent.com/CastellaniDavide/{typerepo}-template/master/{filepath}").text
			page = create_structure.change(page, typerepo, results)
			repo.create_file(filepath.replace("template", results[0]), f"Created {filepath}", f"{page}")
			print(f"Created {filepath.replace('template', results[0])}")
		except:
			print(f"Error {filepath.replace('template', results[0])}\t{type(page)}\n{page}")

	def change(page, typerepo, results):
		"""Returns the changed page
		"""
		data = eval(requests.get(f"https://raw.githubusercontent.com/CastellaniDavide/{typerepo}-template/master/.castellanidavide/change.json").text)
		advanced_values = { f"sol{i}sol" : j for i, j in enumerate(results)}
		time = datetime.now()
		time = f"{str(time.year)}-{str(time.month)}-{str(time.day)}"

		for i in data.keys():
			page = page.replace(i.replace("'''", '"'), data[i].replace("'''", '"'))

		for i in advanced_values.keys():
			page = page.replace(i, advanced_values[i])

		page = page.replace("time__now", time)
		page = page.replace("time_now", time.replace("_", ""))
		
		return page
		
	def download_repo(repo, folder_name):
		"""Downloads the repo into folder_name
		"""
		pygit2.clone_repository(repo.git_url, folder_name)

if __name__ == "__main__":
	assert(TOKEN == "<INSERT_YOUR_TOKEN>", "You must to put your tocken into TOKEN variable")
	try:
		create_structure()
	except:
		print("There is an error, try again.")
