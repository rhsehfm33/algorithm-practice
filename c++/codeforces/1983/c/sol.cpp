#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> abc(3, vector<ll>(n + 1));
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> abc[i][j];
        }
    }
    ll target = (accumulate(abc[0].begin(), abc[0].end(), 0ll) + 2) / 3;

    vector<array<int, 2>> ans;
    vector<int> p = {0, 1, 2};
    do {
        ans.clear();
        int i = 1;

        for (auto& pi : p) {
            ans.push_back({pi, i});
            
            ll sum = 0;
            while (i <= n and (sum < target or ans.size() == 5)) {
                sum += abc[pi][i++];
            }

            if (sum >= target) {
                ans.push_back({pi, i - 1});
            }
        }
        if (ans.size() == 6) {
            break;
        }
    } while (next_permutation(p.begin(), p.end()));

    if (ans.size() != 6) {
        cout << "-1\n";
        return;
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < 6; ++i) {
        cout << ans[i][1] << ' ';
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