#!/usr/bin/env bash

# Strict mode
set -o errexit
set -o nounset
set -o pipefail

#  THEME & CONSTANTS

# Configuration Defaults
THEME="${THEME:-amber}"
NO_BELL="${NO_BELL:-0}"
DRY_RUN=false
INTERACTIVE=false
DO_PUSH=true
GIT_COMMIT_ALL=false
SIGNOFF=false
TARGET_BRANCH=""
COMMIT_MSG=""

# Visual Assets
readonly CLS=$'\033[2J\033[H'
readonly RESET=$'\033[0m'
readonly BOLD=$'\033[1m'
readonly DIM=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly BLINK=$'\033[5m'

# Palette Definition
if [[ "$THEME" == "green" ]]; then
  readonly MAIN=$'\033[38;5;46m'   # Bright Green
  readonly DARK=$'\033[38;5;22m'   # Dark Green
  readonly ACC=$'\033[38;5;154m'   # Yellow-Green
  readonly ERR=$'\033[38;5;196m'   # Red
else
  # Amber / Fallout Theme
  readonly MAIN=$'\033[38;5;214m'  # Amber
  readonly DARK=$'\033[38;5;94m'   # Dark Orange/Brown
  readonly ACC=$'\033[38;5;226m'   # Bright Yellow
  readonly ERR=$'\033[38;5;196m'   # Red
fi

# Box Drawing Characters
TL="╔"; TR="╗"; BL="╚"; BR="╝"; H="═"; V="║"
T_R="╠"; T_L="╣"; CROSS="╬"

#  UI & UTILITY FUNCTIONS

usage() {
  cat <<EOF
Usage: $(basename "$0") [options] "commit message"
EOF
  exit 1
}

# Draw a horizontal line
hr() {
  printf "%b%s%b\n" "$DARK" "$(printf '%*s' 60 | tr ' ' "$H")" "$RESET"
}

# Print a boxed header
header() {
  local title=" $1 "
  local len=${#title}
  local pad=$(( (58 - len) / 2 ))

  echo
  printf "%b%s%b\n" "$MAIN" "$(printf '%*s' 60 | tr ' ' "$H")" "$RESET"
  printf "%b%s%s%s%s%b\n" "$MAIN" "$V" "$(printf '%*s' $pad)" "$ACC$BOLD$title$RESET$MAIN" "$(printf '%*s' $pad)" "$V" "$RESET"
  printf "%b%s%b\n" "$MAIN" "$(printf '%*s' 60 | tr ' ' "$H")" "$RESET"
}

# Print a key-value pair aligned nicely
info_row() {
  local key="$1"
  local val="$2"
  printf "%b %s %-15s %b%s%b\n" "$DARK$V$RESET" "$ACC" "$key" "$MAIN" "$val" "$RESET"
}

# Status indicator
status_msg() {
  local icon="$1"
  local msg="$2"
  printf " %b[%s]%b %s\n" "$ACC" "$icon" "$RESET" "$msg"
}

run_cmd() {
  local cmd_name="$1"
  shift
  local cmd_args=("$@")

  if [[ "$DRY_RUN" == "true" ]]; then
    printf " %b[DRY]%b %s %s\n" "$DIM" "$RESET" "$cmd_name" "${cmd_args[*]}"
    return 0
  fi
  "$cmd_name" "${cmd_args[@]}"
}

ask_confirm() {
  echo
  printf "%b %s%b %s [y/n] " "$ACC" "?" "$RESET" "$1"
  read -r ans
  [[ "${ans,,}" =~ ^(y|yes)$ ]]
}

#  MAIN LOGIC

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

# 2. Pre-flight Checks
if [[ -z "${COMMIT_MSG// }" ]]; then
  printf "\n%b [!] SYSTEM ERROR: Commit message empty.%b\n\n" "$ERR" "$RESET"
  exit 1
fi

if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  printf "\n%b [!] SYSTEM ERROR: Git repository not found.%b\n\n" "$ERR" "$RESET"
  exit 1
fi

# 3. Initialize Interface
printf "%b" "$CLS"
header "GIT COMMANDER v3.0"

# Detect Branch
CURRENT_BRANCH="$(git rev-parse --abbrev-ref HEAD 2>/dev/null || echo "HEAD")"
PUSH_BRANCH="${TARGET_BRANCH:-$CURRENT_BRANCH}"

# Display Diagnostics
info_row "BRANCH"   "$CURRENT_BRANCH"
info_row "TARGET"   "origin/$PUSH_BRANCH"
info_row "MODE"     "$([ "$GIT_COMMIT_ALL" = true ] && echo "COMMIT-ALL (-a)" || echo "STANDARD")"
if $DO_PUSH; then
  info_row "UPLINK"   "ACTIVE"
else
  info_row "UPLINK"   "OFFLINE (Local Only)"
fi
hr

# 4. Status Check
echo
status_msg "i" "Scanning working directory..."
# Get status, indent it, colorize minimal output
STATUS_OUT=$(git status --short --branch)

if [[ -z "$STATUS_OUT" ]]; then
   status_msg "!" "No changes detected."
else
   # Print status with a little margin
   printf "%b%s%b\n" "$DIM" "$(echo "$STATUS_OUT" | sed 's/^/   /')" "$RESET"
fi

# 5. Staging
if [[ "$GIT_COMMIT_ALL" == "true" ]]; then
  : # No add needed
else
  status_msg "+" "Staging all changes..."
  run_cmd git add .
fi

# 6. Safety Check
if ! $GIT_COMMIT_ALL && git diff --cached --quiet; then
  echo
  printf "%b %s %b\n" "$ERR" ">>> ABORT: NO CHANGES STAGED <<<" "$RESET"
  hr
  exit 0
fi

# 7. Interactive Mode
if [[ "$INTERACTIVE" == "true" ]]; then
  echo
  hr
  printf "%b  REVIEW CHANGES %b\n" "$ACC" "$RESET"
  hr
  git --no-pager diff --staged --stat | sed "s/^/  /"
  echo
  if ! ask_confirm "Execute commit procedures?"; then
    echo "  Aborted."
    exit 0
  fi
  echo
fi

# 8. Commit
COMMIT_ARGS=("commit" "-m" "$COMMIT_MSG")
[[ "$GIT_COMMIT_ALL" == "true" ]] && COMMIT_ARGS+=("-a")
[[ "$SIGNOFF" == "true" ]]        && COMMIT_ARGS+=("--signoff")
! git rev-parse --verify --quiet HEAD >/dev/null 2>&1 && COMMIT_ARGS+=("--allow-empty")

status_msg ">" "Committing data..."
run_cmd git "${COMMIT_ARGS[@]}" > /dev/null

# Get new hash
NEW_HASH=$(git rev-parse --short HEAD 2>/dev/null || echo "????")
status_msg "OK" "Commit confirmed: $ACC$NEW_HASH$RESET"

# 9. Push
if [[ "$DO_PUSH" == "true" ]]; then
  if git remote get-url origin >/dev/null 2>&1; then
    status_msg "^" "Pushing to remote..."
    if run_cmd git push origin "$PUSH_BRANCH" --quiet; then
      status_msg "OK" "Remote updated successfully."
    else
      status_msg "!!" "Push failed."
      exit 1
    fi
  else
    status_msg "!" "No remote found. Push skipped."
  fi
fi

# 10. Footer
echo
printf "%b%s%b\n" "$MAIN" "$(printf '%*s' 60 | tr ' ' "$H")" "$RESET"
printf "%b%s%b\n" "$MAIN" "  SYSTEM HALT. OPERATION SUCCESSFUL." "$RESET"
echo
