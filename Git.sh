#!/usr/bin/env bash
# git_auto_retro_pc.sh — Retro PC (IBM/XT/386) boot experience + git automation
# Drop-in nostalgia: POST, CHKDSK, floppy prompts, HDD seek LEDs, AUTOEXEC, BASIC prompt
# Keeps robust git ops: --dry-run, --interactive, --no-push, --all, --signoff, --branch, --theme
# Usage examples:
#   ./git_auto_retro_pc.sh "fix: tiny bug"
#   ./git_auto_retro_pc.sh --dry-run --interactive -a "wip: test"
#   THEME=green ./git_auto_retro_pc.sh --long-handshake "release candidate"

set -o errexit
set -o nounset
set -o pipefail

THEME="${THEME:-amber}"
NO_BELL="${NO_BELL:-0}"
DRY_RUN=false
INTERACTIVE=false
LONG_HANDSHAKE=false

DO_PUSH=true
GIT_COMMIT_ALL=false
SIGNOFF=false
TARGET_BRANCH=""
COMMIT_MSG=""

AMP="\e[33m"
GRN="\e[32m"
DIM="\e[2m"
BRIGHT="\e[1m"
RESET="\e[0m"
BLINK="\e[5m"
CLS="\e[2J\e[H"

if [[ "$THEME" == "green" ]]; then
  ACC="$GRN"
else
  ACC="$AMP"
fi

bell() {
  [[ "$NO_BELL" == "1" ]] && return
  printf "\a"
}

safe_run() {
  local cmd="$*"
  echo -e "${ACC}>>> ${cmd}${RESET}"
  if $DRY_RUN; then
    echo -e "${ACC}(dry-run) not executed${RESET}"
    return 0
  fi
  if ! eval "${cmd}"; then
    echo -e "${ACC}!!! ERROR running: ${cmd}${RESET}"
    exit 1
  fi
}

ask_yes_no() {
  local prompt="$1" ans
  while true; do
    read -r -p "${prompt} [y/n] " ans
    case "${ans,,}" in
      y|yes) return 0 ;;
      n|no) return 1 ;;
      *) echo "Please answer y or n." ;;
    esac
  done
}

type_slow() {
  local s="$1" delay="${2:-0.009}" i
  for ((i=0; i<${#s}; i++)); do
    printf "%s" "${s:i:1}"
    sleep "$delay"
  done
  printf "\n"
}

# tiny progress bar
progress_bar() {
  local width=${1:-30} speed=${2:-0.015}
  printf "["
  local i
  for i in $(seq 1 "$width"); do
    printf "%b#%b" "$ACC" "$RESET"
    sleep "$speed"
  done
  printf "]\n"
}

hdd_seek() {
  local times=${1:-14} i j
  for i in $(seq 1 "$times"); do
    printf "  HDD: ["
    for j in 1 2 3 4; do
      if (( (i + j) % 4 == 0 )); then
        printf "%b=%b" "$ACC" "$RESET"
      else
        printf " "
      fi
    done
    printf "]\r"
    sleep 0.08
  done
  echo ""
}

floppy_activity() {
  local n=${1:-18} i j
  for i in $(seq 1 "$n"); do
    printf "  FLOPPY: ["
    for j in $(seq 1 18); do
      if (( (i + j) % 5 == 0 )); then
        printf "%b*%b" "$ACC" "$RESET"
      else
        printf "."
      fi
    done
    printf "]\r"
    sleep 0.05
  done
  echo ""
}

crt_warmup() {
  local frames=3
  local i
  for i in $(seq 1 "$frames"); do
    printf "%b" "$CLS"
    echo -e "${ACC}${DIM}BOOTING...${RESET}"
    sleep 0.05
    printf "%b" "$CLS"
    sleep 0.05
  done
}

crt_shutdown() {
  local i
  for i in 3 2 1; do
    printf "%b" "$CLS"
    echo -e "${ACC}${BRIGHT}POWERING DOWN IN: ${i}${RESET}"
    bell
    sleep 0.7
  done
  printf "%b" "$CLS"
  echo -e "${ACC}${BRIGHT}SYSTEM HALT. GOODNIGHT.${RESET}"
}

blink_cursor_line() {
  local text="$1" cycles="${2:-6}"
  local i
  for i in $(seq 1 "$cycles"); do
    printf "\r%s%s_" "$text" "$ACC"
    sleep 0.2
    printf "\r%s " "$text"
    sleep 0.2
  done
  echo ""
}

usage() {
  cat <<EOF
Usage: $0 [options] "commit message"

Options:
  -n, --no-push        Do not push to remote (local-only)
  -a, --all            Commit tracked files (git commit -a)
  -s, --signoff        Add --signoff to commit
  -b, --branch BR      Push to BR instead of detected branch
      --dry-run        Print actions but do not execute git commands
      --interactive    Preview staged diff and confirm before actions
      --long-handshake Dramatic modem / floppy animations
      --theme THEME    Theme: amber (default) or green
  -h, --help           Show this help

Env:
  NO_BELL=1            Mute terminal bell
  THEME=green          Green phosphor style
EOF
  exit 1
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    -n|--no-push)
      DO_PUSH=false
      shift
      ;;
    -a|--all)
      GIT_COMMIT_ALL=true
      shift
      ;;
    -s|--signoff)
      SIGNOFF=true
      shift
      ;;
    -b|--branch)
      if [[ -z "${2:-}" ]]; then
        echo "Missing branch name"
        usage
      fi
      TARGET_BRANCH="$2"
      shift 2
      ;;
    --dry-run)
      DRY_RUN=true
      shift
      ;;
    --interactive)
      INTERACTIVE=true
      shift
      ;;
    --long-handshake)
      LONG_HANDSHAKE=true
      shift
      ;;
    --theme)
      if [[ -z "${2:-}" ]]; then
        echo "Missing theme"
        usage
      fi
      THEME="$2"
      shift 2
      if [[ "$THEME" == "green" ]]; then
        ACC="$GRN"
      else
        ACC="$AMP"
      fi
      ;;
    -h|--help)
      usage
      ;;
    --)
      shift
      break
      ;;
    -*)
      echo "Unknown option: $1"
      usage
      ;;
    *)
      # everything else = commit message
      COMMIT_MSG="$*"
      break
      ;;
  esac
