!/usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail

THEME="${THEME:-amber}"
DRY_RUN=false
INTERACTIVE=false
DO_PUSH=true
GIT_COMMIT_ALL=false
SIGNOFF=false
TARGET_BRANCH=""
COMMIT_MSG=""

setup_colors() {
  local main_col
  case "$THEME" in
    green)  main_col="46" ;;
    blue)   main_col="39" ;;
    purple) main_col="135" ;;
    *)      main_col="214" ;;
  esac

  readonly C_MAIN="\033[38;5;${main_col}m"
  readonly C_DIM="\033[38;5;240m"
  readonly C_WHITE="\033[38;5;255m"
  readonly C_ERR="\033[38;5;196m"
  readonly C_OK="\033[38;5;154m"
  readonly RESET="\033[0m"
  readonly BOLD="\033[1m"
}

setup_colors

cls() { printf "\033[2J\033[H"; }

hr() {
  printf "%b%s%b\n" "$C_DIM" "------------------------------------------------------" "$RESET"
}

log_info() {
  local key="$1"
  local val="$2"
  printf "  %b%s%b %s\n" "$C_DIM" "::" "$C_MAIN" "$key"
  printf "     %b%s%b\n" "$C_WHITE" "$val" "$RESET"
}

run_step() {
  local desc="$1"
  shift
  local cmd=("$@")

  printf "  %b%s %-40s%b" "$C_MAIN" "⫸" "$desc" "$RESET"

  if [[ "$DRY_RUN" == "true" ]]; then
    printf "%b[ DRY ]%b\n" "$C_DIM" "$RESET"
    return 0
  fi

  local output
  if output=$("${cmd[@]}" 2>&1); then
    printf "%b[ OK ]%b\n" "$C_OK" "$RESET"
  else
    printf "%b[FAIL]%b\n" "$C_ERR" "$RESET"
    echo
    printf "%bError Details:%b\n%s\n" "$C_ERR" "$RESET" "$output"
    exit 1
  fi
}

ask_confirm() {
  echo
  printf "  %b?%b %s %b[y/N]%b " "$C_MAIN" "$RESET" "$1" "$C_DIM" "$RESET"
  read -r ans
  [[ "${ans,,}" =~ ^(y|yes)$ ]]
}

header() {
  cls
  echo
  printf "  %b%s%b\n" "$C_MAIN$BOLD" "GIT COMMANDER // SYSTEM v4.0" "$RESET"
  hr
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    -n|--no-push)    DO_PUSH=false; shift ;;
    -a|--all)        GIT_COMMIT_ALL=true; shift ;;
    -s|--signoff)    SIGNOFF=true; shift ;;
    -b|--branch)     TARGET_BRANCH="$2"; shift 2 ;;
    --dry-run)       DRY_RUN=true; shift ;;
    --interactive)   INTERACTIVE=true; shift ;;
    --theme)         THEME="$2"; setup_colors; shift 2 ;;
    -h|--help)       echo "Usage: $0 [options] 'message'"; exit 0 ;;
    --)              shift; break ;;
    -*)              echo "Unknown: $1"; exit 1 ;;
    *)               COMMIT_MSG="$*"; break ;;
  esac
done


[[ -z "${COMMIT_MSG// }" ]] && { printf "\n%b[!] Error: Commit message empty.%b\n" "$C_ERR" "$RESET"; exit 1; }
git rev-parse --is-inside-work-tree >/dev/null 2>&1 || { printf "\n%b[!] Error: Not a git repo.%b\n" "$C_ERR" "$RESET"; exit 1; }

CURRENT_BRANCH="$(git rev-parse --abbrev-ref HEAD 2>/dev/null || echo "HEAD")"
PUSH_BRANCH="${TARGET_BRANCH:-$CURRENT_BRANCH}"

header
log_info "COMMIT MESSAGE" "$COMMIT_MSG"
log_info "TARGET BRANCH"  "${C_MAIN}${CURRENT_BRANCH}${RESET} → origin/${PUSH_BRANCH}"
echo

if [[ "$GIT_COMMIT_ALL" == "true" ]]; then
  run_step "Verifying Status" git status --short
else
  if git diff --cached --quiet; then
    run_step "Staging Changes" git add .
  else
    run_step "Staging Changes" git add .
  fi
fi

if ! $GIT_COMMIT_ALL && git diff --cached --quiet; then
  printf "\n  %b[!] No changes to commit. System Idle.%b\n\n" "$C_DIM" "$RESET"
  exit 0
fi

if [[ "$INTERACTIVE" == "true" ]]; then
  hr
  git --no-pager diff --staged --stat | sed "s/^/    /"
  if ! ask_confirm "Proceed with commit?"; then
    echo "  Aborted."
    exit 0
  fi
  hr
fi

CMD_ARGS=("commit" "-m" "$COMMIT_MSG")
[[ "$GIT_COMMIT_ALL" == "true" ]] && CMD_ARGS+=("-a")
[[ "$SIGNOFF" == "true" ]]        && CMD_ARGS+=("--signoff")
! git rev-parse --verify --quiet HEAD >/dev/null 2>&1 && CMD_ARGS+=("--allow-empty")

run_step "Committing Data" git "${CMD_ARGS[@]}"

if [[ "$DO_PUSH" == "true" ]]; then
  if git remote get-url origin >/dev/null 2>&1; then
    run_step "Pushing to Origin" git push origin "$PUSH_BRANCH" --quiet
  else
    printf "  %b!%b  No remote detected. Push skipped.\n" "$C_MAIN" "$RESET"
  fi
fi

echo
SHORT_HASH="$(git rev-parse --short HEAD 2>/dev/null)"
printf "  %b SUCCESS%b  Hash: %b%s%b\n" "$C_OK" "$RESET" "$C_WHITE" "$SHORT_HASH" "$RESET"
hr
echo
