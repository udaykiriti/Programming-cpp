#!/bin/bash

# Enable classic green CRT text
GREEN="\e[32m"
RESET="\e[0m"
BLINK="\e[5m"

echo -e "${GREEN}----------------------------------------"
echo -e "   SYSTEM UTILITY v1.0  (C) 1989 RTS"
echo -e "   MODULE: GIT OPERATION HANDLER"
echo -e "----------------------------------------${RESET}"
echo ""

if [ -z "$1" ]; then
    echo -e "${GREEN}ERROR: NO COMMIT MESSAGE PROVIDED"
    echo -e "USAGE: git_auto.sh \"message\""
    echo -e "SYSTEM STOPPED${RESET}"
    exit 1
fi

echo -e "${GREEN}>> CHECKING FILE STATE${RESET}"
git status
echo -e "${GREEN}   STATUS: OK${RESET}"
echo ""

echo -e "${GREEN}>> PREPARING CHANGES${RESET}"
git add .
echo -e "${GREEN}   RESULT: READY${RESET}"
echo ""

echo -e "${GREEN}>> WRITING LOG ENTRY${RESET}"
git commit -m "$1"
echo -e "${GREEN}   RESULT: STORED${RESET}"
echo ""

echo -e "${GREEN}>> TRANSMITTING DATA${RESET}"
git push origin main
echo -e "${GREEN}   RESULT: SENT${RESET}"
echo ""

echo -e "${GREEN}----------------------------------------"
echo -e "   OPERATION COMPLETE - SYSTEM IDLE"
echo -e "----------------------------------------${RESET}"

# Blinking green cursor (CRT style)
echo -ne "${GREEN}${BLINK}_ ${RESET}"
