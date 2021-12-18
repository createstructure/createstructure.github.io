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
- Create a [GitHub token](https://github.com/settings/tokens/new) with the scope `repo`, `workflow`, `org:admin` and `user`
- Follow the [REST API documentation](https://github.com/createstructure/rest-createstructure/wiki/REST-Actions)

