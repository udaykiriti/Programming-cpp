#!/usr/bin/env bash
# git_auto.sh — Ultra-retro CRT + scanlines + noise + git automation (FIXED)
# Usage: ./Git.sh [--slow|--no-effects] "commit message"

# -------- CONFIG (tweak to taste) --------
SLOW_MODE=0
EFFECTS_ON=1

# parse flags
if [ "$1" = "--slow" ]; then
  SLOW_MODE=1
  shift
elif [ "$1" = "--no-effects" ]; then
  EFFECTS_ON=0
  shift
fi

# commit message now should be $1
MSG="$1"

# speed multipliers
if [ "$SLOW_MODE" -eq 1 ]; then
  SLP=0.12
  TYP=0.02
else
  SLP=0.06
  TYP=0.008
fi

# ANSI
GREEN="\e[32m"
DIM="\e[2m"
BRIGHT="\e[1m"
RESET="\e[0m"
BLINK="\e[5m"
CLS="\e[2J\e[H"

# terminal geometry
COLS=$(tput cols 2>/dev/null || echo 80)
LINES=$(tput lines 2>/dev/null || echo 24)

# helpers
# rnd max -> 0..max-1, safe with max<=1
rnd() {
  local max=${1:-1}
  if [ "$max" -le 1 ]; then
    echo 0
  else
    echo $(( RANDOM % max ))
  fi
}

