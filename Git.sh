#!/usr/bin/env bash
# git_auto_nostalgia.sh — Ultra-nostalgic CRT + vintage POST + git actions
# - Amber monochrome look
# - Large ASCII CRT logo
# - POST with faux floppy/modem handshake and checksum progress
# - Optional bells (terminal BEL), optional no-push, signoff, branch, commit-all
# Usage:
#   NO_BELL=1 ./git_auto_nostalgia.sh "commit message"
#   ./git_auto_nostalgia.sh -n -a --signoff -b feature/x "msg"

set -o errexit
set -o nounset
set -o pipefail

# Appearance (amber / green fallback)
AMBER="\e[33m"
GREEN="\e[32m"
DIM="\e[2m"
BRIGHT="\e[1m"
RESET="\e[0m"
BLINK="\e[5m"
CLS="\e[2J\e[H"
NO_BELL="${NO_BELL:-0}"

# Options defaults
DO_PUSH=true
GIT_COMMIT_ALL=false
SIGNOFF=false
TARGET_BRANCH=""
COMMIT_MSG=""

# helper: optionally ring system bell (if NO_BELL != 1)
bell() {
  if [[ "$NO_BELL" != "1" ]]; then
    printf "\a"    # terminal bell
  fi
}

# small safe runner (quiet by default)
safe_run() {
  local cmd="$*"
  echo -e "${AMBER}>>> ${cmd}${RESET}"
  if ! eval "${cmd}"; then
    echo -e "${AMBER}!!! ERROR running: ${cmd}${RESET}"
    exit 1
  fi
}

# Usage
usage() {
  cat <<EOF
Usage: $0 [options] "commit message"
Options:
  -n | --no-push       Do not push to remote (local-only)
  -a | --all           use 'git commit -a' (commit tracked files)
  -s | --signoff       add --signoff to commit
  -b | --branch BR     push to BR instead of detected branch
  -h | --help          show help
Env:
  NO_BELL=1            suppress audible bell
EOF
  exit 1
}

# Parse args (simple)
while [[ $# -gt 0 ]]; do
  case "$1" in
    -n|--no-push) DO_PUSH=false; shift ;;
    -a|--all) GIT_COMMIT_ALL=true; shift ;;
    -s|--signoff) SIGNOFF=true; shift ;;
    -b|--branch)
      if [[ -z "${2:-}" ]]; then echo "Missing branch name"; usage; fi
      TARGET_BRANCH="$2"; shift 2 ;;
    -h|--help) usage ;;
    --) shift; break ;;
    -*)
      echo "Unknown option: $1"
      usage
      ;;
    *)
      COMMIT_MSG="$*"
      break
      ;;
  esac
done

if [[ -z "${COMMIT_MSG// }" ]]; then
  echo -e "${AMBER}ERROR: missing commit message.${RESET}"
  usage
fi

# Nostalgic visuals
crt_logo() {
  cat <<'EOF'
   ____  ____  _______  ______  ____  _____
  / ___||  _ \|__   __||  ____|/ __ \|  __ \
 | |    | |_) |  | |   | |__  | |  | | |__) |
 | |    |  _ <   | |   |  __| | |  | |  _  /
 | |____| |_) |  | |   | |____| |__| | | \ \
  \_____|____/   |_|   |______|\____/|_|  \_\
EOF
}

