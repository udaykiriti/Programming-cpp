#!/usr/bin/env bash
# git_auto_ultra.sh — Ultra-nostalgic CRT + interactive git + dry-run + themes
# Features:
#   - themes: amber (default) or green
#   - flags: --no-push, --all, --signoff, --branch BR
#   - new: --dry-run, --interactive, --long-handshake, --theme
# Usage examples:
#   ./git_auto_ultra.sh "fix: small typo"
#   ./git_auto_ultra.sh --dry-run --interactive -a "feat: WIP"
#   THEME=green ./git_auto_ultra.sh --long-handshake "release: v1.2"
# Notes:
#   - set NO_BELL=1 in env to silence terminal bell
#   - interactive mode will prompt before committing/pushing

set -o errexit
set -o nounset
set -o pipefail

# ----- Configurable appearance -----
THEME="${THEME:-amber}"   # default theme; can be overridden with --theme
NO_BELL="${NO_BELL:-0}"   # set to 1 to silence bell
DRY_RUN=false
INTERACTIVE=false
LONG_HANDSHAKE=false

# ----- State defaults -----
DO_PUSH=true
GIT_COMMIT_ALL=false
SIGNOFF=false
TARGET_BRANCH=""
COMMIT_MSG=""

# ----- Colors (ANSI) -----
AMP="\e[33m"  # amber
GRN="\e[32m"
DIM="\e[2m"
BRIGHT="\e[1m"
RESET="\e[0m"
BLINK="\e[5m"
CLS="\e[2J\e[H"

# choose colors based on theme
if [[ "$THEME" == "green" ]]; then
  ACC="$GRN"
else
  ACC="$AMP"
fi

# ----- Helpers -----
bell() {
  [[ "$NO_BELL" == "1" ]] && return
  printf "\a"
}

# safe runner that respects dry-run
safe_run() {
  local cmd="$*"
  echo -e "${ACC}>>> ${cmd}${RESET}"
  if $DRY_RUN; then
    echo -e "${ACC} (dry-run) command not executed${RESET}"
    return 0
  fi
  if ! eval "${cmd}"; then
    echo -e "${ACC}!!! ERROR running: ${cmd}${RESET}"
    exit 1
  fi
}

# prompt yes/no (returns 0 for yes)
ask_yes_no() {
  local prompt="$1"
  local ans
  while true; do
    read -r -p "${prompt} [y/n] " ans
    case "${ans,,}" in
      y|yes) return 0 ;;
      n|no) return 1 ;;
      *) echo "Please answer y or n." ;;
    esac
  done
}

# Usage
usage() {
  cat <<EOF
Usage: $0 [options] "commit message"
Options:
  -n, --no-push        Do not push to remote (local-only)
  -a, --all            Commit tracked files (git commit -a)
  -s, --signoff        Add --signoff to commit
  -b, --branch BR      Push to BR instead of detected branch
      --dry-run        Print actions but do not execute git commands
      --interactive    Show staged diff and confirm before commit/push
      --long-handshake Longer retro modem handshake animation
      --theme THEME    Theme: amber (default) or green
  -h, --help           Show this help
Env:
  NO_BELL=1            Suppress audible bell
EOF
  exit 1
}

# ----- argument parsing -----
while [[ $# -gt 0 ]]; do
  case "$1" in
    -n|--no-push) DO_PUSH=false; shift ;;
    -a|--all) GIT_COMMIT_ALL=true; shift ;;
    -s|--signoff) SIGNOFF=true; shift ;;
    -b|--branch)
      if [[ -z "${2:-}" ]]; then echo "Missing branch name"; usage; fi
      TARGET_BRANCH="$2"; shift 2 ;;
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
  echo -e "${ACC}ERROR: missing commit message${RESET}"
  usage
fi

# ----- ASCII art + small visuals -----
big_logo() {
  cat <<'EOF'
██████╗ ██████╗ ████████╗████████╗
██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝
██████╔╝██████╔╝   ██║      ██║
██╔═══╝ ██╔══██╗   ██║      ██║
██║     ██║  ██║   ██║      ██║
╚═╝     ╚═╝  ╚═╝   ╚═╝      ╚═╝
EOF
}

