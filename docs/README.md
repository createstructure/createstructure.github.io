# create_structure
[![GitHub license](https://img.shields.io/badge/license-GNU-green?style=flat)](https://github.com/CastellaniDavide/cpp-create_structure/blob/master/LICENSE) ![Author](https://img.shields.io/badge/author-Castellani%20Davide-green?style=flat) ![Version](https://img.shields.io/badge/version-v5.4-blue?style=flat) ![Language Python](https://img.shields.io/badge/language-Python-yellowgreen?style=flat) ![sys.platform supported](https://img.shields.io/badge/OS%20platform%20supported-Linux,%20Windows%20&%20Mac%20OS-blue?style=flat) [![On GitHub](https://img.shields.io/badge/on%20GitHub-True-green?style=flat&logo=github)](https://github.com/CastellaniDavide/create_structure) ![Check installation](https://github.com/CastellaniDavide/create_structure/workflows/Check%20installation/badge.svg)

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
With this programm you can easly create a repository on GitHub :octocat: with a basic template, personalized for your use.

### Required
 - Internet connection
 - GitHub account
	- [GitHub Token](https://github.com/settings/tokens) with repo and organization permission

### Setup/ Update
#### Attention: replace <SOME_WORDS> with your values
 - Debian/Ubuntu: ```sudo apt install git python3 python3-pip; cd ~; git clone https://github.com/CastellaniDavide/create_structure.git; cd create_structure; git pull --force; pip3 install -r requirements/requirements.txt; alias create_structure="python3 ~/create_structure/bin/create_structure.py -t=<TOCKEN> -s=<(optional)_ARRAY_OF_TEMPLATE_SOURCES> -o=<(optional)_ORGANIZATION> -i=<(optional)_FOLDERS_TO_BE_IGNORED_FROM_TEMPLATE>"```
 - Windows (on PowerShell as Adminastrator): ```Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1')); choco install git.install -y; choco install python3 --pre -y; cd "C:\Program Files";  git clone https://github.com/CastellaniDavide/create_structure.git; cd create_structure; git pull --force; pip3 install -r requirements/requirements.txt;New-Item -Path $Profile -Type File -Force; echo "Function CreateStructureFunction {python 'C:\Program Files/create_structure/bin/create_structure.py' -t=<TOCKEN> -s='<(optional)_ARRAY_OF_TEMPLATE_SOURCES>' -o=<(optional)_ORGANIZATION> -i='<(optional)_FOLDERS_TO_BE_IGNORED_FROM_TEMPLATE>'}" > $Profile; echo "Set-Alias -Name create_structure -Value CreateStructureFunction" >> $Profile```
  - open another powershell window on you PC and start to use code
 - Others:
    - [install git](https://git-scm.com/download)
    - download the repo ```git clone https://github.com/CastellaniDavide/create_structure.git```
    - [install python3](https://www.python.org/)
    - [install pip3](https://www.python.org/)
    - install requirements.txt (in core of the project): ```pip3 install -r requirements/requirements.txt```
    - create an alias
      - name: create_structure
      - attribute: python3 <ABSOLUTE_PATH_OF_REPO>/bin/create_structure.py -t=<TOCKEN> -s=<ARRAY_OF_SOURCES> -o=<(optional)_ORGANIZATION> -i=<(optional)_FOLDERS_TO_BE_IGNORED_FROM_TEMPLATE>

### Directories structure
 - .github
   - ISSUE_TEMPLATE
     - bug_report.md
     - feature-request.md
 - bin
   - create_structure.py
 - doc
   - LICENSE
   - README.md
 - requirements
   - requirements.txt
   
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
 - [5.4_2020-12-12](#54_2020-12-12)
 - [5.3_2020-11-29](#53_2020-11-29)
 - [5.2_2020-11-28](#52_2020-11-28)
 - [5.1_2020-11-28](#51_2020-11-28)
 - [5.0_2020-11-21](#50_2020-11-21)
 - [4.0_2020-9-25](#40_2020-9-25)	
 - [3.1_2020-8-18](#31_2020-8-18)	
 - [3.0_2020-8-15](#30_2020-8-15)								 
 - [2.0_2020-3-24](#20_2020-3-24)
 - [1.0_2020-3-24](#10_2020-3-24)

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

#### 4.0_2020-9-25
 ##### Changes
  - Fixed a bug
  - Remove the necessity of insert credentials any time
  - Download in any case, before only if public repo
  - removed unused files

#### 3.1_2020-8-18
 ##### Changes
  - optimized the code
  - added requirements.txt 

#### 3.0_2020-8-15
 ##### Changes
  - add GitHub support with a lot of options (eg. repo private or public)
   
#### 2.0_2020-3-24
 ##### Changes
  - adjusted some bugs
  - improved the program

#### 1.0_2020-3-24
  - Initial version

---
Made by Castellani Davide 
If you have any problem please contact us:
- help@castellanidavide.it
- [Discussion](https://github.com/CastellaniDavide/create_structure/discussions)
- [Issue](https://github.com/CastellaniDavide/create_structure/issues) 
