#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll X;
    cin >> X;

    ll li = 60;
    while (true) {
        if ((X >> li) & 1) {
            break;
        }
        --li;
    }

    vector<ll> ans;
    for (ll i = 1; i <= li; ++i) {
        ans.push_back(i);
    }

    --li;
    for (ll i = 1, cur = 1; i < ans.size(); ++i, --li) {
        if ((X >> li) & 1) {
            ans.insert(ans.begin() + i, --cur);
            ++i;
        }
    }
    if (X & 1) {
        ans.push_back(-200);
    }

    cout << ans.size() << '\n';
    for (auto ansi : ans) {
        cout << ansi << ' ';
    }
    cout << '\n';
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