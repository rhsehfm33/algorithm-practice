#!/bin/bash

contest_id="$1"
problem_id="$2"
target_file="/home/c++/codeforces/$contest_id/$problem_id/sol.cpp"

# 매개변수 확인
if [ -z "$contest_id" ] || [ -z "$problem_id" ]; then
    echo "Usage: $0 <contest_id> <problem_id>"
    exit 1
fi

# 파일 존재 체크
if [ ! -f "$target_file" ]; then
    echo "Error: '$target_file' does not exist."
    exit 1
fi

# add -> commit -> push
git add "$target_file"

git commit -m "Solve codeforces, contest $contest_id, problem $problem_id" \
             -m "problem link: https://codeforces.com/problemset/problem/$contest_id/$problem_id"

git push origin master
