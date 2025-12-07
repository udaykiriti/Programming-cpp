#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

# Retro compile-run script with "old compiler" animation
# Usage: ./sol.sh [-s source.cpp] [-i in.txt] [-o out.txt] [-c compiler] [-f "extra flags"] [source.cpp]

# --------- Defaults ----------
SRC=""
INFILE="in.txt"
OUTFILE="out.txt"
COMPILER="g++"
CXXFLAGS=( -std=c++20 -O2 -Wall -Wextra -DLOCAL )
TIMESTAMP=true

# --------- Colors (if tty) ----------
if [[ -t 1 ]]; then
  RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[0;33m'
  BLUE='\033[0;34m'; MAGENTA='\033[0;35m'; CYAN='\033[0;36m'
  BOLD='\033[1m'; NC='\033[0m'
else
  RED='' ; GREEN='' ; YELLOW='' ; BLUE='' ; MAGENTA='' ; CYAN='' ; BOLD='' ; NC=''
fi

usage() {
  cat <<EOF
Usage: $0 [-s source.cpp] [-i in.txt] [-o out.txt] [-c compiler] [-f "extra flags"] [source.cpp]
Example: $0 -s solution.cpp -i sample.in -o sample.out -f "-g -O0"
EOF
}

log()  { printf "%b\n" "${BLUE}>>${NC} $*"; }
ok()   { printf "%b\n" "${GREEN}✔${NC} $*"; }
err()  { printf "%b\n" "${RED}✖ ${NC}$*" >&2; }

# --------- Parse flags ----------
while getopts ":s:i:o:c:f:th" opt; do
  case "$opt" in
    s) SRC="$OPTARG" ;;
    i) INFILE="$OPTARG" ;;
    o) OUTFILE="$OPTARG" ;;
    c) COMPILER="$OPTARG" ;;
    f) # split provided string into words and append
       # shellcheck disable=SC2206
       CXXFLAGS+=( $OPTARG )
       ;;
    t) TIMESTAMP=false ;;
    h) usage; exit 0 ;;
    \?) err "Invalid option: -$OPTARG"; exit 2 ;;
    :)  err "Option -$OPTARG requires argument"; exit 2 ;;
  esac
done

shift $((OPTIND - 1))

# If positional source provided, prefer it
if [[ -n "${1:-}" ]] && [[ -z "$SRC" ]]; then
  SRC="$1"
fi

# If no source given, pick first .cpp in CWD
if [[ -z "$SRC" ]]; then
  shopt -s nullglob
  files=( *.cpp )
  (( ${#files[@]} > 0 )) || { err "No .cpp files found in current directory."; exit 1; }
  SRC="${files[0]}"
  log "No source specified — using first .cpp: ${YELLOW}${SRC}${NC}"
fi

[[ -f "$SRC" ]] || { err "Source file '$SRC' not found."; exit 1; }

BIN="${SRC%.*}"
if [[ "${OS:-}" =~ MINGW|Windows ]] || [[ "${MSYSTEM:-}" =~ MINGW ]]; then
  BIN="${BIN}.exe"
fi

command -v "$COMPILER" >/dev/null || { err "Compiler not found: $COMPILER"; exit 1; }

# ---------------- Retro ASCII banner & helpers ----------------
retro_banner() {
  cat <<'BANNER'
  ____   ____  _____  _     ___   ____  _   _ 
 |  _ \ / ___||  ___|| |   / _ \ / ___|| | | |
 | |_) |\___ \| |_   | |  | | | |\___ \| | | |
 |  _ <  ___) |  _|  | |__| |_| | ___) | |_| |
 |_| \_\|____/|_|    |_____\___/ |____/ \___/ 

   Classic-Style C++ Compiler — Retro Mode
BANNER
}
# Note: banner above is in a here-doc (no color codes inside), we'll color it below

