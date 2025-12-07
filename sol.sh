#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

# sol.sh — compile & run with retro/turbo/dos animation modes
# Usage: ./sol.sh [-s source.cpp] [-i in.txt] [-o out.txt] [-c compiler] [-f "extra flags"] [-m mode] [-n] [source.cpp]
# Modes: retro (default), turbo, dos
# -n : no animation (plain output)

# --------- Defaults ----------
SRC=""
INFILE="in.txt"
OUTFILE="out.txt"
COMPILER="g++"
CXXFLAGS=( -std=c++20 -O2 -Wall -Wextra -DLOCAL )
TIMESTAMP=true
MODE="retro"
NO_ANIM=false

# --------- Colors (if tty) ----------
if [[ -t 1 ]]; then
  RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[0;33m'
  BLUE='\033[0;34m'; MAGENTA='\033[0;35m'; CYAN='\033[0;36m'
  BOLD='\033[1m'; UNDER='\033[4m'; NC='\033[0m'
else
  RED='' ; GREEN='' ; YELLOW='' ; BLUE='' ; MAGENTA='' ; CYAN='' ; BOLD='' ; UNDER='' ; NC=''
fi

usage() {
  cat <<EOF
Usage: $0 [-s source.cpp] [-i in.txt] [-o out.txt] [-c compiler] [-f "extra flags"] [-m mode] [-n] [source.cpp]
Modes: retro (default), turbo, dos
-n disables animation (plain / script-friendly)
Examples:
  $0 -m turbo solution.cpp
  $0 -n solution.cpp
EOF
}

log()  { printf "%b\n" "${BLUE}>>${NC} $*"; }
ok()   { printf "%b\n" "${GREEN}✔${NC} $*"; }
err()  { printf "%b\n" "${RED}✖ ${NC}$*" >&2; }

# --------- Parse flags ----------
while getopts ":s:i:o:c:f:m:tnh" opt; do
  case "$opt" in
    s) SRC="$OPTARG" ;;
    i) INFILE="$OPTARG" ;;
    o) OUTFILE="$OPTARG" ;;
    c) COMPILER="$OPTARG" ;;
    f) # append words from quoted string
       # shellcheck disable=SC2206
       CXXFLAGS+=( $OPTARG )
       ;;
    m) MODE="$OPTARG" ;;
    t) TIMESTAMP=false ;;
    n) NO_ANIM=true ;;
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

# Auto-detect .cpp if needed
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

# ---------------- Mode defaults ----------------
TYPE_DELAY=0.01
SPINNER_SPEED=0.08
BANNER_FUNC="retro_banner"

case "$MODE" in
  retro)
    TYPE_DELAY=0.005; SPINNER_SPEED=0.08
    ;;
  turbo)
    TYPE_DELAY=0.002; SPINNER_SPEED=0.04
    ;;
  dos)
    TYPE_DELAY=0.03; SPINNER_SPEED=0.12
    ;;
  *)
    err "Unknown mode: $MODE. Allowed: retro,turbo,dos"; exit 2
    ;;
esac

# ---------------- Banners ----------------
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

turbo_banner() {
  cat <<'BANNER'
  _______  _   _  _   _  ____   _   _  ____  
 |__   __|| \ | || \ | ||  _ \ | \ | |/ __ \ 
    | |   |  \| ||  \| || |_) ||  \| | |  | |
    | |   | . ` || . ` ||  _ < | . ` | |  | |
    | |   | |\  || |\  || |_) || |\  | |__| |
    |_|   |_| \_||_| \_||____/ |_| \_|\____/ 

   TURBO MODE — FAST & LOUD
BANNER
}

dos_banner() {
  cat <<'BANNER'
  _____   ____   _____ 
 |  __ \ / __ \ / ____|
 | |  | | |  | | (___  
 | |  | | |  | |\___ \ 
 | |__| | |__| |____) |
 |_____/ \____/|_____/ 

   DOS-ish Legacy Mode
BANNER
}

# ---------------- Utilities ----------------
typewriter() {
  local text="$*"
  for ((i=0;i<${#text};i++)); do
    printf "%s" "${text:i:1}"
    sleep "$TYPE_DELAY"
  done
  printf "\n"
}

spinner_start() {
  local sp='|/-\'
  printf " "
  (
    while true; do
      for ((i=0;i<${#sp};i++)); do
        printf "\b%s" "${sp:i:1}"
        sleep "$SPINNER_SPEED"
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
    printf "\b"
  fi
}

cleanup() { spinner_stop; }
trap cleanup EXIT

# ---------------- If no animation, do plain flow ----------------
if $NO_ANIM; then
  log "Compiling $SRC -> $BIN"
  log "Flags: ${CXXFLAGS[*]}"
  if ! "$COMPILER" "${CXXFLAGS[@]}" "$SRC" -o "$BIN"; then
    err "Compilation failed."
    exit 1
  fi
  ok "Compiled."
  if [[ -f "$INFILE" ]]; then
    log "Running ./$BIN < $INFILE > $OUTFILE"
    ./"$BIN" < "$INFILE" > "$OUTFILE"
  else
    log "Running ./$BIN > $OUTFILE"
    ./"$BIN" > "$OUTFILE"
  fi
  ok "Output written to $OUTFILE"
  exit 0
fi

# ---------------- Show banner per mode ----------------
case "$MODE" in
  retro) printf "%b" "$CYAN"; retro_banner; printf "%b\n" "$NC" ;;
  turbo) printf "%b" "$YELLOW"; turbo_banner; printf "%b\n" "$NC" ;;
  dos)   printf "%b" "$MAGENTA"; dos_banner; printf "%b\n" "$NC" ;;
esac

# show compile command
printf "%b" "${YELLOW}"
typewriter "Command: $COMPILER ${CXXFLAGS[*]} $SRC -o $BIN"
printf "%b" "$NC"

# ---------------- Compile with spinner ----------------
printf "%b" "${BOLD}${BLUE}Compiling${NC} "
spinner_start

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

# small link effect
case "$MODE" in
  turbo) typewriter "Linking..."; sleep 0.06 ;;
  retro) typewriter "Linking objects..."; sleep 0.15 ;;
  dos)   typewriter "Linking..."; sleep 0.25 ;;
esac

# ---------------- Run program ----------------
if [[ -f "$INFILE" ]]; then
  log "Running program: ./${BIN} < ${INFILE} > ${OUTFILE}"
  typewriter "Running..."
  ./"$BIN" < "$INFILE" > "$OUTFILE"
else
  log "Running program: ./${BIN} > ${OUTFILE}"
  typewriter "Running (no input file)..."
  ./"$BIN" > "$OUTFILE"
fi

# ---------------- Completion ----------------
case "$MODE" in
  turbo) typewriter "Done — blazing fast." ;;
  retro) typewriter "Execution finished." ;;
  dos)   typewriter "Execution finished. Press any key to continue..." ;;
esac

ok "Output written to ${OUTFILE}"

# print a small preview of output
if [[ -s "$OUTFILE" ]]; then
  echo
  printf "%b" "${CYAN}${BOLD}--- program output (first 20 lines) ---${NC}\n"
  sed -n '1,20p' "$OUTFILE" || true
  echo
fi

exit 0
