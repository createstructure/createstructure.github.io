# create_structure
[![GitHub license](https://img.shields.io/badge/license-GNU-green?style=flat)](https://github.com/CastellaniDavide/cpp-create_structure/blob/master/LICENSE) ![Author](https://img.shields.io/badge/author-Castellani%20Davide-green?style=flat) ![Version](https://img.shields.io/badge/version-v6.1-blue?style=flat) ![Language Python](https://img.shields.io/badge/language-Python-yellowgreen?style=flat) ![sys.platform supported](https://img.shields.io/badge/OS%20platform%20supported-Linux,%20Windows%20&%20Mac%20OS-blue?style=flat) [![On GitHub](https://img.shields.io/badge/on%20GitHub-True-green?style=flat&logo=github)](https://github.com/CastellaniDavide/create_structure) ![PyPI](https://img.shields.io/pypi/v/createstructure)

## Contents
 - [Description](#description)
 - [Required](#required)
 - [Setup/ Update](#setup/%20update)
 - [Directories structure](#directories%20structure)
 - [Execution examples](#execution%20examples)
 - [How to create your own template](#how%20to%20create%20your%20own%20template)
 - [Changelog](#changelog)

### Description
This is the magic :octocat: bot :octocat: by Castellani Davide
With this programm you can easily create a repository on GitHub :octocat: with a basic template, personalized for your use.

### Required
 - required python3 (>=3.8)
 - pip3
 - Internet connection
 - GitHub account
	- [GitHub Token](https://github.com/settings/tokens) with repo and organization permission

### Setup
#### Attention: replace <SOME_WORDS> with your values
 - All OS using pypi:
    - ```pip install createstructure```
    - Made an alias of use
      - Value of the alias: 
      ```python3 -c "exec(\"from create_structure import create_structure;create_structure()\")" -t=<TOCKEN> -s=<(optional)_ARRAY_OF_TEMPLATE_SOURCES> -o=<(optional)_ORGANIZATION> -i=<(optional)_FOLDERS_AND_FILES_TO_BE_IGNORED_BY_TEMPLATE>```
      - Eg. ubuntu/debian (after this reload the terminal): 
      ```echo alias createstructure='python3 -c "exec(\"from create_structure import create_structure;create_structure()\")" -t=<TOCKEN> -s=<(optional)_ARRAY_OF_TEMPLATE_SOURCES> -o=<(optional)_ORGANIZATION> -i=<(optional)_FOLDERS_AND_FILES_TO_BE_IGNORED_BY_TEMPLATE>' >> ~/.bash_aliases```
      - Example of use: ```echo "alias createstructure='python3 -c \"exec(\\\"from create_structure import create_structure;create_structure()\\\")\" -t=abcb1234 -s=[CastellaniDavide] -o=CastellaniDavideTest -i=[.vs,.vscode]'" >> ~/.bash_aliases```
 - Manual by source:
    - [install git](https://git-scm.com/download)
    - download the repo ```git clone https://github.com/CastellaniDavide/create_structure.git```
    - [install python3](https://www.python.org/)
    - [install pip3](https://www.python.org/)
    - install requirements.txt (in core of the project): ```pip3 install -r requirements/requirements.txt```
    - create an alias
      - name: create_structure
      - attribute: python3 <ABSOLUTE_PATH_OF_REPO>/bin/create_structure.py -t=<TOCKEN> -s=<ARRAY_OF_SOURCES> -o=<(optional)_ORGANIZATION> -i=<(optional)_FOLDERS_TO_BE_IGNORED_FROM_TEMPLATE>

### Update
 - With pypi method: ```pip3 install [package_name] --upgrade```

### Directories structure
 - .github
   - ISSUE_TEMPLATE
     - *.md
   - workflows
     - *.yml
 - create_structure
   - __init __.py
 - doc
   - _config.yml
   - LICENSE
   - README.md
 - requirements
   - requirements.txt
 - setup.py
 - .gitignore
   
### Execution examples
 - create_structure

### How to create your own template
#### 1. Open father template
 - [https://github.com/CastellaniDavide/default-template](https://github.com/CastellaniDavide/default-template)

#### 2. Clone the templete into your GitHub account
 - Press "Use this template" bottom
 - Compile the form that you see, take attention to the owner and make sure the visibity to "Public"

#### 3. Modify it
 - You can clone on your PC and choose what and how to change (it's not a problem if you want to change all the structure :smile:)
 - Take attention to che .castellanidavide\change.json file
   - You can see some change examples => ... "from": "to", ...
   - Make attention to this special alias
     - sol<question_tag>sol -> the result of your answer in the form you made at the beginning
     - time__now -> Datetime (format yyyy-mm-dd)
     - time_now -> Datetime (format yyyymmdd)
     - (Do you have any idea? You can say me on the help email help@castellanidavide.it and I could add it to newer versions)
 - Rememper to push your changes

#### 4. Add your account into research
 - Add your Own name into SOUCES_OF_TEMPLATES, keep attention to the order (i sugge

#### 5. Try it
 - Try to execute this programm and check correct use

### Changelog
 - [6.1_2021-01-03](#60_2021-01-03)
 - [6.0_2020-12-16](#60_2020-12-16)
 - [5.5_2020-12-13](#55_2020-12-13)
 - [5.4_2020-12-12](#54_2020-12-12)
 - [5.3_2020-11-29](#53_2020-11-29)
 - [5.2_2020-11-28](#52_2020-11-28)
 - [5.1_2020-11-28](#51_2020-11-28)
 - [5.0_2020-11-21](#50_2020-11-21)
 - [4.0_2020-09-25](#40_2020-09-25)	
 - [3.1_2020-08-18](#31_2020-08-18)	
 - [3.0_2020-08-15](#30_2020-08-15)								 
 - [2.0_2020-03-24](#20_2020-03-24)
 - [1.0_2020-03-24](#10_2020-03-24)

#### 6.1_2021-01-03
  - Fixed a bug
  - Adjusted variable names
  - Added a method to understand when an answer is positive, this for a more centralized control
  - Added developer/ verbose setting
  - Update .gitignore
  - Added the possibility to add automatically the answers
  - Optimized README.md
  - Now the workflows file are loaded at the end

#### 5.5_2020-12-13
  - Add first version of GitHub Actions

#### 5.4_2020-12-12
  - Fixed some bugs
  - Changed the README.md
  - Create a setup method <= easier to use
  - Changed the way to give the tocken, ... => now by CLI 

#### 5.3_2020-11-29
  - removed some untils lines
  - accelerated the code
  - parametrized the folder to be ignored
  - start to use multitreading (41 sec. -> 10 sec.) (I made this test using [this template](https://github.com/CastellaniDavide/py-template))
  - optimized imports
  - optimised variables

#### 5.2_2020-11-28
  - Added the website documentation
  - Fixed a bug

#### 5.1_2020-11-28
  - Fixed a bug
  - Add team selection in runtime execution

#### 5.0_2020-11-21
  - Fixed a bug
  - Made a better documentation
  - Optimized the question structure
  - Optimized the questions
  - Added some variables
    - Template sources list
    - Organization name (if you want to save into an Organization)
  - Removed some ununtil variables

#### 4.0_2020-09-25
 ##### Changes
  - Fixed a bug
  - Remove the necessity of insert credentials any time
  - Download in any case, before only if public repo
  - removed unused files

#### 3.1_2020-08-18
 ##### Changes
  - optimized the code
  - added requirements.txt 

#### 3.0_2020-08-15
 ##### Changes
  - add GitHub support with a lot of options (eg. repo private or public)
   
#### 2.0_2020-03-24
 ##### Changes
  - adjusted some bugs
  - improved the program

#### 1.0_2020-03-24
  - Initial version

---
Made by Castellani Davide 
If you have any problem or ask please contact me:
- [help@castellanidavide.it](mailto:help@castellanidavide.it)
- [Discussion](https://github.com/CastellaniDavide/create_structure/discussions)
- [Issue](https://github.com/CastellaniDavide/create_structure/issues) 
