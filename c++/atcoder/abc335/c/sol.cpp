#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<array<int, 2>> c;
    for (int i = 0; i < N; ++i) {
        c.push_back({0, i + 1});
    }

    int ci = 0, cx = 0, cy = 1;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            char C;
            cin >> C;
            ci = (ci - 1 + N) % N;
            if (C == 'U') {
                c[ci] = {++cx, cy};
            } else if (C == 'R') {
                c[ci] = {cx, ++cy};
            } else if (C == 'D') {
                c[ci] = {--cx, cy};
            } else {
                c[ci] = {cx, --cy};
            }
        } else {
            int p;
            cin >> p;
            int ti = (ci + p - 1) % N;
            cout << c[ti][1] << ' ' << c[ti][0] << '\n';
        }
    }
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}