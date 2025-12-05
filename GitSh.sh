#!/bin/bash

# Enable classic green CRT text
GREEN="\e[32m"
RESET="\e[0m"
BLINK="\e[5m"

clear

echo -e "${GREEN}RTS SYSTEM FIRMWARE v1.03  (C) 1989 REALTECH"
echo "-----------------------------------------------"
sleep 0.3
echo "INITIALIZING SYSTEM..."
sleep 0.4
echo " "
echo "MEMORY TEST:"
sleep 0.4

# Fake memory test animation
for i in 16 32 64 128 256 512 1024 2048; do
    echo -e "  ${i}KB OK"
    sleep 0.15
done

echo "MEMORY CHECK: PASSED"
sleep 0.3
echo ""

echo "DEVICE CHECK:"
sleep 0.3
echo "  KEYBOARD ............... OK"
sleep 0.15
echo "  DISPLAY  ............... OK"
sleep 0.15
echo "  STORAGE  ............... OK"
sleep 0.15
echo "  NETWORK  ............... OK"
sleep 0.15
echo ""

echo "BOOT COMPLETE"
sleep 0.3
echo "-----------------------------------------------"
echo ""

# --- YOUR ORIGINAL RETRO TERMINAL SCRIPT BELOW ---

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
