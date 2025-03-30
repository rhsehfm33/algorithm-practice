#include <bits/stdc++.h>

using namespace std;

int _ti;

const int MAX = 123456;
vector<bool> p;

void preset() {
    p.resize(MAX, true);
    for (int i = 2; i < MAX; ++i) {
        if (!p[i]) {
            continue;
        }
        for (int j = i + i; j < MAX; j += i) {
            p[j] = false;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "2 1\n";
        return;
    } else if (n == 3) {
        cout << "2 1 3\n";
        return;
    }

    int on = n;
    vector<int> ans;
    while (n % 2 or !p[n / 2]) {
        ans.push_back(n--);
    }
    ans.push_back(n);
    ans.push_back(n / 2);
    for (int u = n / 2 + 1, d = n / 2 - 1; u < n and d > 0; ++u, --d) {
        ans.push_back(u);
        ans.push_back(d);
    }
    reverse(ans.begin(), ans.end());
    for (auto ansi : ans) {
        cout << ansi << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    preset();

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }
    cout << "\n";

    return 0;
}