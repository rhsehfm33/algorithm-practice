#!/bin/bash

cd /home || exit 1

commit_made=false

git reset

while read -r file; do
    if [[ "$file" =~ c\+\+/codeforces/([0-9]+)/([a-z]+)/sol\.cpp ]]; then
        contest_id="${BASH_REMATCH[1]}"
        problem_id="${BASH_REMATCH[2]}"

        git add "$file"
        git commit -m "Solve codeforces, contest $contest_id, problem $problem_id" \
                   -m "problem link: https://codeforces.com/problemset/problem/$contest_id/$problem_id"

        commit_made=true
    else
        echo "패턴에 맞지 않음: $file"
    fi
done < <(git ls-files --others --exclude-standard)

if [ "$commit_made" = true ]; then
    echo "commit 완료, push 진행할게"
    git push -f origin master
else
    echo "커밋할 파일 없음."
fi
