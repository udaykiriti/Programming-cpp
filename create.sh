#!/bin/bash

TEMPLATE="$HOME/Programming-cpp/algo/Template.cpp"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

if [ -z "$1" ]; then
  echo -e "${YELLOW}Usage:${NC} create <name> [-cpp]"
  exit 1
fi

FILENAME="$1"
EXTENSION="$2"

if [ "$EXTENSION" == "-cpp" ]; then
  FILENAME="${FILENAME}.cpp"
fi

if [ ! -f "$TEMPLATE" ]; then
  echo -e "${RED} Error:${NC} Template not found"
  echo -e "${BLUE}Path:${NC} $TEMPLATE"
  exit 1
fi

if [ -f "$FILENAME" ]; then
  echo "Please check once before Trying another time.."
  echo -e "${YELLOW}Warning:${NC} $FILENAME already exists.... "
  echo "Danger [Verify Twice and Enter "y" cuz the Data will be Destroyed"
  read -p "Overwrite? (y/n) [Now the Danger Begins]: " choice
  [[ "$choice" != "y" ]] && echo -e "${RED}Aborted...[I mean Operation Cancelled]" && exit 1
fi

cp "$TEMPLATE" "$FILENAME" &&
  echo -e "${GREEN} Delivered:${NC} $FILENAME from Template.cpp"
