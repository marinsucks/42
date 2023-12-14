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
    # if no $2, add all files
    if [ -z "$2" ]; then
        echo "git add ."
        git add . 
    else
        shift 1 && echo "git add "$@""
        git add "$@" 
    fi
    echo -e "\n${LGREEN}Commit message = ${NC}\"$1\""
    echo -e "\n${RED}Are you sure you want to push to origin?${LRED}"
    read -p "[y/n ]" -n 1 -r
    if [[ ! $REPLY =~ ^[Yy]$|^$ ]]; then
        echo -e "\n\n${YELLOW}Push aborted.${LYELLOW}"
        git reset $@
        exit 1
    fi
    git commit -m "$1"
    echo -e "\n${LGREEN}Pushing origin...${NC}"
    git push origin
    echo -e "\n${GREEN}REPO PUSH COMPLETED $SWAG${NC}"
}

setup_alias() {
    echo -e "${LGREEN}Setting up 'push' alias in ~/.bashrc and ~/.zshrc...${NC}"
    echo -e "push() {\n\t$PWD/git.sh \"\$@\"\n} " >> ~/.bashrc
    source ~/.bashrc
	echo -e "push() {\n\t$PWD/git.sh \"\$@\"\n} " >> ~/.zshrc
    echo -e "${GREEN}Alias 'push' set up successfully.${NC}"
}

if [ $# -eq 0 ]; then
    echo -e "${LRED}Missing commit message.${NC}"
    exit 1
fi

if [ "$1" == "setpush" ]; then
	setup_alias
elif [ "$1" == "help" ]; then
	echo -e "Usage: push \"commit message\" \"[files to add]\""
else
	git_action "$@"
fi

