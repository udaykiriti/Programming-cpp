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
    echo "ERROR: Commit message missing."
    echo "USAGE : git_auto.sh \"message\""
    exit 1
fi

echo "[STATUS] Checking repository..."
git status
echo ""

echo "[ACTION] Adding files..."
git add .
echo ""

echo "[ACTION] Committing changes..."
echo "MESSAGE: \"$1\""
git commit -m "$1"
echo ""

echo "[ACTION] Uploading to server (origin:main)..."
git push origin main
echo ""

echo "----------------------------------------"
echo "  O P E R A T I O N   C O M P L E T E    "
echo "----------------------------------------"