#!/bin/bash

GREY='\033[1;30m'
LGREY='\033[0;30m'
RED='\033[1;31m'
LRED='\033[0;31m'
GREEN='\033[1;32m'
LGREEN='\033[0;32m'
YELLOW='\033[1;33m'
LYELLOW='\033[0;33m'
BOLD='\033[1;37m'
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
    echo -e "\n\n${LGREEN}Committing...${NC}"
    git commit -m "$1"
    echo -e "\n${LGREEN}Pushing origin...${NC}"
    git push origin
    echo -e "\n${GREEN}REPO PUSH COMPLETED $SWAG${NC}"
}

setpush() {
    echo -e "${LGREEN}Setting up 'push' alias...${NC}"
    if [ "$(echo $SHELL)" = "/bin/bash" ]; then
        echo -e "alias push=\"$PWD/git.sh\" \"\$@\"" >> ~/.bashrc
        source ~/.bashrc
        echo -e "${GREEN}Alias 'push' set up successfully in ~/.bashrc.${NC}"
    elif [ "$(echo $SHELL)" = "/bin/zsh" ]; then
        echo -e "alias push=\"$PWD/git.sh\" \"\$@\"" >> ~/.zshrc
        source ~/.zshrc
        echo -e "${GREEN}Alias 'push' written successfully in ~/.zshrc.${NC}"
        echo -e "${LYELLOW}If you use ohmyzsh, please run ${YELLOW}'source ~/.zshrc'${LYELLOW} to finish the installation.${NC}"
    else
        echo -e "${LRED}Could not set up alias 'push': please use ./git.sh instead.${NC}"
        echo $0
    fi
}

if [ $# -eq 0 ]; then
    echo -e "${LRED}Missing first argument.\n${LYELLOW}Try ./git.sh help${NC}"
    exit 1
fi

if [ "$1" == "setpush" ]; then
	setpush
elif [ "$1" == "help" ]; then
	
    echo -e "${BOLD}USAGE\t\t${NC}push \"commit message\" \"[files to add]\""
    echo -e "${BOLD}PUSH SETUP:\t${NC}./git.sh setpush  ${LGREY}-> aliases the push command, replacing ./git.sh${NC}"
else
	git_action "$@"
fi

