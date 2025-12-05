#!/bin/bash

echo "=============================================="
echo "   ____ _ _      _        _         _         "
echo "  / ___(_) |_ __| |_ __ _| |_ _   _| |__  ___ "
echo " | |  _| | __/ _\` | '__| | __| | | | '_ \/ __|"
echo " | |_| | | || (_| | |  | | |_| |_| | |_) \__ \\"
echo "  \____|_|\__\__,_|_|  |_|\__|\__,_|_.__/|___/"
echo "=============================================="
echo ""

if [ -z "$1" ]; then
    echo "Please provide a commit message!"
    echo "Usage: ./git_auto.sh \"your message\""
    exit 1
fi

echo "Running git status..."
git status

echo "Adding all files..."
git add .

echo "Committing with message: $1"
git commit -m "$1"

echo "Pushing to origin main..."
git push origin main

echo "Done!"