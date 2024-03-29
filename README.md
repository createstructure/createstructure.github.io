# createstructure

## Table of Contents
- [createstructure](#createstructure)
  - [Table of contents](#table-of-contents)
  - [Description](#description)
  - [subscription to the service](#subscription-of-the-service)
  - [How to use](#how-to-use)
  - [How to create your own template](#how-to-create-your-own-template)
  - [How to contribute](#how-to-contribute)
  - [Privacy Policy](#privacy-policy)
  - [Repos structure](#repos-structure)
    - [app-createstructure](#app-createstructure)
    - [debian-createstructure](#debian-createstructure)
    - [rest-createstructure](#rest-createstructure)
    - [createstructure.github.io](#createstructure.github.io)
    - [manager-createstructure](#manager-createstructure)
    - [core-createstructure](#core-createstructure)
    - [librerias-createstructure](#librerias-createstructure)
    - [default-template](#default-template)

##  Description 
![BMC createstructure](https://raw.githubusercontent.com/createstructure/createstructure.github.io/main/img/createstructure.github.io-BMC.svg)



## Subscription to the service

### How to subscribe to the service
- Go to the [subscription page](https://github.com/marketplace/createstructure)
- Go to the end of the page
- From the left menu, select the plan you want to subscribe to
- Press the "Subscribe" button, the text can be different depending on the plan
- If the plan it's not free, you will be asked to enter your credit card details
- Press the "Complete" button, the text can be different depending on the plan
- Now you can use the service

### How to change the subscription
- Go to the [subscription page](https://github.com/marketplace/createstructure)
- Press the "Edit your plan" button and select your username
- In the plan box select the plan you want to subscribe to
- If the plan it's not free, you will be asked to enter your credit card details
- Press the "Complete" button, the text can be different depending on the plan
- Now you can use the service with the new plan

### How to unsubscribe from the service
- Go to the [subscription page](https://github.com/marketplace/createstructure)
- Press the "Edit your plan" button and select your username
- In the plan box select press the "Cancel this plan" link
- In the alert box, press the "OK" button
- Now you are unsubscribed from the service

## How to use

> To use the createstructure service, you need to be [subscribed to the createstructure service](./subscription-to-the-service.md).

### Mobile app
Use the mobile app is the easiest way to use the createstructure service.
At the moment it's disponible for Android (>= 8).

The steps to install the app are:
- [Download the app](https://play.google.com/store/apps/details?id=it.castellanidavide.createstructure.createstructure)
- Follow the tutorial on the app

The steps to upgrade the app are:
- [Go to Playstore](https://play.google.com/store/apps/details?id=it.castellanidavide.createstructure.createstructure)
- Update the app

The steps to uninstall the app are:
- [Go to Playstore](https://play.google.com/store/apps/details?id=it.castellanidavide.createstructure.createstructure)
- Uninstall the app

### Ubuntu/ Debian app
The Ubuntu/ Debian app is a tool to use the createstructure service on the command line.

The steps to install the app are:
- Ubuntu

```    
sudo add-apt-repository ppa:castellanidavide/createstructure
sudo apt-get update
sudo apt-get install createstructure
```

- Debian
  - Download the last .deb file from the [Release page](https://github.com/createstructure/debian-createstructure/releases)
  - `sudo apt-get install <filename>.deb`

The steps to update the app are:
- Ubuntu
  - `sudo apt-get update`
  - `sudo apt-get upgrade`
- Debian
  - Download the last .deb file from the [Release page](https://github.com/createstructure/debian-createstructure/releases)
  - `sudo apt-get install <filename>.deb`

The steps to uninstall the app are:
- `sudo apt-get remove createstructure`

### REST API
The REST API is a web service that allows you to use the createstructure service. It didn't need to be installed on the computer to use the service.

The steps to use it are:
- Create a [GitHub token](https://github.com/settings/tokens/new) with the scope `repo`, `workflow`, `org:admin` and `user`
- Follow the [REST API documentation](https://github.com/createstructure/rest-createstructure/wiki/REST-Actions)

## How to create your own template

With createstructure service you can also use your own template.

A personal template to be usable needs:
- to be private
- to end with `-template`

How to create your own template:
- Create a private repository with the name endind with `-template` (for this step you can use the createstructure service)
- Costumize the repo with your own content
- Create a `.createstructure/change.json` like this:

```
{
  "This is the default template.": "soldescrsol",
  "createstructure/default-template": "solnamesol",
  "default-template": "solnamesol",
  "default": "solnamesol",
  "key": "value"
}
```
There are some special keys whict starts and ends with `sol`, the list is [this](https://github.com/createstructure/core-createstructure/blob/main/bin/local-libraries/repo.hpp#L375-L407)

- Push the repository
- Try the created template

## How to contribute

### Use the service
The fist way to contribute is to use the service.
If you discover any problem, please report it to the Issues or in the Discussions pages.

If you like this project you can also tell others about it, so the community can grow :smile:.

### Contributing to the code
One way to contribute to help us improve the code.
In every repository, there are the instructions to rebuild the code by your own.

So the steps to contribute to the code are:
- [ ] (Put the star on the repository :star:)
- [ ] Fork the repository
- [ ] Clone the repository
- [ ] Follow the instructions to rebuild the code
- [ ] Make your changes
- [ ] Test them
- [ ] Create a pull request in which you explain the changes you made
  - [ ] Why did you make the changes/ What was the problem?
  - [ ] How did you solve the problem?
  - [ ] Any other information you want to share

## Privacy policy
Press the image below to see the privacy policy.
[![Privacy policy](https://media.istockphoto.com/vectors/privacy-policy-beauteous-vector-halftone-isometric-illustration-vector-id1145198292?k=20&m=1145198292&s=612x612&w=0&h=rBMrJ-rDliLqSnkQHkUXg2j2Z4MIBH9CsaijSwZ5FxU=)](./Privacy-Policy.md)

## Repos structure

### app-createstructure
Mobile app to use createstructure service
![createstructure/app-createstructure](https://opengraph.githubassets.com/cd4b1adef0fc08f45b5cce4cb1ffbbda58a554763de0cb9812ba85faf0823d5e/createstructure/app-createstructure)

### debian-createstructure
Debian client app
![createstructure/debian-createstructure](https://opengraph.githubassets.com/634d64ce9dfd157de1c6e92e1a82de53df01e6e29e960bf700ed6dd8c68c153e/createstructure/debian-createstructure)

### rest-createstructure
This repository contains the REST API created for the createstructure service.

To get more info about how it works and how can you can contribute, please go to the [wiki](https://github.com/createstructure/rest-createstructure/wiki).
![createstructure/rest-createstructure](https://opengraph.githubassets.com/2dca08a12f82905c32a6cc1f6e5870e24eb6edd6d5d3b4f2e2796c769689d9b4/createstructure/rest-createstructure)

### createstructure.github.io
This repo is made to make it easier to contain all the documentation of the createstructure project.
![createstructure.github.io](https://opengraph.githubassets.com/0c4381254fd5d35c59220c0600186566eddbe21ce8e0bd23199a4519078f33db/createstructure/createstructure.github.io)
### manager-createstructure
Repo for managing the creation of the repos
![createstructure/manager-createstructure](https://opengraph.githubassets.com/9ee759ce22abcdf96e8e25dc294bc96221a11239c38a58625a518e680a707ece/createstructure/manager-createstructure)

### core-createstructure
Repo where there's the source to create the repo(s)
![createstructure/core-createstructure](https://opengraph.githubassets.com/9b2fad5928b5deecd16dc94ce790de61ed86ce0ae1d52fa66f2e2b6c10d90fd8/createstructure/core-createstructure)

### librerias-createstructure
Repo containing the library used by core-createstructure  manager-createstructure
![createstructure/libraries-createstructure](https://opengraph.githubassets.com/626e3b763debefc0fcbda458a379f3cc00c23e7debc2fc61a135bb00872358ec/createstructure/libraries-createstructure)

### default-template
This is the default template
![createstructure/default-template](https://opengraph.githubassets.com/cf4891d1ca34cb9699f58b62ad889f1b369fad174bbb7dc2b3abfa7b482580a6/createstructure/default-template)

---
Made with ❤️ by @DavideC03

If you have any questions, please contact my community and me:

- [Discussion](https://github.com/createstructure/createstructure/discussions/new)
- [Issues](https://github.com/createstructure/createstructure/issues/new)
- [Mail](mailto:help@castellanidavide.it)