done

if [[ -z "${COMMIT_MSG// }" ]]; then
  echo -e "${ACC}ERROR: missing commit message${RESET}"
  usage
fi

# ----------------- Retro PC visuals -----------------
pc_ascii() {
  cat <<'EOF'
      .----------------------------------------------.
      |   ________   ____   ____   ____   ____      |
      |  |  ____  | |  __| | |__| |  __| | |__|     |
      |  | |    | | | |    |  __| | |    |  __|     |
      |  | |____| | | |___ | |    | |___ | |        |
      |  |________| |_____|'_|    |_____|'_|        |
      '----------------------------------------------'
       IBM PC/XT - Retro Emulation Console v1.0
EOF
}

boot_post() {
  crt_warmup
  printf "%b" "$CLS"
  echo -e "${ACC}${BRIGHT}"
  pc_ascii
  echo -e "${RESET}"
  sleep 0.12

  type_slow "${ACC}IBM PC/XT BIOS v4.10  1986 (C) REALTECH${RESET}" 0.008
  bell; sleep 0.08
  type_slow "Performing QUICK POWER-ON SELF TEST (POST)..." 0.006

  # fake POST progress
  progress_bar 28 0.012

  type_slow "  CPU: 80286 (simulated) ................ OK" 0.004; sleep 0.06
  type_slow "  FPU: none .............................. OK" 0.004; sleep 0.04
  type_slow "  RAM: 512KB base + 512KB extended ........ OK" 0.004; sleep 0.05
  bell
  type_slow "  VIDEO: MDA/CGA compatible ................ OK" 0.004; sleep 0.04
  type_slow "  FLOPPY CONTROLLER ....................... OK" 0.004; sleep 0.04
  type_slow "  HARD DISK CONTROLLER .................... OK" 0.004; sleep 0.04
  echo ""
}

chk_dsk_sim() {
  type_slow "${ACC}Starting CHKDSK (simulated) - scanning file allocation table...${RESET}" 0.006
  local total=120 files=0 i
  for i in $(seq 1 "$total"); do
    files=$((files + (RANDOM % 3)))
    printf "\r  Scanning: %3d%%   Files: %5d" $((i * 100 / total)) "$files"
    sleep 0.03
  done
  echo ""
  sleep 0.06
  type_slow "CHKDSK: 0 KB in bad sectors." 0.004
  type_slow "CHKDSK: 0 lost clusters found." 0.004
  bell
  echo ""
}

