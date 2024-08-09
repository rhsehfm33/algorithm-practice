#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> test = {n};
    for (int i = n - 1; i > 0; --i) {
        test.push_back(i);
        test.push_back(i);
    }

    int i = 0;
    while (i < test.size() and k > 0) {
        k -= test[i];
        ++i;
    }

    cout << i << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}