type_line() {
  local s="$1"; local d="${2:-$TYP}"
  local i
  for ((i=0;i<${#s};i++)); do
    printf "%s" "${s:i:1}"
    sleep "$d"
  done
  printf "\n"
}

center() {
  local s="$1"
  local pad=$(( (COLS - ${#s}) / 2 ))
  [ "$pad" -lt 0 ] && pad=0
  printf "%*s%s\n" $pad "" "$s"
}

# visual effect funcs
print_title() {
  center "${GREEN}${BRIGHT}----------------------------------------${RESET}"
  center "${GREEN}${BRIGHT}   SYSTEM UTILITY v1.0  (C) 1989 RTS${RESET}"
  center "${GREEN}${BRIGHT}   MODULE: GIT OPERATION HANDLER${RESET}"
  center "${GREEN}${BRIGHT}----------------------------------------${RESET}"
}

flicker_intro() {
  # multiple randomized flickers
  local cycles=$((3 + $(rnd 3)))
  local i
  for i in $(seq 1 $cycles); do
    printf "%b" "${CLS}"
    sleep "$(awk -v s=$SLP -v r=$(rnd 40) 'BEGIN{printf \"%.3f\", s * (0.4 + r/100)}')"
    # dim glow, sometimes with jitter
    if [ $((rnd 2)) -eq 0 ]; then
      printf "%b" "${DIM}${GREEN}"
      center "...initializing display..."
      printf "%b" "${RESET}"
    fi
    sleep "$(awk -v s=$SLP -v r=$(rnd 40) 'BEGIN{printf \"%.3f\", s * (0.2 + r/200)}')"
    printf "%b" "${CLS}"
    print_title
    # tiny shake: redraw with small horizontal shift sometimes
    if [ $((rnd 3)) -eq 0 ]; then
      printf "%b" "${CLS}"
      printf "%*s" $((2 + $(rnd 4))) ""
      print_title
    fi
    sleep "$(awk -v s=$SLP -v r=$(rnd 50) 'BEGIN{printf \"%.3f\", s * (0.06 + r/150)}')"
  done
  # brief extra flash
  printf "%b" "${CLS}"
  print_title
  sleep $SLP
}

scanline_overlay() {
  # Print alternating faint scanlines across the screen then repaint main content
  local rows=$((LINES / 2))
  local chalf=$((COLS / 2))
  # move down a bit
  for i in $(seq 1 2); do printf "\n"; done
  for r in $(seq 1 $rows); do
    # alternate denser/light scanlines
    if [ $((r % 2)) -eq 0 ]; then
      printf "%b" "${DIM}${GREEN}"
      for c in $(seq 1 $chalf); do printf "░"; done
      printf "%b" "${RESET}\n"
    else
      printf "%b" "${DIM}${GREEN}"
      for c in $(seq 1 $((chalf/2))); do printf " "; done
      printf "%b" "${RESET}\n"
    fi
    sleep 0.01
  done
  sleep $SLP
  printf "%b" "${CLS}"
  print_title
}

phosphor_fade() {
  # simulate phosphor decay by reprinting text in dim color after short delay
  sleep 0.18
  printf "%b" "${DIM}${GREEN}"
  center "   OPERATION COMPLETE - SYSTEM IDLE"
  printf "%b" "${RESET}\n"
}

screen_noise() {
  # brief random speckles of noise
  local speckles=30
  local i xr yr
  # compute max y for noise, ensure positive
  local max_y=$(( LINES - 6 ))
  if [ "$max_y" -le 1 ]; then
    max_y=1
  fi
  for i in $(seq 1 $speckles); do
    xr=$(rnd "$COLS")
    yr=$(( 3 + $(rnd "$max_y") ))
    # move cursor and print a tiny block; ignore tput errors in weird terminals
    tput cup "$yr" "$xr" 2>/dev/null || true
    printf "%b" "${DIM}${GREEN}█${RESET}"
    sleep 0.005
  done
  sleep 0.06
  printf "%b" "${CLS}"
  print_title
}

curved_print() {
  # mimic convex CRT curvature by adding variable padding per line
  local lines=6
  local i offset
  for i in $(seq 1 $lines); do
    offset=$(( (lines/2 - i) * 2 ))
    if [ $offset -ge 0 ]; then
      printf "%*s" $offset ""
    else
      printf "%*s" $(( -offset )) ""
    fi
    case $i in
      1) center "${GREEN}RTS SYSTEM FIRMWARE v1.03  (C) 1989 REALTECH${RESET}";;
      2) center "-----------------------------------------------";;
      3) center "INITIALIZING SYSTEM...";;
      4) center "MEMORY TEST:";;
      5) center "DEVICE CHECK:";;
      6) center "BOOT COMPLETE";;
    esac
    sleep 0.02
  done
  echo ""
}

# ----- run effects if enabled -----
if [ "$EFFECTS_ON" -eq 1 ]; then
  printf "%b" "${CLS}"
  flicker_intro
  scanline_overlay
  curved_print
  # small memory test with typing feel
  for i in 16 32 64 128 256 512 1024 2048; do
    printf "  %4sKB " "$i"
    type_line "OK" 0.004
    sleep 0.03
  done
  type_line "MEMORY CHECK: PASSED" 0.01
  sleep 0.03
  type_line "DEVICE CHECK:" 0.01
  type_line "  KEYBOARD ............... OK" 0.003
  type_line "  DISPLAY  ............... OK" 0.003
  type_line "  STORAGE  ............... OK" 0.003
  type_line "  NETWORK  ............... OK" 0.003
  sleep 0.04
  # noise & brief flicker
  screen_noise
fi

# --- main title and git ops header (always show)
printf "%b" "${CLS}"
print_title
echo ""

# if no message provided, show usage and exit
if [ -z "$MSG" ]; then
  echo -e "${GREEN}ERROR: NO COMMIT MESSAGE PROVIDED${RESET}"
  echo -e "${GREEN}USAGE: Git.sh [--slow|--no-effects] \"message\"${RESET}"
  echo -e "${GREEN}SYSTEM STOPPED${RESET}"
  exit 1
fi

# perform git steps with small retro labels
echo -e "${GREEN}>> CHECKING FILE STATE${RESET}"
git status
echo -e "${GREEN}   STATUS: OK${RESET}"
echo ""

echo -e "${GREEN}>> PREPARING CHANGES${RESET}"
git add .
echo -e "${GREEN}   RESULT: READY${RESET}"
echo ""

echo -e "${GREEN}>> WRITING LOG ENTRY${RESET}"
git commit -m "$MSG"
echo -e "${GREEN}   RESULT: STORED${RESET}"
echo ""

echo -e "${GREEN}>> TRANSMITTING DATA${RESET}"
git push origin main
echo -e "${GREEN}   RESULT: SENT${RESET}"
echo ""

# final lines + phosphor fade and subtle flicker
echo -e "${GREEN}----------------------------------------${RESET}"
echo -e "${GREEN}   OPERATION COMPLETE - SYSTEM IDLE${RESET}"
echo -e "${GREEN}----------------------------------------${RESET}"
if [ "$EFFECTS_ON" -eq 1 ]; then
  phosphor_fade &
fi

# a small final flicker / glow
if [ "$EFFECTS_ON" -eq 1 ]; then
  sleep 0.05
  printf "%b" "${CLS}"
  print_title
  sleep 0.04
  printf "%b" "${CLS}"
  print_title
fi

# blinking green cursor (CRT style) - leave it at prompt
echo -ne "${GREEN}${BLINK}_${RESET}"