type_slow() {
  local s="$1" delay="${2:-0.01}"
  local i
  for ((i=0; i<${#s}; i++)); do
    printf "%s" "${s:i:1}"
    sleep "$delay"
  done
  printf "\n"
}

progress_bar() {
  local len=${1:-36}
  local speed=${2:-0.013}
  printf "["
  for i in $(seq 1 $len); do
    printf "%b" "${ACC}#${RESET}"
    sleep "$speed"
  done
  printf "]\n"
}

modem_handshake_short() {
  local steps=( "DIAL" "SYN" "ACK" "CONNECT" )
  for s in "${steps[@]}"; do
    printf "  [MODEM] %s..." "$s"
    sleep 0.14
    printf " %bOK%b\n" "$ACC" "$RESET"
  done
  bell
}

modem_handshake_long() {
  echo "  [MODEM] LONG HANDSHAKE: dialing..."
  for n in {1..6}; do
    printf "   ~%s" "$(printf '=%.0s' $(seq 1 $n))"
    sleep 0.12
  done
  echo ""
  for tone in 1 2 3 4 5 6 7; do
    printf "   TONE-%d " "$tone"
    sleep 0.1
    printf "%bOK%b\n" "$ACC" "$RESET"
  done
  bell
}

# ----- start visuals -----
printf "%b" "${CLS}"
echo -e "${ACC}${BRIGHT}"
big_logo
echo -e "${RESET}"
type_slow "${ACC}RTS SYSTEMS — GIT AUTO ULTRA${RESET}" 0.009
sleep 0.06

type_slow "POWER ON SELF TEST (POST) — running..." 0.007
progress_bar 28 0.009
sleep 0.06
if $LONG_HANDSHAKE; then modem_handshake_long; else modem_handshake_short; fi
type_slow "${ACC}POST COMPLETE${RESET}" 0.006
echo ""

# ----- git environment checks -----
if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  echo -e "${ACC}ERROR: not inside a git repository${RESET}"
  exit 1
fi

CURRENT_BRANCH="$(git rev-parse --abbrev-ref HEAD 2>/dev/null || echo "main")"
PUSH_BRANCH="${TARGET_BRANCH:-$CURRENT_BRANCH}"

echo -e "${ACC}>> REPOSITORY STATUS${RESET}"
safe_run "git status --short --branch"

echo ""
echo -e "${ACC}>> STAGING CHANGES${RESET}"
if $GIT_COMMIT_ALL; then
  echo -e "${ACC}  (will commit tracked files with -a)${RESET}"
else
  safe_run "git add ."
fi

# nothing to commit check
if git diff --cached --quiet && ! $GIT_COMMIT_ALL; then
  echo -e "${ACC}  No changes staged. System idle.${RESET}"
  exit 0
fi

# interactive preview if requested
if $INTERACTIVE; then
  echo -e ""
  echo -e "${ACC}--- STAGED DIFF (preview) ---${RESET}"
  git --no-pager diff --staged || true
  echo -e "${ACC}-----------------------------${RESET}"
  if ! ask_yes_no "Proceed to commit?"; then
    echo "Aborted by user. No commit performed."
    exit 0
  fi
fi

# prepare commit command
COMMIT_OPTS=()
$SIGNOFF && COMMIT_OPTS+=(--signoff)
COMMIT_CMD=""
if $GIT_COMMIT_ALL; then
  COMMIT_CMD="git commit -a -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
else
  # if there's no HEAD (initial commit), allow empty or normal commit depending
  if git rev-parse --verify --quiet HEAD >/dev/null 2>&1; then
    COMMIT_CMD="git commit -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
  else
    COMMIT_CMD="git commit --allow-empty -m \"${COMMIT_MSG//\"/\\\"}\" ${COMMIT_OPTS[*]:-}"
  fi
fi

# show what will happen (helpful in dry-run)
echo ""
echo -e "${ACC}>> ABOUT TO RUN${RESET}"
echo -e "  Commit command: ${COMMIT_CMD}"
if $DO_PUSH; then
  echo -e "  Push target   : origin/${PUSH_BRANCH}"
else
  echo -e "  Push          : (skipped)"
fi
echo ""

# final confirmation in interactive mode
if $INTERACTIVE && ! $DRY_RUN; then
  if ! ask_yes_no "Really run the above actions?"; then
    echo "Cancelled by user."
    exit 0
  fi
fi

# execute commit
safe_run "${COMMIT_CMD}"

# commit summary (short)
echo ""
echo -e "${ACC}>> COMMIT SUMMARY${RESET}"
git --no-pager log -1 --pretty=format:"%C(yellow)%h %C(green)%cr %C(reset)%s"
echo ""

# push if allowed
if $DO_PUSH; then
  if git remote get-url origin >/dev/null 2>&1; then
    echo -e "${ACC}>> PUSHING TO origin/${PUSH_BRANCH}${RESET}"
    if $DRY_RUN; then
      echo -e "${ACC}(dry-run) git push origin ${PUSH_BRANCH}${RESET}"
    else
      safe_run "git push origin ${PUSH_BRANCH}"
    fi
  else
    echo -e "${ACC}>> No 'origin' remote configured; push skipped.${RESET}"
  fi
else
  echo -e "${ACC}>> Push skipped (--no-push).${RESET}"
fi

# polished finish + final mini animation
echo ""
type_slow "${ACC}TRANSACTION COMPLETE — SYSTEM IDLE${RESET}" 0.01
progress_bar 22 0.01
bell

# small commit stats if not dry-run
if ! $DRY_RUN; then
  echo ""
  echo -e "${ACC}>>> DIFFSTAT (last commit)${RESET}"
  git --no-pager show --stat --oneline -1 || true
fi

# gentle exit sparkle
for i in 1 3; do
  printf "%b" "${CLS}"
  echo -e "${ACC}${BRIGHT}  * retro shimmer *${RESET}"
  sleep 0.12
done

echo -e "${ACC}Goodnight, and good luck.${RESET}"
exit 0
