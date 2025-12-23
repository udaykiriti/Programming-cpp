#!/usr/bin/env bash

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

AMP=$'\033[33m'
GRN=$'\033[32m'
DIM=$'\033[2m'
BRIGHT=$'\033[1m'
RESET=$'\033[0m'
BLINK=$'\033[5m'
CLS=$'\033[2J\033[H'

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
  printf "%b>>> %s%b\n" "$ACC" "$cmd" "$RESET"
  if $DRY_RUN; then
    printf "%b(dry-run) not executed%b\n" "$ACC" "$RESET"
    return 0
  fi
  if ! eval "${cmd}"; then
    printf "%b!!! ERROR running: %s%b\n" "$ACC" "$cmd" "$RESET"
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

# Instant output instead of slow typing
type_slow() {
  printf "%s\n" "$1"
}

# Simplified/Removed slow functions
progress_bar() { :; }
hdd_seek() { :; }
floppy_activity() { :; }
crt_warmup() { :; }
crt_shutdown() {
  echo -e "${ACC}${BRIGHT}SYSTEM HALT.${RESET}"
}

blink_cursor_line() {
  printf "\r%s%s_\n" "$1" "$ACC"
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

# --- parse args ---
while [[ $# -gt 0 ]]; do
  case "$1" in
    -n|--no-push) DO_PUSH=false; shift ;;
    -a|--all) GIT_COMMIT_ALL=true; shift ;;
    -s|--signoff) SIGNOFF=true; shift ;;
    -b|--branch)
      if [[ -z "${2:-}" ]]; then echo "Missing branch name"; usage; fi
      TARGET_BRANCH="$2"; shift 2
      ;;
    --dry-run) DRY_RUN=true; shift ;;
    --interactive) INTERACTIVE=true; shift ;;
    --long-handshake) LONG_HANDSHAKE=true; shift ;;
    --theme)
      if [[ -z "${2:-}" ]]; then echo "Missing theme"; usage; fi
      THEME="$2"; shift 2
      if [[ "$THEME" == "green" ]]; then ACC="$GRN"; else ACC="$AMP"; fi
      ;;
    -h|--help) usage ;;
    --) shift; break ;;
    -*) echo "Unknown option: $1"; usage ;;
    *) COMMIT_MSG="$*"; break ;;
  esac
done

if [[ -z "${COMMIT_MSG// }" ]]; then
  printf "%bERROR: missing commit message%b\n" "$ACC" "$RESET"
  usage
fi

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
  printf "%b" "$CLS"
  printf "%b" "${ACC}${BRIGHT}"
  pc_ascii
  printf "%b\n" "${RESET}"
  type_slow "IBM PC/XT BIOS v4.10  1986 (C) REALTECH"
  type_slow "Performing Power-On Self Test (POST)... OK"
}

chk_dsk_sim() { :; }

autoexec_sequence() {
  type_slow "${ACC}Loading CONFIG.SYS ...[OK]${RESET}"
  type_slow "Loading AUTOEXEC.BAT ... [OK]"
  type_slow "${ACC}BOOT: MS-DOS style shell ready.${RESET}"
}

boot_post
chk_dsk_sim
autoexec_sequence

if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  echo -e "${ACC}ERROR: not inside a git repository${RESET}"
  exit 1
fi

CURRENTBRANCH="$(git rev-parse --abbrev-ref HEAD 2>/dev/null || echo "main")"
PUSH_BRANCH="${TARGET_BRANCH:-$CURRENTBRANCH}"

echo -e "${ACC}A:> DIR /W /P${RESET}"
safe_run "git status --short --branch"

printf "\n"
echo -e "${ACC}A:> STAGE ALL CHANGES${RESET}"
if $GIT_COMMIT_ALL; then
  echo -e "${ACC}  (will commit tracked changes with -a)${RESET}"
else
  safe_run "git add ."
fi

if git diff --cached --quiet && ! $GIT_COMMIT_ALL; then
  echo -e "${ACC}  No changes staged. System idle.${RESET}"
  printf "\n"
  echo -e "${ACC}C:\\> BASIC READY.${RESET}"
  echo -e "${ACC}10 PRINT \"NO CHANGES TO COMMIT\"${RESET}"
  echo -e "${ACC}20 GOTO 10${RESET}"
  blink_cursor_line "${ACC}RUN${RESET}"
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

printf "\n"
echo -e "${ACC}PLANNED ACTIONS:${RESET}"
echo -e "  Commit command: ${COMMIT_CMD}"
if $DO_PUSH; then
  echo -e "  Push target: origin/${PUSH_BRANCH}"
else
  echo -e "  Push: (skipped)"
fi
printf "\n"

if $INTERACTIVE && ! $DRY_RUN; then
  if ! ask_yes_no "Really execute these actions?"; then
    echo "Cancelled."
    exit 0
  fi
fi

safe_run "${COMMIT_CMD}"
COMMIT_HASH="$(git rev-parse --short HEAD 2>/dev/null || echo 'none')"
COMMIT_SUBJECT="$(git log -1 --pretty=format:%s 2>/dev/null || echo '')"

printf "\n"
echo -e "${ACC}A:> TYPE COMMIT.LOG${RESET}"
type_slow "${ACC}Last commit: ${COMMIT_HASH} - ${COMMIT_SUBJECT}${RESET}"

if $DO_PUSH; then
  if git remote get-url origin >/dev/null 2>&1; then
    echo -e "${ACC}A:> PUSHDATA TO origin/${PUSH_BRANCH}${RESET}"
    safe_run "git push origin ${PUSH_BRANCH}"
  else
    echo -e "${ACC}No 'origin' remote detected — push skipped.${RESET}"
  fi
fi

printf "\n"
echo -e "${ACC}----------------------------------------${RESET}"
echo -e "${ACC}     MS-DOS / BASIC EMULATOR MODE      ${RESET}"
echo -e "${ACC}----------------------------------------${RESET}"
type_slow "${ACC}READY.${RESET}"
echo -e "${ACC}10 PRINT \"COMMIT: ${COMMIT_HASH} - ${COMMIT_SUBJECT}\"${RESET}"
echo -e "${ACC}20 END${RESET}"
crt_shutdown
exit 0
