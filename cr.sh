#!/bin/bash

TEMPLATE="$HOME/Programming-cpp/algo/Template.cpp"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

if [ -z "$1" ]; then
  echo -e "${YELLOW}Usage:${NC} cr <filename.cpp>"
  exit 1
fi

if [ ! -f "$TEMPLATE" ]; then
  echo -e "${RED} Error:${NC} Template not found"
  echo -e "${BLUE}Path:${NC} $TEMPLATE"
  exit 1
fi

if [ -f "$1" ]; then
  echo -e "${YELLOW}⚠ Warning:${NC} $1 already exists"
  read -p "Overwrite? (y/n): " choice
  [[ "$choice" != "y" ]] && echo "Aborted." && exit 1
fi

cp "$TEMPLATE" "$1" && \
echo -e "${GREEN} Created:${NC} $1 from Template.cpp"
