#!/bin/bash
# git_auto.sh — Retro CRT with flicker + scanlines, then git actions

# ANSI sequences
GREEN="\e[32m"
DIM="\e[2m"
BRIGHT="\e[1m"
RESET="\e[0m"
BLINK="\e[5m"
CLS="\e[2J\e[H"

# small helper to print centered-ish title
print_title() {
  echo -e "${GREEN}${BRIGHT}----------------------------------------${RESET}"
  echo -e "${GREEN}${BRIGHT}   SYSTEM UTILITY v1.0  (C) 1989 RTS${RESET}"
  echo -e "${GREEN}${BRIGHT}   MODULE: GIT OPERATION HANDLER${RESET}"
  echo -e "${GREEN}${BRIGHT}----------------------------------------${RESET}"
}

# CRT flicker intro: quick flicker cycles that "power" the screen up
flicker_intro() {
  # number of flickers
  local i
  for i in 1 2 3; do
    # off
    printf "%b" "${CLS}"
    sleep 0.06
    # faint glow (dim)
    printf "%b" "${CLS}"
    echo -e "${DIM}${GREEN}...initializing display...${RESET}"
    sleep 0.06
    # short full-on flash with title
    printf "%b" "${CLS}"
    print_title
    sleep 0.06
    # small pause
    printf "%b" "${CLS}"
    sleep 0.04
  done

  # final steady display
  printf "%b" "${CLS}"
  print_title
  echo ""
}

# scanline overlay: prints thin horizontal lines across the screen to simulate scanlines
# it draws using light shading characters; stays for a moment then the script continues
scanline_overlay() {
  local rows=12      # approximate number of scanlines overlay (tweak to taste)
  local cols=$(tput cols 2>/dev/null || echo 40)
  local r
  # overlay scanlines by printing lines of '░' spaced vertically
  for r in $(seq 1 $rows); do
    # position cursor: approximate vertical placement
    # we print some empty lines first to scatter lines down the screen
    # using printf so we can place the overlay without clearing the whole screen
    printf "\n"
    # print a faint scanline
    printf "%b" "${DIM}${GREEN}"
    # create a line of light block chars sized to terminal width (or 40)
    for c in $(seq 1 $((cols/2))); do printf "░"; done
    printf "%b" "${RESET}\n"
    sleep 0.04
  done
  # brief pause so user sees the effect
  sleep 0.08
  # re-draw main content (clears the overlay preserving retro effect)
  printf "%b" "${CLS}"
  print_title
  echo ""
}

# small typing effect for a line (optional feel)
type_line() {
  local s="$1"
  local delay="${2:-0.008}"
  local i
  for ((i=0; i<${#s}; i++)); do
    printf "%s" "${s:i:1}"
    sleep "$delay"
  done
  printf "\n"
}

# run intro effects
flicker_intro
scanline_overlay

# BIOS-style boot/POST (fast, with short sleeps)
echo -e "${GREEN}RTS SYSTEM FIRMWARE v1.03  (C) 1989 REALTECH${RESET}"
echo "-----------------------------------------------"
sleep 0.18
type_line "INITIALIZING SYSTEM..." 0.01
sleep 0.08

echo ""
echo "MEMORY TEST:"
sleep 0.08
for i in 16 32 64 128 256 512 1024 2048; do
    printf "  %4sKB " "$i"
    type_line "OK" 0.002
    sleep 0.04
done

echo "MEMORY CHECK: PASSED"
sleep 0.08
echo ""

echo "DEVICE CHECK:"
sleep 0.06
type_line "  KEYBOARD ............... OK" 0.002
type_line "  DISPLAY  ............... OK" 0.002
type_line "  STORAGE  ............... OK" 0.002
type_line "  NETWORK  ............... OK" 0.002
sleep 0.06

echo ""
type_line "BOOT COMPLETE" 0.01
echo "-----------------------------------------------"
echo ""

# --- Begin Git operation flow (retro style) ---
echo -e "${GREEN}----------------------------------------${RESET}"
echo -e "${GREEN}   SYSTEM UTILITY v1.0  (C) 1989 RTS${RESET}"
echo -e "${GREEN}   MODULE: GIT OPERATION HANDLER${RESET}"
echo -e "${GREEN}----------------------------------------${RESET}"
echo ""

if [ -z "$1" ]; then
    echo -e "${GREEN}ERROR: NO COMMIT MESSAGE PROVIDED${RESET}"
    echo -e "${GREEN}USAGE: git_auto.sh \"message\"${RESET}"
    echo -e "${GREEN}SYSTEM STOPPED${RESET}"
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

echo -e "${GREEN}----------------------------------------${RESET}"
echo -e "${GREEN}   OPERATION COMPLETE - SYSTEM IDLE${RESET}"
echo -e "${GREEN}----------------------------------------${RESET}"
echo ""

# Final subtle CRT flicker / idle glow
( printf "%b" "${CLS}"; print_title; sleep 0.06; printf "%b" "${CLS}"; print_title; ) >/dev/null 2>&1

# Blinking green cursor (CRT style)
echo -ne "${GREEN}${BLINK}_ ${RESET}"
