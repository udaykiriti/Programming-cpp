#!/bin/bash

echo "----------------------------------------"
echo "   SYSTEM UTILITY v1.0  (C) 1989 RTS     "
echo "   MODULE: GIT OPERATION HANDLER         "
echo "----------------------------------------"
echo ""

if [ -z "$1" ]; then
    echo "ERROR: NO COMMIT MESSAGE PROVIDED"
    echo "USAGE: git_auto.sh \"message\""
    echo "SYSTEM STOPPED"
    exit 1
fi

echo ">> CHECKING FILE STATE"
git status
echo "   STATUS: OK"
echo ""

echo ">> PREPARING CHANGES"
git add .
echo "   RESULT: READY"
echo ""

echo ">> WRITING LOG ENTRY"
git commit -m "$1"
echo "   RESULT: STORED"
echo ""

echo ">> TRANSMITTING DATA"
git push origin main
echo "   RESULT: SENT"
echo ""

echo "----------------------------------------"
echo "   OPERATION COMPLETE - RETURNING TO IDLE"
echo "----------------------------------------"
