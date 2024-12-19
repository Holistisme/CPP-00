#!/bin/bash

git add .
echo -n "Commit subject: "
read commit_message
git commit -m "$commit_message"
echo "Commit set!"
git push
echo "Commit pushed!"
