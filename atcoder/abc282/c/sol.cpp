#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    for (int i = 0, is_open = 0; i < S.size(); ++i) {
        if (S[i] == ',' and is_open == 0) {
            S[i] = '.';
        }
        else if (S[i] == '\"') {
            is_open = !is_open;
        }
    }

    cout << S << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}