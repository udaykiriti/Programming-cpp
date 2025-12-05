#!/bin/bash

# Check if commit message is provided
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
