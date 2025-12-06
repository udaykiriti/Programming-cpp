#!/usr/bin/env bash
# git_auto.sh — Retro CRT with flicker + scanlines, then git actions
# Improved: safer, argument parsing, checks, optional push control
# Usage:
#   ./git_auto.sh "commit message"
#   ./git_auto.sh -n "local-only commit (no push)"
#   ./git_auto.sh --all --signoff "commit message"
#   ./git_auto.sh --branch feature/x "commit message"

set -o errexit
set -o nounset
set -o pipefail

# Colors / effects
GREEN="\e[32m"
DIM="\e[2m"
BRIGHT="\e[1m"
RESET="\e[0m"
BLINK="\e[5m"
CLS="\e[2J\e[H"

# Defaults
DO_PUSH=true
GIT_COMMIT_ALL=false
SIGNOFF=false
TARGET_BRANCH=""
COMMIT_MSG=""

# safe command runner
safe_run() {
  local cmd="$*"
  echo -e "${GREEN}>> ${cmd}${RESET}"
  if ! eval "${cmd}"; then
    echo -e "${GREEN}ERROR: command failed: ${cmd}${RESET}"
    exit 1
  fi
}

# print title (centered-ish)
print_title() {
  echo -e "${GREEN}${BRIGHT}----------------------------------------${RESET}"
  echo -e "${GREEN}${BRIGHT}   SYSTEM UTILITY v1.0  (C) 1989 RTS${RESET}"
  echo -e "${GREEN}${BRIGHT}   MODULE: GIT OPERATION HANDLER${RESET}"
  echo -e "${GREEN}${BRIGHT}----------------------------------------${RESET}"
}

# flicker intro
flicker_intro() {
  for i in 1 2 3; do
    printf "%b" "${CLS}"
    sleep 0.06
    printf "%b" "${CLS}"
    echo -e "${DIM}${GREEN}...initializing display...${RESET}"
    sleep 0.06
    printf "%b" "${CLS}"
    print_title
    sleep 0.06
    printf "%b" "${CLS}"
    sleep 0.04
  done
  printf "%b" "${CLS}"
  print_title
  echo ""
}

# scanline overlay (portable width)
scanline_overlay() {
  local rows=12
  local cols
  cols="$(tput cols 2>/dev/null || echo 40)"
  local i
  for i in $(seq 1 $rows); do
    printf "\n"
    printf "%b" "${DIM}${GREEN}"
    # print half-width blocks to avoid weird wide characters in some terminals
    for c in $(seq 1 $((cols / 2))); do printf "░"; done
    printf "%b" "${RESET}\n"
    sleep 0.04
  done
  sleep 0.08
  printf "%b" "${CLS}"
  print_title
  echo ""
}

# typing effect
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

# usage
usage() {
  cat <<EOF
Usage: $0 [options] "commit message"
Options:
  -n | --no-push       Do not push to remote (local-only)
  -a | --all           use 'git commit -a' (stage tracked changes)
  -s | --signoff       add --signoff to commit
  -b | --branch BR     push to BR instead of detected branch
  -h | --help          show this help
EOF
  exit 1
}

# parse args (simple)
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
      # assume the rest is the commit message (may contain spaces)
      COMMIT_MSG="$*"
      break
      ;;
  esac
done

# final check commit message
if [[ -z "${COMMIT_MSG// }" ]]; then
  echo -e "${GREEN}ERROR: NO COMMIT MESSAGE PROVIDED${RESET}"
  echo -e "${GREEN}USAGE: git_auto.sh \"message\"${RESET}"
  echo -e "${GREEN}SYSTEM STOPPED${RESET}"
  exit 1
fi

# error trap
on_error() {
  echo -e "${GREEN}----------------------------------------${RESET}"
  echo -e "${GREEN}   OPERATION FAILED - SEE ABOVE${RESET}"
  echo -e "${GREEN}----------------------------------------${RESET}"
}
trap on_error ERR

# run intro effects
flicker_intro
scanline_overlay

echo -e "${GREEN}RTS SYSTEM FIRMWARE v1.03  (C) 1989 REALTECH${RESET}"
echo "-----------------------------------------------"
sleep 0.12
type_line "INITIALIZING SYSTEM..." 0.008
sleep 0.06

# quick git environment checks
if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  echo -e "${GREEN}ERROR: not inside a git repository${RESET}"
  exit 1
fi

CURRENT_BRANCH="$(git rev-parse --abbrev-ref HEAD 2>/dev/null || echo "main")"
PUSH_BRANCH="${TARGET_BRANCH:-$CURRENT_BRANCH}"

echo ""
echo -e "${GREEN}>> CHECKING FILE STATE${RESET}"
safe_run "git status --short --branch"

echo ""
echo -e "${GREEN}>> PREPARING CHANGES${RESET}"
if $GIT_COMMIT_ALL; then
  echo -e "${GREEN}   committing tracked changes (git commit -a)${RESET}"
else
  safe_run "git add ."
fi

# check if there is anything staged or changed
if git diff --cached --quiet && ! $GIT_COMMIT_ALL; then
  echo -e "${GREEN}   NO CHANGES TO COMMIT (staged area empty)${RESET}"
  echo -e "${GREEN}   SYSTEM IDLE${RESET}"
  exit 0
fi

# commit flags
COMMIT_OPTS=()
$SIGNOFF && COMMIT_OPTS+=(--signoff)

echo -e "${GREEN}>> WRITING LOG ENTRY${RESET}"
if $GIT_COMMIT_ALL; then
  safe_run "git commit -a -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
else
  if git rev-parse --verify --quiet HEAD >/dev/null 2>&1; then
    # repo has a HEAD -> normal commit
    safe_run "git commit -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
  else
    # initial commit case
    safe_run "git commit --allow-empty -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
  fi
fi

echo -e "${GREEN}   RESULT: STORED${RESET}"
echo ""

if $DO_PUSH; then
  # check if remote exists
  if git remote get-url origin >/dev/null 2>&1; then
    echo -e "${GREEN}>> TRANSMITTING DATA -> origin/${PUSH_BRANCH}${RESET}"
    safe_run "git push origin ${PUSH_BRANCH}"
    echo -e "${GREEN}   RESULT: SENT${RESET}"
  else
    echo -e "${GREEN}   WARNING: no 'origin' remote configured. Skipping push.${RESET}"
  fi
else
  echo -e "${GREEN}>> TRANSMIT SKIPPED (no-push)${RESET}"
fi

echo ""
echo -e "${GREEN}----------------------------------------${RESET}"
echo -e "${GREEN}   OPERATION COMPLETE - SYSTEM IDLE${RESET}"
echo -e "${GREEN}----------------------------------------${RESET}"
echo ""

# final subtle CRT flicker / idle glow (non-fatal)
( printf "%b" "${CLS}"; print_title; sleep 0.06; printf "%b" "${CLS}"; print_title; ) >/dev/null 2>&1 || true

# Blinking green cursor (CRT style). Press Ctrl+C to exit.
while true; do
  echo -ne "${GREEN}${BLINK}_ ${RESET}"
  sleep 0.8
  echo -ne "\b\b  \b\b"
  sleep 0.8
done