autoexec_sequence() {
  type_slow "${ACC}Loading CONFIG.SYS ...[OK]${RESET}" 0.004
  sleep 0.06
  type_slow "Loading AUTOEXEC.BAT ... [OK]" 0.004
  sleep 0.05

  if $LONG_HANDSHAKE; then
    floppy_activity 30
  else
    floppy_activity 16
  fi
  echo ""
  hdd_seek 18
  echo ""
  type_slow "${ACC}BOOT: MS-DOS style shell ready.${RESET}" 0.006
  bell
  echo ""
}

# ----------------- Run retro boot visuals -----------------
boot_post
chk_dsk_sim
autoexec_sequence

# ----------------- Git logic (keeps safety) -----------------
if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  echo -e "${ACC}ERROR: not inside a git repository${RESET}"
  exit 1
fi

CURRENT_BRANCH="$(git rev-parse --abbrev-ref HEAD 2>/dev/null || echo "main")"
PUSH_BRANCH="${TARGET_BRANCH:-$CURRENT_BRANCH}"

echo -e "${ACC}A:> DIR /W /P${RESET}"
safe_run "git status --short --branch"

echo ""
echo -e "${ACC}A:> STAGE ALL CHANGES${RESET}"
if $GIT_COMMIT_ALL; then
  echo -e "${ACC}  (will commit tracked changes with -a)${RESET}"
else
  safe_run "git add ."
fi

if git diff --cached --quiet && ! $GIT_COMMIT_ALL; then
  echo -e "${ACC}  No changes staged. System idle.${RESET}"
  echo ""
  echo -e "${ACC}C:\\> BASIC READY.${RESET}"
  echo -e "${ACC}10 PRINT \"NO CHANGES TO COMMIT\"${RESET}"
  echo -e "${ACC}20 GOTO 10${RESET}"
  sleep 0.3
  blink_cursor_line "${ACC}RUN${RESET}" 4
  exit 0
fi

if $INTERACTIVE; then
  echo -e "${ACC}--- STAGED DIFF PREVIEW ---${RESET}"
  git --no-pager diff --staged || true
  echo -e "${ACC}---------------------------${RESET}"
  if ! ask_yes_no "Proceed to commit?"; then
    echo "Aborted by user."
    exit 0
  fi
fi

COMMIT_OPTS=()
$SIGNOFF && COMMIT_OPTS+=(--signoff)

if $GIT_COMMIT_ALL; then
  COMMIT_CMD="git commit -a -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
else
  if git rev-parse --verify --quiet HEAD >/dev/null 2>&1; then
    COMMIT_CMD="git commit -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
  else
    COMMIT_CMD="git commit --allow-empty -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
  fi
fi

echo ""
echo -e "${ACC}PLANNED ACTIONS:${RESET}"
echo -e "  Commit command: ${COMMIT_CMD}"
if $DO_PUSH; then
  echo -e "  Push target: origin/${PUSH_BRANCH}"
else
  echo -e "  Push: (skipped)"
fi
echo ""

if $INTERACTIVE && ! $DRY_RUN; then
  if ! ask_yes_no "Really execute these actions?"; then
    echo "Cancelled."
    exit 0
  fi
fi

# run commit
safe_run "${COMMIT_CMD}"
COMMIT_HASH="$(git rev-parse --short HEAD 2>/dev/null || echo 'none')"
COMMIT_SUBJECT="$(git log -1 --pretty=format:%s 2>/dev/null || echo '')"

echo ""
echo -e "${ACC}A:> TYPE COMMIT.LOG${RESET}"
type_slow "${ACC}Last commit: ${COMMIT_HASH} - ${COMMIT_SUBJECT}${RESET}" 0.006
echo ""

# push if configured
if $DO_PUSH; then
  if git remote get-url origin >/dev/null 2>&1; then
    echo -e "${ACC}A:> PUSHDATA TO origin/${PUSH_BRANCH}${RESET}"
    safe_run "git push origin ${PUSH_BRANCH}"
    echo -e "${ACC}Transmission OK.${RESET}"
  else
    echo -e "${ACC}No 'origin' remote detected — push skipped.${RESET}"
  fi
else
  echo -e "${ACC}Push skipped (--no-push).${RESET}"
fi

echo ""
echo -e "${ACC}----------------------------------------${RESET}"
echo -e "${ACC}     MS-DOS / BASIC EMULATOR MODE      ${RESET}"
echo -e "${ACC}----------------------------------------${RESET}"
type_slow "${ACC}READY.${RESET}" 0.005
echo -e "${ACC}10 PRINT \"COMMIT: ${COMMIT_HASH} - ${COMMIT_SUBJECT}\"${RESET}"
echo -e "${ACC}20 END${RESET}"
echo ""
echo ""
crt_shutdown
exit 0
