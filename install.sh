#!/bin/bash
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
if [ "$#" -ne 4 ]; then
    echo "Illegal number of parameters"
    echo "install.sh {GITHUB_USERNAME} {GITHUB_TOKEN} {SERVER_ID} {SERVER_CODE}"
    echo "Replacing {...} with correct vaules"
    exit 1
fi

GITHUB_USERNAME=$1
GITHUB_TOKEN=$2
SERVER_ID=$3
SERVER_CODE=$4

echo -e "\xE2\x9C\x94 Getted arguments"


# Update & Upgrade
apt update > /dev/null
apt full-upgrade -y > /dev/null

echo -e "\xE2\x9C\x94 Updated & Upgraded"


# Install Docker
apt install docker.io -y > /dev/null
docker login docker.pkg.github.com --username $GITHUB_USERNAME --password $GITHUB_TOKEN
docker pull docker.pkg.github.com/createstructure/core-createstructure/core

echo -e "\xE2\x9C\x94 Installed Docker"


# Install git
apt install git -y > /dev/null

echo -e "\xE2\x9C\x94 Installed git"


# Change current position to /bin
cd /bin

echo -e "\xE2\x9C\x94 Changed directory to /bin"


# Install project & prepare data folder
add-apt-repository ppa:castellanidavide/createstructure -y
apt install manager -y
mkdir createstructure
cd createstructure

echo -e "\xE2\x9C\x94 Installed project & prepare data folder"


# Create settings
echo "{\"server_id\": \"$SERVER_ID\", \"server_code\": \"$SERVER_CODE\"}" > ./server.settings

echo -e "\xE2\x9C\x94 Created settings"


# Create key pair
# Create
openssl genrsa -out private.pem 2048 > /dev/null
openssl rsa -in private.pem -outform PEM -pubout -out public.pem > /dev/null

# Make keys visible
sudo chmod a+rwx private.pem
sudo chmod a+rwx public.pem

echo -e "\xE2\x9C\x94 Created RSA pair key"


# Give public key
echo "Public key:"
cat ./public.pem
echo -e "\xE2\x9C\x94 Given RSA public key"


# Create on-startup service
echo -e '#!/bin/bash\n\ncd "$(dirname "$0")"\n# Make to have the correcth rights\nif [[ $UID != 0 ]]; then\n    echo "Please run this script with sudo:"\n    echo "sudo $0 $* ..."\n    exit 1\nfi\nexec sudo manager >> log.txt\n' > ./manager.sh
echo -e "[Unit]\nAfter=network.service\n\n[Service]\nExecStart=/bin/createstructure/manager.sh\n\n[Install]\nWantedBy=default.target\n" > /etc/systemd/system/createstructure.service
chmod 664 /etc/systemd/system/createstructure.service
systemctl enable createstructure.service > /dev/null

echo -e "\xE2\x9C\x94 Created & cloned service"


# End
echo -e "\xE2\x9C\x94 End"
echo "Made w/ ❤ by Castellani Davide (@DavideC03)"
