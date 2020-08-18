"""This is the magic "robottino" by Castellani Davide & Sabaini Chiara
"""
# Imports
import os
from datetime import *
from github import Github
import pygit2
from getpass import getpass

__author__ = "davidecastellani@castellanidavide.it", "chiara@sabaini.com"
__version__ = "03.01 2020-08-15"

class create_structure_03_01:
	def __init__ (self):
		"""Main function
		"""
		questions = [	"Inserisci nome progetto (es. create_structur): ",																	#0
						"Inserisci estensione file principale (es. py): ",																	#1
						"Inserisci una descrizione del progetto: ",																			#2
						"Il progetto è con Boscaini (<nome della classe>-<numero consegna>), Bellini (b) o qualcunaltro(lasciare vuoto)? ",	#3
						"Questo progetto è con la Chiara?(Y/N): ",																			#4
						"Questo progetto è privato?(Y/N): ",																				#5
						"Inserisci il tuo username di GitHub: ",																			#6
						"Inserisci la tua password su GitHub: "																				#7
					]
		results = []

		for i, current_quest in enumerate(questions):
			if i == len(questions) - 1:
				results.append(getpass(prompt=current_quest))
			else:
				results.append(input(current_quest))
		
		print()

		folder_name = f"./{results[0].lower()}_01_01" if (results[3] == "b") else (f"./{results[0]}" if(results[3] == "") else f"./{results[3]}-{results[0]}")
		create_structure_03_01.create_folder(folder_name)
		print(f"Folder built")

		repo = create_structure_03_01.create_repo(results)
		print(f"Repo built")

		create_structure_03_01.create_source(repo, results)
		print(f"Source file built")

		create_structure_03_01.create_README(repo, results)
		print(f"README.md built")

		create_structure_03_01.create_log(repo)
		print(f"trace.log built")

		create_structure_03_01.download_repo(repo, folder_name)
		print(f"repo downloaded")

	def create_folder(directory):
		"""Creates a folder
		"""
		try:
			if not os.path.exists(directory):
				os.makedirs(directory)
		except OSError:
			print ('Error: Creating directory. ' +  directory)

	def create_repo(results):
		"""Create the repo in CastellaniDavide repository
		"""
		if results[4] == "Y":
			repo = Github(results[6], results[7]).get_organization("CastellaniDavide").create_repo(results[0], description=results[2], private=results[5] == "Y", has_issues=False, has_wiki=False, has_downloads=True, has_projects=False, team_id=4008430)
		else:
			repo = Github(results[6], results[7]).get_organization("CastellaniDavide").create_repo(results[0], description=results[2], private=results[5] == "Y", has_issues=False, has_wiki=False, has_downloads=True, has_projects=False)

		return repo

	def create_source(repo, results):
		"""Writes the standards line of code based on the extension
		"""
		time = datetime.now()

		if(results[1] == "py"):
			text = f'"""{results[0]}\n"""\n\n__author__ = "davidecastellani@castellanidavide.it", "chiara@sabaini.com"\n__version__ = "01.01 {str(time.day)}-{str(time.month)}-{str(time.day)}"\n\n'	# first part
			text += f'class {results[0]}:\n\tdef __init__ (self):\n\nif __name__ == "__main__":\n\t{results[0]}()'
		elif(results[1] == "js"):
			text = f'/**\n * @file {results[0]}.{results[1]}\n *\n * @version 01.01 {str(time.year)}{str(time.month)}{str(time.day)}\n *\n * @brief desc\n *\n * @ingroup {results[0]}\n * (Note: this needs exactly one @defgroup somewhere)\n *\n * @author Castellani Davide & Sabaini Chiara\n *\n *Contact: davidecastellani@castellanidavide.it, chiara@sabaini.com\n *\n */'
		elif(results[1] == "c"):
			init = f'/**\n * @file {results[0]}.{results[1]}\n *\n * @version 01.01 {str(time.year)}{str(time.month)}{str(time.day)}\n *\n * @brief desc\n *\n * @ingroup {results[0]}\n * (Note: this needs exactly one @defgroup somewhere)\n *\n * @author Castellani Davide & Sabaini Chiara\n *\n *Contact: davidecastellani@castellanidavide.it, chiara@sabaini.com\n *\n */'
			text = init + ""
		elif(results[1] == "cpp"):
			init = f'/**\n * @file {results[0]}.{results[1]}\n *\n * @version 01.01 {str(time.year)}{str(time.month)}{str(time.day)}\n *\n * @brief desc\n *\n * @ingroup {results[0]}\n * (Note: this needs exactly one @defgroup somewhere)\n *\n * @author Castellani Davide & Sabaini Chiara\n *\n *Contact: davidecastellani@castellanidavide.it, chiara@sabaini.com\n *\n */'
			text = init + f'\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nint main() {"{"}\n    return 0;\n{"}"}'
		elif(results[1] == "cs"):
			init = f'/**\n * @file {results[0]}.{results[1]}\n *\n * @version 01.01 {str(time.year)}{str(time.month)}{str(time.day)}\n *\n * @brief desc\n *\n * @ingroup {results[0]}\n * (Note: this needs exactly one @defgroup somewhere)\n *\n * @author Castellani Davide & Sabaini Chiara\n *\n *Contact: davidecastellani@castellanidavide.it, chiara@sabaini.com\n *\n */'
		elif(results[1] == "html"):
			text = f'<!DOCTYPE html>\n<!--\n@author: Castellani Davide & Sabaini Chiara 3CI a.s. 2019/2020\n@version: 01.01 {str(time.year)}-{str(time.month)}-{str(time.day)}\n-->\n<html>\n\n<head>\n\n\t<title>{results[0]}</title>\n\n\t<meta charset="utf-8">\n\n\t<meta name="viewport" content="width=device-width, initial-scale=1">\n\n\t<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css">\n\n\t<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>\n\n\t	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>\n\n\t<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js"></script>\n\n\t<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>\n\n</head>\n\n\n\n<body>\n\n\t<div class="container">\n\n\t</div>\n\n</body>\n\n</html>'
		elif(results[1] == "bat"):
			text = f"@ECHO OFF\nCLS\n\nREM\n{results[0]}\nREM Made by Castellani Davide & Sabaini Chiara 3CI a.s. 2019/2020\n"
		elif(results[1] == "ino"):
			text =f"// Author: Castellani Davide & Sabaini Chiara\n// Version: 01.01  {str(time.year)}-{str(time.month)}-{str(time.day)}\nvoid setup(){'{'}\n  Serial.begin(9600);\n{'}'}\nvoid loop(){'{'}\n\n{'}'}"
		else:
			text = f"# {results[0]}"

		if(results[4] == "N"):
			text = text.replace(" & Sabaini Chiara", "").replace(', "chiara@sabaini.com"', "")

		repo.create_file(f"bin/{results[0]}.{results[1]}", f"Created {results[0]}.{results[1]}", text)

	def create_README(repo, results):
		"""Creates the README.md
		"""
		time = datetime.now()

		init = f"# {results[0]}\n"
		tags = f"\n## Tags\n #tag1, #tag2\n"
		desc = f"\n## Description\n{results[2]}\n"
		req = f"\n## Required\n - \n"
		dir_structure = f"\n### Directories structure\n - bin\n\t - {results[0]}.{results[1]}\n - doc\n\t - README.md\n - log\n\t - trace.log\n"
		exe_examples = f"\n### Execution examples\n - {results[0]}.{results[1]}\n\t - \n"		
		changelog = f"\n## Changelog\n- [01.01_{str(time.year)}-{str(time.month)}-{str(time.day)}](#01.01_{str(time.year)}-{str(time.month)}-{str(time.day)})\n"
		version = f"\n### 01.01_{str(time.year)}-{str(time.month)}-{str(time.day)}\n - first version\n"
		finish = f"\nMade by Castellani Davide & Sabaini Chiara\nIf you have any problem please contact us:\n- davidecastellani@castellanidavide.it\n- chiara@sabaini.com"
		sep = f"\n---"
		text = init + tags + desc + req + sep + dir_structure + sep + exe_examples + sep + changelog + sep + version + sep + finish

		if(results[4] == "N"):
			text = text.replace(" & Sabaini Chiara", "").replace("\n- chiara@sabaini.com", "")
		
		repo.create_file("docs/README.md", f"Created README.md", text)

	def create_log(repo):
		"""Creates the trace.log
		"""
		repo.create_file("log/trace.log", f"Created trace.log", "")
		
	def download_repo(repo, folder_name):
		"""Downloads the repo into folder_name
		"""
		pygit2.clone_repository(repo.git_url, folder_name)

if __name__ == "__main__":
	try:
		create_structure_03_01()
	except:
		print("There is an error, try again.")
