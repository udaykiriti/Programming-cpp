#!/usr/bin/env bash

# Strict mode: exit on error, undefined vars, or pipe failures
set -o errexit
set -o nounset
set -o pipefail

# CONFIGURATION

# Defaults
THEME="${THEME:-amber}"
NO_BELL="${NO_BELL:-0}"
DRY_RUN=false
INTERACTIVE=false
DO_PUSH=true
GIT_COMMIT_ALL=false
SIGNOFF=false
TARGET_BRANCH=""
COMMIT_MSG=""

# Colors (ANSI)
readonly CLS=$'\033[2J\033[H'
readonly RESET=$'\033[0m'
readonly BOLD=$'\033[1m'
readonly DIM=$'\033[2m'
readonly RED=$'\033[31m'

# Theme Selection
if [[ "$THEME" == "green" ]]; then
  readonly ACC=$'\033[32m' # Green Phosphor
else
  readonly ACC=$'\033[33m' # Amber Phosphor
fi

# UTILITY FUNCTIONS

usage() {
  cat <<EOF
Usage: $(basename "$0") [options] "commit message"

Options:
  -n, --no-push       Local commit only (no push)
  -a, --all           Stage all tracked files (git commit -a)
  -s, --signoff       Add --signoff trailer
  -b, --branch BR     Target specific branch
      --dry-run       Simulate actions
      --interactive   Review diffs before committing
      --theme COLOR   'amber' or 'green'
  -h, --help          Show this help
EOF
  exit 1
}

log() {
  printf "%b%s%b\n" "$ACC" "$1" "$RESET"
}

run_cmd() {
  local cmd_name="$1"
  shift
  local cmd_args=("$@")

  # Minimal output for speed, unless dry-run
  if [[ "$DRY_RUN" == "true" ]]; then
    printf "%b[DRY-RUN] %s %s%b\n" "$DIM" "$cmd_name" "${cmd_args[*]}" "$RESET"
    return 0
  fi

  "$cmd_name" "${cmd_args[@]}"
}

ask_confirm() {
  local prompt="$1"
  local ans
  while true; do
    read -r -p "${ACC}${prompt} [y/n] ${RESET}" ans
    case "${ans,,}" in
      y|yes) return 0 ;;
      n|no)  return 1 ;;
      *)     ;;
    esac
  done
}

# VISUALS

show_art() {
  # 3.5" Floppy Disk ASCII Art
  printf "%b" "$ACC"
  cat <<'EOF'
    _________________
   /  _____________  \   GIT COMMANDER v2.0
  /  / |  _   _  | \  \  ------------------
  |  | | |_| |_| | |  |  [A:] MEMORY CHECK OK
  |  | |_________| |  |  [B:] REPO FOUND
  |  |_____________|  |
  |  ________________ |
  | |  _    ___    | ||
  | | | \  / _ \   | ||
  | | |_/ | (_) |  | ||
  | |_____ \___/___| ||
  \___________________/
EOF
  printf "%b\n" "$RESET"
}

# MAIN LOGIC

# 1. Parse Arguments
while [[ $# -gt 0 ]]; do
  case "$1" in
    -n|--no-push)    DO_PUSH=false; shift ;;
    -a|--all)        GIT_COMMIT_ALL=true; shift ;;
    -s|--signoff)    SIGNOFF=true; shift ;;
    -b|--branch)     TARGET_BRANCH="$2"; shift 2 ;;
    --dry-run)       DRY_RUN=true; shift ;;
    --interactive)   INTERACTIVE=true; shift ;;
    --theme)         THEME="$2"; shift 2 ;;
    -h|--help)       usage ;;
    --)              shift; break ;;
    -*)              echo "Unknown: $1"; usage ;;
    *)               COMMIT_MSG="$*"; break ;;
  esac
done

# 2. Validation
if [[ -z "${COMMIT_MSG// }" ]]; then
  printf "%b[!] ERROR: Commit message required.%b\n" "$RED" "$RESET"
  usage
fi

if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  printf "%b[!] ERROR: Not a git repository.%b\n" "$RED" "$RESET"
  exit 1
fi

# 3. Execution Start
clear
show_art

CURRENT_BRANCH="$(git rev-parse --abbrev-ref HEAD 2>/dev/null || echo "HEAD")"
PUSH_BRANCH="${TARGET_BRANCH:-$CURRENT_BRANCH}"

# Status Check (Compact)
printf "%b>> STATUS CHECK:%b\n" "$ACC" "$RESET"
run_cmd git status --short --branch

# Staging
if [[ "$GIT_COMMIT_ALL" == "true" ]]; then
  printf "\n%b>> MODE: COMMIT ALL TRACKED%b\n" "$ACC" "$RESET"
else
  run_cmd git add .
fi

# Empty Check
if ! $GIT_COMMIT_ALL && git diff --cached --quiet; then
  printf "\n%b[!] NO CHANGES STAGED. ABORTING.%b\n" "$RED" "$RESET"
  exit 0
fi

# Interactive Review
if [[ "$INTERACTIVE" == "true" ]]; then
  echo
  git --no-pager diff --staged --stat
  echo
  if ! ask_confirm "Proceed?"; then
    echo "Aborted."
    exit 0
  fi
fi

# Build Command
COMMIT_ARGS=("commit" "-m" "$COMMIT_MSG")
[[ "$GIT_COMMIT_ALL" == "true" ]] && COMMIT_ARGS+=("-a")
[[ "$SIGNOFF" == "true" ]]        && COMMIT_ARGS+=("--signoff")
# Handle empty initial commits
! git rev-parse --verify --quiet HEAD >/dev/null 2>&1 && COMMIT_ARGS+=("--allow-empty")

# Commit
printf "\n%b>> EXECUTING COMMIT...%b\n" "$ACC" "$RESET"
run_cmd git "${COMMIT_ARGS[@]}"

# Push
if [[ "$DO_PUSH" == "true" ]]; then
  if git remote get-url origin >/dev/null 2>&1; then
    printf "\n%b>> PUSHING TO origin/%s...%b\n" "$ACC" "$PUSH_BRANCH" "$RESET"
    run_cmd git push origin "$PUSH_BRANCH"
  else
    printf "\n%b[!] NO REMOTE. PUSH SKIPPED.%b\n" "$DIM" "$RESET"
  fi
fi

# Quick Exit
printf "\n%b>> OPERATION COMPLETE. SYSTEM HALT.%b\n" "$ACC" "$RESET"
exit 0
