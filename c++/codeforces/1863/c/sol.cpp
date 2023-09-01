#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    long long n, k;
    cin >> n >> k;
    vector<bool> vis(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vis[a[i]] = true;
    }

    for (int i = 0; i <= n; ++i) {
        if (vis[i] == false) {
            a[0] = i;
            break;
        }
    }

    for (long long i = n * (k - 1) % (n + 1), j = 0; j < n; ++j) {
        cout << a[(i + j) % (n + 1)] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}