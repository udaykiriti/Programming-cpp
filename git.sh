#!/usr/bin/env bash

set -euo pipefail

COLOR_THEME="${COLOR_THEME:-amber}"

FLAG_DRY_RUN=false
FLAG_INTERACTIVE=false
FLAG_PUSH=true
FLAG_COMMIT_ALL=false
FLAG_SIGNOFF=false

TARGET_BRANCH=""
COMMIT_MESSAGE=""

supports_color() {
  [[ -t 1 ]] && [[ "${TERM:-}" != "dumb" ]]
}

init_colors() {
  local primary_color

  case "$COLOR_THEME" in
    green)  primary_color="46" ;;
    blue)   primary_color="39" ;;
    purple) primary_color="135" ;;
    *)      primary_color="214" ;; 
  esac

  COLOR_PRIMARY="\033[38;5;${primary_color}m"
  COLOR_DIM="\033[38;5;240m"
  COLOR_TEXT="\033[38;5;255m"
  COLOR_ERROR="\033[38;5;196m"
  COLOR_SUCCESS="\033[38;5;154m"
  COLOR_RESET="\033[0m"
  COLOR_BOLD="\033[1m"
}

if supports_color; then
  init_colors
else
  COLOR_PRIMARY=""
  COLOR_DIM=""
  COLOR_TEXT=""
  COLOR_ERROR=""
  COLOR_SUCCESS=""
  COLOR_RESET=""
  COLOR_BOLD=""
fi

clear_screen() {
  printf "\033[2J\033[H"
}

print_divider() {
  printf "%b%s%b\n" "$COLOR_DIM" "------------------------------------------------------" "$COLOR_RESET"
}

print_info() {
  local label="$1"
  local value="$2"

  printf "  %b::%b %s\n" "$COLOR_DIM" "$COLOR_RESET" "$label"
  printf "     %b%b%b\n" "$COLOR_TEXT" "$value" "$COLOR_RESET"
}

print_header() {
  clear_screen
  echo
  printf "  %b%s%b\n" "$COLOR_PRIMARY$COLOR_BOLD" "GIT COMMANDER // SYSTEM v4.0" "$COLOR_RESET"
  print_divider
}

confirm_action() {
  echo
  printf "  %b?%b %s %b[y/N]%b " \
    "$COLOR_PRIMARY" "$COLOR_RESET" "$1" "$COLOR_DIM" "$COLOR_RESET"
  read -r reply
  [[ "${reply,,}" =~ ^(y|yes)$ ]]
}

run_step() {
  local description="$1"
  shift
  local command=("$@")

  printf "  %b⫸ %-40s%b" "$COLOR_PRIMARY" "$description" "$COLOR_RESET"

  if $FLAG_DRY_RUN; then
    printf "%b[ DRY ]%b\n" "$COLOR_DIM" "$COLOR_RESET"
    return 0
  fi

  if output=$("${command[@]}" 2>&1); then
    printf "%b[ OK ]%b\n" "$COLOR_SUCCESS" "$COLOR_RESET"
  else
    printf "%b[FAIL]%b\n\n%bError:%b\n%s\n" \
      "$COLOR_ERROR" "$COLOR_RESET" \
      "$COLOR_ERROR" "$COLOR_RESET" \
      "$output"
    exit 1
  fi
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    -n|--no-push)        FLAG_PUSH=false; shift ;;
    -a|--all)            FLAG_COMMIT_ALL=true; shift ;;
    -s|--signoff)        FLAG_SIGNOFF=true; shift ;;
    -b|--branch)         TARGET_BRANCH="$2"; shift 2 ;;
    --dry-run)           FLAG_DRY_RUN=true; shift ;;
    --interactive)       FLAG_INTERACTIVE=true; shift ;;
    --theme)
      COLOR_THEME="$2"
      supports_color && init_colors
      shift 2
      ;;
    -h|--help)
      echo "Usage: $0 [options] \"commit message\""
      exit 0
      ;;
    --) shift; break ;;
    -*) echo "Unknown option: $1"; exit 1 ;;
    *)  COMMIT_MESSAGE="$*"; break ;;
  esac
done

[[ -z "${COMMIT_MESSAGE// }" ]] && {
  printf "\n%b[!] Commit message cannot be empty.%b\n" "$COLOR_ERROR" "$COLOR_RESET"
  exit 1
}

git rev-parse --is-inside-work-tree >/dev/null 2>&1 || {
  printf "\n%b[!] Not inside a Git repository.%b\n" "$COLOR_ERROR" "$COLOR_RESET"
  exit 1
}

CURRENT_BRANCH="$(git rev-parse --abbrev-ref HEAD)"
PUSH_TARGET_BRANCH="${TARGET_BRANCH:-$CURRENT_BRANCH}"

print_header
print_info "[Commit]: Message" "$COMMIT_MESSAGE"
print_info "Target Branch" "${COLOR_PRIMARY}${CURRENT_BRANCH}${COLOR_RESET} → origin/${PUSH_TARGET_BRANCH}"
echo

run_step "Staging Changes" git add .

if ! $FLAG_COMMIT_ALL && git diff --cached --quiet; then
  printf "\n  %b[!] No staged changes. Nothing to commit.%b\n\n" "$COLOR_DIM" "$COLOR_RESET"
  exit 0
fi

if $FLAG_INTERACTIVE; then
  print_divider
  git --no-pager diff --staged --stat | sed "s/^/    /"
  confirm_action "Proceed with commit?" || exit 0
  print_divider
fi

GIT_COMMIT_ARGS=("commit" "-m" "$COMMIT_MESSAGE")
$FLAG_COMMIT_ALL && GIT_COMMIT_ARGS+=("-a")
$FLAG_SIGNOFF   && GIT_COMMIT_ARGS+=("--signoff")
git rev-parse --verify --quiet HEAD >/dev/null 2>&1 || GIT_COMMIT_ARGS+=("--allow-empty")

run_step "[Hold]: Creating Commit" git "${GIT_COMMIT_ARGS[@]}"

if $FLAG_PUSH && git remote get-url origin >/dev/null 2>&1; then
  run_step "[Wait]: Pushing to Origin" git push origin "$PUSH_TARGET_BRANCH" --quiet
fi

echo
SHORT_COMMIT_HASH="$(git rev-parse --short HEAD)"
printf "  %b[DONE]%b  Commit: %b%s%b\n" \
  "$COLOR_SUCCESS" "$COLOR_RESET" \
  "$COLOR_TEXT" "$SHORT_COMMIT_HASH" "$COLOR_RESET"

print_divider
echo
