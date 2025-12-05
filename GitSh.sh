#!/bin/bash

echo "=== SYSTEM DIAGNOSTIC MODE ==="
echo "Module: Git Operation Unit"
echo ""

if [ -z "$1" ]; then
    echo "ERROR: Commit message missing."
    echo "USAGE: git_auto.sh \"message\""
    echo "ABORTED."
    exit 1
fi

echo "STATUS: Checking repository..."
git status
echo "OK"
echo ""

echo "ACTION: Staging changes..."
git add .
echo "DONE"
echo ""

echo "ACTION: Committing..."
git commit -m "$1"
echo "COMMIT SAVED"
echo ""

echo "ACTION: Sending to remote..."
git push origin main
echo "TRANSFER COMPLETE"
echo ""

echo "=== OPERATION COMPLETE — SYSTEM IDLE ==="
