#include <bits/stdc++.h>
using namespace std;

int _ti;

int get_mex(vector<int>& a, int z0, int z1) {
    vector<bool> vis(a.size() + 1);
    int li = (z1 + z0) / 2;
    int ri = li + (z1 - z0) % 2;
    while (li >= 0 and ri < a.size() and a[li] == a[ri]) {
        vis[a[li]] = true;
        --li;
        ++ri;
    }

    for (int i = 0; i <= a.size(); ++i) {
        if (!vis[i]) {
            return max(1, i);
        }
    }
    assert(false);
    return -1;
}

void solve() {
    int z0 = -1, z1 = -1;
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        if (a[i] == 0)  {
            if (z0 == -1) {
                z0 = i;
            } else {
                z1 = i;
            }
        }
    }
    int mex1 = get_mex(a, z0, z0);
    int mex2 = get_mex(a, z0, z1);
    int mex3 = get_mex(a, z1, z1);
    cout << max({mex1, mex2, mex3}) << '\n';
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