# createstructure

## Table of Contents
- [createstructure](#createstructure)
  - [Table of contents](#table-of-contents)
  - [General description](#general-description)
  - [Repo description](#repo-description)
  - [subscription to the service](#subscription-of-the-service)
  - [How to use](#how-to-use)
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

## General description
createstructure is a service to make it easier and faster the setup for any IT project.

## Repo description
This repo is it made to make easier to contain all the documentation of the createstructure project.

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
## How to use the createstructure service

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
- Create a [GitHub token](https://github.com/settings/tokens/new) with the scope `repo`, `org:admin` and `user`
- Follow the [REST API documentation](https://github.com/createstructure/rest-createstructure/wiki/REST-Actions)
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
![createstructure/app-createstructure](https://opengraph.githubassets.com/f4c4090ca30cdd10d02102d88530d7a55fd08410fe735d047eabb85c082c86df/createstructure/app-createstructure)

### debian-createstructure
Debian client app
![createstructure/debian-createstructure](https://opengraph.githubassets.com/ffec71b52f5a8aad89c032753b480a607568cc335e0d8769b84c26c05163c2ad/createstructure/debian-createstructure)

### rest-createstructure
This repository contains the REST API created for the createstructure service.

To get more info about how it works and how can you can contribute, please go to the [wiki](https://github.com/createstructure/rest-createstructure/wiki).
![createstructure/rest-createstructure](https://opengraph.githubassets.com/cad05156c359e8665206bdb005420539bb843cba414c759a62ce06acf3376749/createstructure/rest-createstructure)

### createstructure.github.io
This repo is it made to make easier to contain all the documentation of the createstructure project.
![createstructure/createstructure.github.io](https://opengraph.githubassets.com/2909ff28f99e65bb9093289fd82b9576a94f919fab0fcc1a904ea500b68b9e68/createstructure/createstructure.github.io)

### manager-createstructure
Repo for managing the creation of the repos
![createstructure/manager-createstructure](https://opengraph.githubassets.com/5b8f42991e48d1ad0f54a18e131b5af3a7bebd750d1924e17639d072d69b7fc5/createstructure/manager-createstructure)

### core-createstructure
Repo where there's the source to create the repo(s)
![createstructure/core-createstructure](https://opengraph.githubassets.com/e99289000e1828d3876752cd2ab7c13d1a5a87d45d8e788629ab13b0c6e1616e/createstructure/core-createstructure)

### librerias-createstructure
Repo containing the library used by core-createstructure  manager-createstructure
![createstructure/libraries-createstructure](https://opengraph.githubassets.com/72364e818bfdd65899ba491f253da3377f2e9cf314ae5c443bb79478a0cb5e75/createstructure/libraries-createstructure)

### default-template
Welcome to the default-template wiki!

---
Made with ❤️ by @DavideC03

If you have any questions, please contact my community and me:

- [Discussion](https://github.com/createstructure/createstructure/discussions/new)
- [Issues](https://github.com/createstructure/createstructure/issues/new)
- [Mail](mailto:help@castellanidavide.it)