type_slow() {
  local s="$1"; local delay="${2:-0.012}"
  local i
  for ((i=0; i<${#s}; i++)); do
    printf "%s" "${s:i:1}"
    sleep "$delay"
  done
  printf "\n"
}

spinner() {
  local duration=${1:-2} # seconds
  local end=$((SECONDS + duration))
  local i=0
  while [ $SECONDS -lt $end ]; do
    printf "\r%s" "/-\|"[ $((i%4)) ]
    i=$((i+1))
    sleep 0.08
  done
  printf "\r"
}

# Fake hardware POST & vibe
post_boot() {
  printf "%b" "${CLS}"
  echo -e "${AMBER}${BRIGHT}"
  crt_logo
  echo -e "${RESET}"
  echo -e "${AMBER}${DIM}BIOS v2.4 - REALTECH INDUSTRIES${RESET}"
  echo -e "${AMBER}Date: 1989-11-01    Firmware: 0xDEADBEEF${RESET}"
  sleep 0.22; bell
  echo ""
  type_slow "${AMBER}POWER ON SELF TEST (POST)${RESET}" 0.009
  sleep 0.05

  # Memory test with patterns
  echo -n "${AMBER}MEMORY TEST : "
  for size in 16 32 64 128 256 512 1024; do
    printf "%4sKB " "$size"
    # pretend to run pattern checks
    sleep 0.08
    printf "${GREEN}OK ${RESET}"
  done
  echo -e "\n${AMBER}MEMORY CHECK: ${GREEN}PASSED${RESET}"
  bell
  sleep 0.08

  # Device checks
  type_slow "${AMBER}DEVICE CHECKS${RESET}" 0.01
  type_slow "  [FLOPPY DRIVE] : 1.44MB - READY" 0.006
  type_slow "  [TTY-0]        : ONLINE" 0.006
  type_slow "  [MODEM]       : HAYES 2400bps - INITIALIZING" 0.006
  sleep 0.06
  # faux modem handshake (visual)
  echo -n "  [MODEM HANDSHAKE] : "
  for i in 1 2 3; do
    printf "DIAL-"
    sleep 0.09
    printf "TONE "
    sleep 0.09
    printf "."
    bell
    sleep 0.06
  done
  echo " OK"
  sleep 0.08
  echo ""
}

checksum_progress() {
  local len=40
  echo -n "${AMBER}SYSTEM CHECKSUM: ["
  for i in $(seq 1 $len); do
    # fake work
    printf "%b" "${GREEN}#${RESET}"
    sleep 0.015
  done
  echo "] ${GREEN}0xC0FFEE${RESET}"
  bell
}

teletext_announce() {
  echo ""
  type_slow "${AMBER}--- WELCOME TO RTS SYSTEMS - PLEASE STAND BY ---${RESET}" 0.01
  echo ""
}

# "press any key" utility
press_any_key() {
  echo -n "${AMBER}Press any key to continue... ${RESET}"
  # read -n 1 -s || true
  # small non-blocking wait for older shells: timeout 3s if no keypress
  if command -v read >/dev/null 2>&1; then
    # give user up to 3 seconds to press something
    ( read -t 3 -n 1 -s _ >/dev/null 2>&1 ) || true
  else
    sleep 1
  fi
  echo ""
}

# error trap (nostalgic)
on_error() {
  echo -e "${AMBER}"
  echo "----------------------------------------"
  echo "  SYSTEM HALT - UNRECOVERABLE ERROR"
  echo "----------------------------------------"
  echo -e "${RESET}"
}
trap on_error ERR

# run the visual sequence
post_boot
checksum_progress
teletext_announce
press_any_key

# Git operational logic (kept robust)
if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  echo -e "${AMBER}ERROR: This is not a git repository.${RESET}"
  exit 1
fi

CURRENT_BRANCH="$(git rev-parse --abbrev-ref HEAD 2>/dev/null || echo "main")"
PUSH_BRANCH="${TARGET_BRANCH:-$CURRENT_BRANCH}"

echo -e "${AMBER}${BRIGHT}>> REPOSITORY STATUS${RESET}"
safe_run "git status --short --branch"

echo ""
echo -e "${AMBER}>> STAGING CHANGES${RESET}"
if $GIT_COMMIT_ALL; then
  echo -e "${AMBER}  (committing tracked files: -a)${RESET}"
else
  safe_run "git add ."
fi

# if nothing staged and not commit-all -> exit gracefully
if git diff --cached --quiet && ! $GIT_COMMIT_ALL; then
  echo -e "${AMBER}  NO CHANGES TO COMMIT. System idle.${RESET}"
  exit 0
fi

COMMIT_OPTS=()
$SIGNOFF && COMMIT_OPTS+=(--signoff)

echo ""
echo -e "${AMBER}>> WRITING LOG ENTRY${RESET}"
if $GIT_COMMIT_ALL; then
  safe_run "git commit -a -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
else
  if git rev-parse --verify --quiet HEAD >/dev/null 2>&1; then
    safe_run "git commit -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
  else
    # initial commit fallback
    safe_run "git commit --allow-empty -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
  fi
fi

# show a little retro commit summary
echo ""
echo -e "${AMBER}>> COMMIT RESULT${RESET}"
git --no-pager log -1 --pretty=format:"%C(yellow)%h %C(green)%cr %C(reset)%s"
echo ""

if $DO_PUSH; then
  if git remote get-url origin >/dev/null 2>&1; then
    echo -e "${AMBER}>> TRANSMITTING TO ORIGIN/${PUSH_BRANCH}${RESET}"
    safe_run "git push origin ${PUSH_BRANCH}"
    echo -e "${AMBER}  Transmission complete. Goodnight, and good luck.${RESET}"
  else
    echo -e "${AMBER}  No 'origin' remote configured; push skipped.${RESET}"
  fi
else
  echo -e "${AMBER}>> TRANSMIT SKIPPED (local-only)${RESET}"
fi

# final "idle CRT" effect: slow shimmer + optional bell
echo ""
for i in 1 2 3; do
  printf "%b" "${CLS}"
  echo -e "${AMBER}${BRIGHT}"
  crt_logo
  echo -e "${RESET}"
  sleep 0.14
  bell
done

echo -e "${AMBER}--- OPERATION COMPLETE ---${RESET}"
echo ""
# tiny, elegant cursor blink for nostalgia (auto-exit after 6 blinks)
for i in $(seq 1 6); do
  echo -ne "${AMBER}${BLINK}_ ${RESET}"
  sleep 0.7
  echo -ne "\b\b  \b\b"
  sleep 0.2
done

echo -e "${AMBER}SYSTEM IDLE${RESET}"
exit 0
