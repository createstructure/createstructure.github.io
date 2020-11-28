# create_structure
[![GitHub license](https://img.shields.io/badge/licence-GNU-green?style=flat)](https://github.com/CastellaniDavide/cpp-create_structure/blob/master/LICENSE) ![Author](https://img.shields.io/badge/author-Castellani%20Davide-green?style=flat) ![Version](https://img.shields.io/badge/version-v5.1-blue?style=flat) ![Language Python](https://img.shields.io/badge/language-Python-yellowgreen?style=flat) ![sys.platform supported](https://img.shields.io/badge/OS%20platform%20supported-Linux,%20Windows%20&%20Mac%20OS-blue?style=flat) [![On GitHub](https://img.shields.io/badge/on%20GitHub-True-green?style=flat&logo=github)](https://github.com/CastellaniDavide/create_structure)

## Description
This is the magic "robottino" by Castellani Davide
With this programm you can easly create a repository on GitHub with a basic template, personalized for your use.

## Required
 - python3
 - some pip pakeges, to install it go in requirements folder and execute: pip3 install -r requirements.txt
 - Internet connection
 - git
 - GitHub account
	- [GitHub Token](https://github.com/settings/tokens) with repo permission
 - Setup the settings (where it is TODO)

## Directories structure
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
   
## Execution examples
 - python3 create_structure.py

## How to create your own template
### 1. Open father template
 - [https://github.com/CastellaniDavide/default-template](https://github.com/CastellaniDavide/default-template)

### 2. Clone the templete into your GitHub account
 - Press "Use this template" bottom
 - Compile the form that you see, take attention to the owner and make sure the visibity to "Public"

### 3. Modify it
 - You can clone on your PC and choose what and how to change (it's not a problem if you want to change all the structure :smile:)
 - Take attention to che .castellanidavide\change.json file
   - You can see some change examples => ... "from": "to", ...
   - Make attention to this special alias
     - sol<question_tag>sol -> the result of your answer in the form you made at the beginning
     - time__now -> Datetime (format yyyy-mm-dd)
     - time_now -> Datetime (format yyyymmdd)
     - (Do you have any idea? You can say me on the help email help@castellanidavide.it and I could add it to newer versions)
 - Rememper to push your changes

### 4. Add your account into research
 - Add your Own name into SOUCES_OF_TEMPLATES, keep attention to the order (i sugge

### 5. Try it
 - Try to execute this programm and check correct use

# Changelog
 - [5.1_2020-11-28](#5.1_2020-11-28)
 - [5.0_2020-11-21](#5.0_2020-11-21)
 - [4.0_2020-9-25](#4.0_2020-9-25)	
 - [3.1_2020-8-18](#3.1_2020-8-18)	
 - [3.0_2020-8-15](#3.0_2020-8-15)								 
 - [2.0_2020-3-24](#2.0_2020-3-24)
 - [1.0_2020-3-24](#1.0_2020-3-24)

### 5.1_2020-11-28
   - Fixed a bug
   - Add team selection in runtime execution

### 5.0_2020-11-21
   - Fixed a bug
   - Made a better documentation
   - Optimized the question structure
   - Optimized the questions
   - Added some variables
     - Template sources list
     - Organization name (if you want to save into an Organization)
   - Removed some ununtil variables

### 4.0_2020-9-25
 #### Changes
   - Fixed a bug
   - Remove the necessity of insert credentials any time
   - Download in any case, before only if public repo
   - removed unused files

### 3.1_2020-8-18
 #### Changes
   - optimized the code
   - added requirements.txt 

### 3.0_2020-8-15
 #### Changes
   - add GitHub support with a lot of options (eg. repo private or public)
   
### 2.0_2020-3-24
 #### Changes
   - adjusted some bugs
   - improved the program

### 1.0_2020-3-24
 - Initial version

---
Made by Castellani Davide 
If you have any problem please contact us:
- help@castellanidavide.it
- [Issue](https://github.com/CastellaniDavide/create_structure/issues)