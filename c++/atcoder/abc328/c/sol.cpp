#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;

    vector<int> ps(N);
    for (int i = 1; i < N; ++i) {
        ps[i] = ps[i - 1] + (s[i - 1] == s[i]);
    }
    
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << ps[r - 1] - ps[l - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}