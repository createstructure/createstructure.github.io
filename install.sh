#!/bin/bash
echo -e "\xE2\x9C\x94 "


# Starting createstructure installer
echo -e "\xE2\x9C\x94 Starting createstructure installer"


# Make to have the correcth rights
if [[ $UID != 0 ]]; then
    echo "Please run this script with sudo:"
    echo "sudo $0 $* ..."
    exit 1
fi

echo -e "\xE2\x9C\x94 Script runned as administrator"


# Check and get passedarguments
if [ "$#" -ne 2 ]; then
    echo "Illegal number of parameters"
    echo "install.sh {SERVER_ID} {SERVER_CODE}"
    echo "Replacing {...} with correct vaules"
    exit 1
fi

SERVER_ID=$1
SERVER_CODE=$2

echo -e "\xE2\x9C\x94 Getted arguments"


# Update & Upgrade
apt update > /dev/null
apt full-upgrade > /dev/null

echo -e "\xE2\x9C\x94 Updated & Upgraded"


# Install Docker
apt install docker.io -y > /dev/null

echo -e "\xE2\x9C\x94 Installed Docker"


# Install git
apt install git -y > /dev/null

echo -e "\xE2\x9C\x94 Installed git"


# Change current position to /bin
cd /bin

echo -e "\xE2\x9C\x94 Changed directory to /bin"


# Clone project
#git clone https://github.com/createstructure/createstructure
git clone --single-branch --branch v9 https://github.com/createstructure/createstructure > /dev/null
cd createstructure

echo -e "\xE2\x9C\x94 Cloned the project"


# Create settings
echo "{\"server_id\": \"$SERVER_ID\", \"server_code\": \"$SERVER_CODE\"}" > ./core/server.settings

echo -e "\xE2\x9C\x94 Created settings"



# Create key pair
cd ./core

# Create
openssl genrsa -out private.pem 2048 > /dev/null
openssl rsa -in private.pem -outform PEM -pubout -out public.pem > /dev/null

# Make keys visible
sudo chmod a+rwx private.pem
sudo chmod a+rwx public.pem

cd ./..

echo -e "\xE2\x9C\x94 Created RSA pair key"


# Give public key
echo "Public key:"
cat ./core/public.pem
echo -e "\xE2\x9C\x94 Given RSA public key"



# Create on-startup service
echo -e "[Unit]\nAfter=network.service\n\n[Service]\nExecStart=/bin/createstructure/core/manager.sh\n\n[Install]\nWantedBy=default.target\n" > /etc/systemd/system/createstructure.service
chmod 664 /etc/systemd/system/createstructure.service
systemctl enable createstructure.service > /dev/null

echo -e "\xE2\x9C\x94 Created & cloned service"


# End
echo -e "\xE2\x9C\x94 End"
echo "Made w/ ❤ by Castellani Davide (@DavideC03)"
