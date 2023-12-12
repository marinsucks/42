#!/bin/bash

RED='\033[1;31m'
LRED='\033[0;31m'
GREEN='\033[1;32m'
LGREEN='\033[0;32m'
YELLOW='\033[1;33m'
LYELLOW='\033[0;33m'
GREY='\033[1;37m'
NC='\033[0m'
SWAG='🫠'

git_action() {
    echo -e "\n${LGREEN}Adding all 42 files to staging area...${NC}"
    git add . 
    echo -e "\n${LGREEN}Commit message = \"$@\"${NC}"
    echo -e "\n${RED}Are you sure you want to push to origin?${NC}"
    read -p "[y/n ]" -n 1 -r
    if [[ ! $REPLY =~ ^[Yy]$|^$ ]]; then
        echo -e "\n${LYELLOW}Exiting...${NC}"
        exit 1
    fi
    git commit -m "$1"
    echo -e "\n${LGREEN}Pushing origin...${NC}"
    git push origin
    echo -e "\n${GREEN}REPO PUSH COMPLETED $SWAG${NC}"
}

#setup_alias() {
#    echo -e "${LGREEN}Setting up 'push' alias in ~/.bashrc and ~/.zshrc...${NC}"
#    echo "alias push='/bin/bash $PWD/git.sh'" >> ~/.bashrc
#    source ~/.bashrc
#	echo "alias push='/bin/zsh $PWD/git.sh'" >> ~/.zshrc
#    echo -e "${GREEN}Alias 'push' set up successfully.${NC}"
#}

if [ $# -eq 0 ]; then
    echo -e "${LRED}Missing commit message.\n${LYELLOW}Usage: $0 'commit message'${NC}"
    exit 1
fi

if [ "$1" == "setpush" ]; then
	setup_alias
else
	git_action "$@"
fi
