# createstructure
[![GitHub license](https://img.shields.io/badge/license-GNU-green?style=flat)](https://github.com/createstructure/createstructure/blob/master/LICENSE) ![Author](https://img.shields.io/badge/author-Castellani%20Davide-green?style=flat) ![Version](https://img.shields.io/badge/version-v7.8-blue?style=flat) ![Language Python](https://img.shields.io/badge/language-Python-yellowgreen?style=flat) ![sys.platform supported](https://img.shields.io/badge/OS%20platform%20supported-Linux,%20Windows%20&%20Mac%20OS-blue?style=flat) [![On GitHub](https://img.shields.io/badge/on%20GitHub-True-green?style=flat&logo=github)](https://github.com/createstructure/createstructure) ![PyPI](https://img.shields.io/pypi/v/createstructure)

![](https://github.com/CastellaniDavide/createstructure/raw/master/docs/createstructure.png)

## Contents
![](https://static.thenounproject.com/png/121187-200.png)
  - [Description](#description)
  - [Required](#required)
  - [Installation](#installation)
  - [Update](#update)
  - [Delate](#delate)
  - [How to use](#how%20to%20use)
  - [How to create your own template](#how%20to%20create%20your%20own%20template)
    - [1. Install createstructure](#1.%20install%20createstructure)
    - [2. Use template option](#2.%20use%20template%20option)
    - [3. Personalize it](#3.%20personalize%20it)
    - [4. Add your account into research](#4.%20add%20your%20account%20into%20research)
    - [5. Try it](#5.%20try%20it)
  - [Directories structure](#directories%20structure)
  - [Changelog](#changelog)

### Description
![](http://aimhigherafrica.com/wp-content/uploads/2018/09/o6.png)
This is the magic :octocat: bot :octocat: by Castellani Davide
With this program, you can easily create a repository on GitHub :octocat: with a basic template, personalized for your use.

### Required
![](http://jeffnielsen.com/wp-content/uploads/2014/06/required-cropped.png)
  - Windows/ Ubuntu OS
  - Internet connection
  - [GitHub](http://github.com/) account

### Installation
![](https://dctacademy.com/wp-content/uploads/2016/12/install.jpeg)
  - Debian/ Ubuntu using apt:
    - ```sudo add-apt-repository ppa:castellanidavide/createstructure; sudo apt update; sudo apt install createstructure```
  - Linux using snap:
    - ```snap install createstructure; echo "alias createstructure='/snap/createstructure/current/bin/createstructure'" > ~/.bashrc```
    - Refresh terminal
  - Windows (using choco):
    - ```choco install createstructure=7.0```
    - ```createstrucure.exe -l``` <- for the login
  - Manual by source:
    - [install git](https://git-scm.com/download)
    - download the repo ```git clone https://github.com/createstructure/createstructure.git```
    - [install python3](https://www.python.org/)
    - [install pip3](https://www.python.org/)
    - install requirements.txt (in the core of the project): ```pip3 install -r requirements/requirements.txt```
    - create an alias
      - name: createstructure
      - attribute: python3 \<ABSOLUTE_PATH_OF_REPO>/bin/createstructure.py -t=\<TOCKEN> -s=\<ARRAY_OF_SOURCES> -o=\<(optional)_ORGANIZATION> -i=\<(optional)_FOLDERS_TO_BE_IGNORED_FROM_TEMPLATE>

  **Attention: replace <SOME_WORDS> with your values**

### Update
![](https://images.idgesg.net/images/article/2020/07/software_update_by_gocmen_gettyimages-1146311500_2400x1600-100852481-large.jpg)
  - Debian/ Ubuntu using apt:
    - ```sudo apt update; sudo apt upgrade```
  - Linux using snap:
    - ```snap refresh createstructure```
  - Windows (using choco):
    - ```choco upgrade createstructure --version=7.0```
  - Manual by source:
    - In the repo core ```git pull```
    - ```pip3 install --update createstructure```

  **Attention: replace <SOME_WORDS> with your values**

### Delate
![](http://cdn.onlinewebfonts.com/svg/img_105952.png)
  - Debian/ Ubuntu using apt:
    - ```sudo apt remove createstructure```
  - Linux using snap:
    - ```snap remove createstructure```
    - delate ```alias createstructure='/snap/createstructure/current/bin/createstructure'``` in the ~/.bashrc file
  - Windows (using choco):
    - ```choco remove createstructure```
  - Manual by source:
    - Remove the repository on your PC
    - Remove alias
    - ```pip3 uninstall createstructure```

  **Attention: replace <SOME_WORDS> with your values**

### How to use
![](https://www.animationvideo.co/wp-content/uploads/2017/12/How-to-video.jpg)

  - **First time**
    - ```createstructure -l```
    - Follow the passages
  - ```createstructure```
    - Follow the passages

### How to create your own template
![](https://live.staticflickr.com/5213/5523800294_80f0687af7_b.jpg)
#### 1. Install createstructure
![](https://dctacademy.com/wp-content/uploads/2016/12/install.jpeg)
  - [Go to install instructions](#installation)

#### 2. Use template option
![](https://cdn1.iconfinder.com/data/icons/accounting-and-taxes/48/easy_to_use_accessible_press_button_gesture_effortless-512.png)
  - ```createstructure -t```

#### 3. Personalize it
![](https://www.emotivebrand.com/wp-content/uploads/2016/03/Get-a-Leg-Up-With-Our-New-Web-Content-Personalization-eBook.png)
  - You can clone on your PC and choose what and how to change (it's not a problem if you want to change all the structure :smile:)
  - Take attention to che .castellanidavide\change.json file
    - You can see some change examples => ... "from": "to", ...
    - Make attention to this special alias
      - sol<question_tag>sol -> the result of your answer in the form you made at the beginning
      - time__now -> Datetime (format yyyy-mm-dd)
      - time_now -> Datetime (format yyyymmdd)
      - (Do you have any idea? You can say me on the help email help@castellanidavide.it and I could add it to newer versions)
  - Remember to push your changes

#### 4. Add your account into research
![](https://cdn.pixabay.com/photo/2012/04/02/16/07/plus-24844_1280.png)
  - Add your name into the sources, if not I suggest you to do the login again

#### 5. Try it
![](http://assuredstudy.org/wp-content/uploads/2020/10/TRY.jpg)
  - Try to execute this programm and check correct use

### Directories structure
![](https://cdn.analyticsvidhya.com/wp-content/uploads/2019/05/data-science-framework.png)
  - .github
    - ISSUE_TEMPLATE
      - bug_report.md
      - feature_request.md
    - workflows
      - on-push.yml
      - on-release.yml
  - choco
    - tools
      - chocolateybeforemodify.ps1
      - chocolateyinstall.ps1
      - chocolateyuninstall.ps1
      - createstructure.c
      - createstructure.exe
      - createstructure-setup.c
      - createstructure-setup.exe
      - LICENSE.txt
      - VERIFICATION.txt
    - createstructure.nuspec
    - ReadMe.md
    - set.txt
  - createstructure
    - __init __.py
  - debian
    - createstructure
    - createstructure.1
    - createstructure.c
    - debian
      - changelog
      - compat
      - control
      - copyright
      - createstructure.debhelper.log
      - createstructure.dirs
      - postinst
      - postrm
      - preinst
      - rules
      - source
        - format
    - Makefile
    - requirements.in
  - docs
    - _config.yml
    - LICENSE
    - README.md
  - requirements
    - requirements.txt
  - snap
    - snapcraft.yaml
  - snap-bin
    - CMakeLists.txt
    - createstructure.c
  - setup.py
  - .gitignore

### Changelog
![](https://www.ashoka.org/sites/default/files/styles/medium_1600x1000/public/old_way_new_way.jpg?itok=3JnbJz4O)
  - [7.8_2021-03-14](#78_2021-03-14)
  - [7.7_2021-03-14](#77_2021-03-14)
  - [7.6_2021-03-13](#76_2021-03-13)
  - [7.5_2021-03-07](#75_2021-03-07)
  - [7.4_2021-03-07](#74_2021-03-07)
  - [7.3_2021-03-07](#73_2021-03-07)
  - [7.2_2021-03-04](#72_2021-03-04)
  - [7.1_2021-02-13](#71_2021-02-13)
  - [7.0_2021-01-11](#70_2021-01-11)
  - [6.2_2021-01-04](#62_2021-01-04)
  - [6.1_2021-01-03](#61_2021-01-03)
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

#### 7.8_2021-03-13
  - Fixed a bug

#### 7.7_2021-03-13
  - Added snap package
  - Optimized README.md
  - Optimized wiki

#### 7.6_2021-03-13
  - Optimized launcher (createstructure.c)

#### 7.5_2021-03-07
  - Fixed a bug
  - Added the avariability for not-texual files

#### 7.4_2021-03-07
  - Fixed a minor bug

#### 7.3_2021-03-07
  - Fixed few bugs

#### 7.2_2021-03-04
  - Optimized the change method
  - Added the auto-generate token option
  - Unified the createstructure.c files for
    - Debian/ Ubuntu
    - Windows
  - Optimized README.md
  - Created [wiki](https://github.com/createstructure/createstructure/wiki)
  - Automate Ubuntu package push to launchpad server
  - Optimized choco package
  - Uniformed all to use private templates or the once on createstructure organization
  - create_structure => createstructure

#### 7.1_2021-02-13
  - Change internal team variable (team pointer => team name)
  - Adjust emoji
  - Add a parameter to create a template eg. -temp --template
  - Optimized multithreading on push

#### 7.0_2021-01-11
  - Added Debian package
  - Added Choco package
  - Automate Choco package publishing

#### 6.2_2021-01-04
  - Added emoji :smile: to the output

#### 6.1_2021-01-03
  - Fixed a bug
  - Adjusted variable names
  - Added a method to understand when an answer is positive, this for a more centralized control
  - Added developer/ verbose setting
  - Update .gitignore
  - Added the possibility to add automatically the answers
  - Optimized README.md
  - Now the workflows file are loaded at the end
  - Update workflows

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
  - start to use multitreading (41 sec. -> 10 sec.) (I made this test using [this template](https://github.com/createstructure/py-template))
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
  - [Discussion](https://github.com/createstructure/createstructure/discussions)
  - [Issue](https://github.com/createstructure/createstructure/issues) 
