#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<int> ch2cnt('z' + 1);
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        ++ch2cnt[ch];
    }

    int choice = n - k - (n - k) % 2;
    for (int i = 'a'; i <= 'z' and choice; ++i) {
        choice -= min(choice, ch2cnt[i] - ch2cnt[i] % 2);
    }

    cout << (choice ? "NO" : "YES") << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}