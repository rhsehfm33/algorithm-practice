#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (auto& pi : p) {
        cin >> pi;
    }

    int sorted = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] == sorted + 1) {
            ++sorted;
        }
    }
    int not_sorted = n - sorted;

    cout << not_sorted / k + (not_sorted % k ? 1 : 0) << '\n';
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