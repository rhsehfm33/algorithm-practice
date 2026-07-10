#!/bin/bash

setup_git_config() {
    if [ -z "$(git config --global user.name)" ]; then
        read -rp "git user.name 입력: " git_name
        git config --global user.name "$git_name"
    fi

    if [ -z "$(git config --global user.email)" ]; then
        read -rp "git user.email 입력: " git_email
        git config --global user.email "$git_email"
    fi
}

commit_solutions() {
    commit_made=false

    git reset > /dev/null 2>&1

    while read -r file; do
        if [[ "$file" =~ codeforces/([0-9]+)/([a-z]+[0-9]?)/sol\.cpp ]]; then
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
}

cd "${BASH_SOURCE%/*}" || exit 1

setup_git_config
commit_solutions