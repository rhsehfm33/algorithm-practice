#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S;
    cin >> S;
    vector<char> vec;
    vector<int> cnt(26);
    for (int i = 0; i < S.size(); ++i) {
        vec.push_back(S[i]);
        if (S[i] == '(') {
            continue;
        }
        else if (S[i] == ')') {
            while (vec.back() != '(') {
                if (vec.back() >= 'a' and vec.back() <= 'z') {
                    --cnt[vec.back() - 'a'];
                }
                vec.pop_back();
            }
            vec.pop_back();
        }
        else {
            if (cnt[S[i] - 'a'] > 0) {
                cout << "No\n";
                return;
            }
            ++cnt[S[i] - 'a'];
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}