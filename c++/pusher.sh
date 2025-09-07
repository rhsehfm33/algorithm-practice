#!/bin/bash

cd /home || exit 1

commit_made=false

git reset > /dev/null 2>&1

while read -r file; do
    if [[ "$file" =~ c\+\+/codeforces/([0-9]+)/([a-z]+[0-9]?)/sol\.cpp ]]; then
        contest_id="${BASH_REMATCH[1]}"
        problem_id="${BASH_REMATCH[2]}"

        git add "$file"
        git commit -m "Solve codeforces, contest $contest_id, problem $problem_id" \
          -m "problem link: https://codeforces.com/problemset/problem/$contest_id/$problem_id" \
          > /dev/null 2>&1

        echo "$file 커밋 완료"
        commit_made=true
    else
        echo "패턴에 맞지 않음: $file"
    fi
done < <(git ls-files --others --exclude-standard)

if [ "$commit_made" = true ]; then
    git push -f origin master > /dev/null 2>&1
    echo "push 완료"
else
    echo "커밋할 파일 없음."
fi
