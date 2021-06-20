# createstructure
[![GitHub license](https://img.shields.io/badge/license-GNU-green?style=flat)](https://github.com/createstructure/createstructure/blob/master/LICENSE) ![Author](https://img.shields.io/badge/author-Castellani%20Davide-green?style=flat)

![](https://github.com/CastellaniDavide/createstructure/raw/master/docs/createstructure.png)

 > Note
 > 
 > anything you can find in this repo can be viewed int the [wiki](https://github.com/createstructure/createstructure/wiki)

## Table of contents
![](https://static.thenounproject.com/png/121187-200.png)
- [createstructure](#createstructure)
  - [Table of contents](#table-of-contents)
  - [Description](#description)
  - [repo-structure](#repo-structure)
  - [Requirements](#requirements)
  - [How to create your own template](#how-to-create-your-own-template)
    - [1. Use template option](#1-use-template-option)
    - [2. Personalize it](#2-personalize-it)
    - [3. Try it](#3-try-it)

## Description
![](https://aimhigherafrica.com/wp-content/uploads/2018/09/o6.png)
This is the :octocat: bot :octocat: made w/ :love: by Castellani Davide.

With this program, you can easily create a repository on GitHub :octocat: with a basic template, personalized for your use.

## repo-structure
- [__createstructure__](https://github.com/createstructure/createstructure): the repo where to split the people in the specialized repo(s)
- __*-createstructure__: createstructure's funtionallity (eg. server management, apps, etc.)
    - [__manager-createstructure__](https://github.com/createstructure/manager-createstructure): the repo where there is everything you need for server management
    - [__core-createstructure__](https://github.com/createstructure/core-createstructure): the repo where there is the docker source to be run by the manager-createstructure
    - [__rest-createstructure__](https://github.com/createstructure/rest-createstructure): the repo cointaining the public part of the REST/ API 
- __*-template__: the templates that can be used by anyone (eg. default-template)
    - [__default-template__](https://github.com/createstructure/default-template): this template is the reference point for all the others

## Requirements
![](https://jeffnielsen.com/wp-content/uploads/2014/06/required-cropped.png)
  - [GitHub account](http://github.com/)
  - [Subscribed in createstructure](https://github.com/marketplace/createstructure)
  - [Network connection]


## How to create your own template
![](https://live.staticflickr.com/5213/5523800294_80f0687af7_b.jpg)

### 1. Use template option
![](https://cdn1.iconfinder.com/data/icons/accounting-and-taxes/48/easy_to_use_accessible_press_button_gesture_effortless-512.png)
  - Use createstructure to create the project that will become the new template

### 2. Personalize it
![](https://www.emotivebrand.com/wp-content/uploads/2016/03/Get-a-Leg-Up-With-Our-New-Web-Content-Personalization-eBook.png)
  - You can clone on your PC and choose what and how to change (it's not a problem if you want to change all the structure :smile:)
  - Take attention to che .castellanidavide\change.json file
    - The this file is a Json one, so => {..., "from": "to", ...}
    - Make attention to this special alias
      - sol<...>sol: see the complete list [here](https://github.com/createstructure/core-createstructure/blob/main/bin/libraries/createstructure_changes.hpp#L69-L101)
      - to do not change the a word repeate two times "sol": eg. solnamesol => solsolnamesolsol
      - (Do you have any idea for new alias? You can say me on the help email help@castellanidavide.it and I could add it to newer versions)
  - Remember to push your changes

### 3. Try it
![](https://assuredstudy.org/wp-content/uploads/2020/10/TRY.jpg)
  - Try to execute createstructure and check correct use of the template

---
Made by Castellani Davide 
If you have any problem or ask please contact me:
  - [Discussion](https://github.com/createstructure/createstructure/discussions)
  - [Issue](https://github.com/createstructure/createstructure/issues) 
  - [help@castellanidavide.it](mailto:help@castellanidavide.it)
