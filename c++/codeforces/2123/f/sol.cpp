#include <bits/stdc++.h>
using namespace std;

int _ti;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    for (int i = n; i >= 2; --i) {
        if (!is_prime(i)) {
            continue;
        }
        for (int j = i, pj = i; j + i <= n; j += i) {
            if (a[j + i] == j + i) {
                swap(a[pj], a[j + i]);
                pj = j + i;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
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