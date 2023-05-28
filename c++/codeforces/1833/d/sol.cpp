#include <bits/stdc++.h>

using namespace std;

vector<int> getTransform(vector<int>& p, const int n, int l, int r) {
    vector<int> result;
    result.reserve(n);
    for (int i = r + 1; i < n; ++i) {
        result.push_back(p[i]);
    }
    for (int i = r; i >= l; --i) {
        result.push_back(p[i]);
    }
    for (int i = 0; i < l; ++i) {
        result.push_back(p[i]);
    }

    return result;
}

void solve(int _ti) {
    int n;
    cin >> n;

    map<int, int> m;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        m[p[i]] = i;
    }

    if (n == 1) {
        cout << p[0] << '\n';
        return;
    }

    vector<int> ans;
    int max_pivot = p[0] != n ? m[n] : m[n - 1];
    ans = getTransform(p, n, max_pivot, max_pivot);

    for (int r = max_pivot - 1, l = max_pivot - 1; l >= 0; --l) {
        vector<int> result = getTransform(p, n, l, r);
        if (result > ans) {
            ans = result;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}