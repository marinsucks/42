#!/bin/bash

RED='\033[1;31m'
YELLOW='\033[1;33m'
GREEN='\033[1;32m'
NC='\033[0m'

if ! sudo test ok; then
	echo -e "${RED}Error: sudo failure for $USER${NC}"
	exit 1
fi

echo -e "${YELLOW}Updating package list...${NC}"
sudo apt-get update

echo -e "${YELLOW}Installing basic packages...${NC}"
sudo apt-get install -yq \
	curl \
	wget \
	git \
	ssh
sudo systemctl enable ssh

echo -e "${YELLOW}Installing Docker...${NC}"
sudo apt-get install -yq \
	ca-certificates
sudo install -m 0755 -d /etc/apt/keyrings
sudo curl -fsSL https://download.docker.com/linux/debian/gpg -o /etc/apt/keyrings/docker.asc
sudo chmod a+r /etc/apt/keyrings/docker.asc
echo   "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/debian \
	$(. /etc/os-release && echo "$VERSION_CODENAME") stable" |   sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
sudo groupadd docker
sudo usermod -aG docker $USER

echo -e "${YELLOW}Installing Visual Studio Code...${NC}"
sudo apt-get install -yq \
	software-properties-common \
	apt-transport-https
wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main"
sudo apt-get update
sudo apt-get install -yq code

echo -e "${YELLOW}Installing oh-my-zsh...${NC}"
sudo apt-get install zsh
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
chsh -s $(which zsh) $USER

echo -e "${YELLOW}Setting theme to dark...${NC}"
gsettings set org.gnome.desktop.interface gtk-theme 'Adwaita-dark'

echo -e "${YELLOW}Setting dock apps...${NC}"
gsettings set org.gnome.shell favorite-apps "['firefox.desktop', 'org.gnome.Nautilus.desktop', 'org.gnome.Terminal.desktop', 'code.desktop']"

echo -e "${GREEN}Setup complete! Please reboot for changes to be applied.${NC}"