typewriter() {
  # prints argument with a typewriter effect (fast)
  local text="$*"
  local delay="${TYPE_DELAY:-0.01}"
  for ((i=0;i<${#text};i++)); do
    printf "%s" "${text:i:1}"
    sleep "$delay"
  done
  printf "\n"
}

spinner_start() {
  # start spinner in background; spinner_pid is set
  local sp='|/-\'
  printf " "
  (
    while true; do
      for ((i=0;i<${#sp};i++)); do
        printf "\b%s" "${sp:i:1}"
        sleep 0.08
      done
    done
  ) &
  spinner_pid=$!
  disown "$spinner_pid" 2>/dev/null || true
}

spinner_stop() {
  if [[ -n "${spinner_pid:-}" ]]; then
    kill "$spinner_pid" >/dev/null 2>&1 || true
    wait "$spinner_pid" 2>/dev/null || true
    unset spinner_pid
    printf "\b"  # remove spinner char
  fi
}

# Clean up on exit
cleanup() {
  spinner_stop
}
trap cleanup EXIT

# ---------------- Show banner & messages ----------------
printf "%b" "$CYAN"
retro_banner
printf "%b\n" "$NC"

TYPE_DELAY=0.005
printf "%b" "${MAGENTA}"
typewriter "Initializing compiler environment..."
printf "%b" "$NC"

# show compile command (typewriter)
printf "%b" "${YELLOW}"
typewriter "Command: $COMPILER ${CXXFLAGS[*]} $SRC -o $BIN"
printf "%b" "$NC"

# ---------------- Compile with spinner animation ----------------
echo -n "${BOLD}${BLUE}Compiling${NC} "
spinner_start

# Run compiler in background, capture exit code properly
# We run compiler and redirect its stderr/stdout to temporary files so the animation is clean.
tmp_out="$(mktemp)"
tmp_err="$(mktemp)"
set +e
"$COMPILER" "${CXXFLAGS[@]}" "$SRC" -o "$BIN" >"$tmp_out" 2>"$tmp_err" &
compiler_pid=$!
wait "$compiler_pid"
compile_rc=$?
set -e

spinner_stop
if (( compile_rc != 0 )); then
  echo -e "${RED}${BOLD}\nCompilation failed.${NC}"
  echo -e "${YELLOW}--- compiler stdout ---${NC}"
  sed -n '1,200p' "$tmp_out" || true
  echo -e "${YELLOW}--- compiler stderr ---${NC}" >&2
  sed -n '1,200p' "$tmp_err" >&2 || true
  rm -f "$tmp_out" "$tmp_err"
  exit "$compile_rc"
fi

echo -e " ${GREEN}${BOLD}OK${NC}"
rm -f "$tmp_out" "$tmp_err"

# ---------------- Link animation (tiny) ----------------
printf "%b" "${BLUE}"
typewriter "Linking objects..."
sleep 0.15
printf "%b" "$NC"

# ---------------- Run program ----------------
if [[ -f "$INFILE" ]]; then
  log "Running program: ./${BIN} < ${INFILE} > ${OUTFILE}"
  # small retro "running" effect
  printf "%b" "${MAGENTA}"
  typewriter "Running..."
  printf "%b" "$NC"
  ./"$BIN" < "$INFILE" > "$OUTFILE"
else
  log "Running program: ./${BIN} > ${OUTFILE}"
  printf "%b" "${MAGENTA}"
  typewriter "Running (no input file)..."
  printf "%b" "$NC"
  ./"$BIN" > "$OUTFILE"
fi

# ---------------- Completion animation ----------------
printf "%b" "${GREEN}"
typewriter "Execution finished."
printf "%b" "$NC"

ok "Output written to ${OUTFILE}"

# optional: print first few lines of output with a retro "screen"
if [[ -s "$OUTFILE" ]]; then
  echo
  printf "%b" "${CYAN}${BOLD}--- program output (first 20 lines) ---${NC}\n"
  sed -n '1,20p' "$OUTFILE" || true
  echo
fi

exit 0
