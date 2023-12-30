#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int getMinAsc(vector<int> a, int n, int mn, int mx) {
    int result = INF, si = -1, bi = -1;
    for (int i = 0; i < n; ++i) {
        if (a[(n - i) % n] == mn and a[n - i - 1] == mx) {
            si = (n - i) % n;
            bi = n - i + 1;
            result = min(i, n - i + 2);
            break;
        }
    }

    for (int i = si + 1; i % n != si; ++i) {
        if (a[i % n] < a[(i - 1 + n) % n]) {
            return INF;
        }
    }

    return result;
}

int getMinDesc(vector<int> a, int n, int mn, int mx) {
    int result = INF, si = -1, bi = -1;
    for (int i = 0; i < n; ++i) {
        if (a[(n - i) % n] == mx and a[n - i - 1] == mn) {
            si = (n - i) % n;
            bi = n - i + 1;
            result = min(i + 1, n - i + 1);
            break;
        }
    }

    for (int i = si + 1; i % n != si; ++i) {
        if (a[i % n] > a[(i - 1 + n) % n]) {
            return INF;
        }
    }

    return result;
}

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    if (n == 1) {
        cout << "0\n";
        return;
    }

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    int ans = min(getMinAsc(a, n, mn, mx), getMinDesc(a, n, mn, mx));
    cout << (ans == INF ? -1 : ans) << '\n';
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