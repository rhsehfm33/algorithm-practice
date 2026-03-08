#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool vis[1000006];
int _ti;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        vector<int> ai(l);
        for (auto& aij : ai) {
            cin >> aij;
        }
        set<int> s;
        vector<int> ai2;
        for (int j = l - 1; j >= 0; --j) {
            if (!s.count(ai[j])) {
                s.insert(ai[j]);
                ai2.push_back(ai[j]);
            }
        }
        a[i] = ai2;
    }

    vector<int> ans;
    while (a.size()) {
        vector<int> mn = *min_element(a.begin(), a.end());
        for (auto mni : mn) {
            if (!vis[mni]) {
                vis[mni] = true;
                ans.push_back(mni);
            }
        }
        vector<vector<int>> a2;
        for (auto& ai : a) {
            vector<int> ai2;
            for (auto& aij : ai) {
                if (!vis[aij]) {
                    ai2.push_back(aij);
                }
            }
            if (ai2.size()) {
                a2.push_back(ai2);
            }
        }
        a = a2;
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
        vis[ans[i]] = false;
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