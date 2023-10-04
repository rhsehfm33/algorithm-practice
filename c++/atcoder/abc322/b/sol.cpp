#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    bool p = true;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] != T[i]) {
            p = false;
            break;
        }
    }

    bool s = true;
    for (int i = 0; i < S.size(); ++i) {
        if (T[T.size() - 1 - i] != S[S.size() - 1 - i]) {
            s = false;
            break;
        }
    }

    if (p && s) {
        cout << 0 << '\n';
    }
    else if (p) {
        cout << 1 << '\n';
    }
    else if (s) {
        cout << 2 << '\n';
    }
    else {
        cout << 3 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}