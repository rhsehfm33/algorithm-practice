#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_valid(vector<vector<int>>& os, vector<int> org, int lsz) {
    if (lsz < 0 or lsz > org.size()) {
        return false;
    }

    org.insert(org.begin() + lsz, os[0][0]);
    
    for (int i = 0; i < os.size(); ++i) {
        int ti = find(org.begin(), org.end(), os[i][0]) - org.begin();
        int tv = org[ti];
        org.erase(org.begin() + ti);
        org.insert(org.begin(), tv);
        if (org != os[i]) {
            return false;
        }
        org.erase(org.begin());
        org.insert(org.begin() + ti, tv);
    }
    return true;
}

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> os(k, vector<int>(n));
    for (vector<int>& o : os) {
        for (int& oi : o) {
            cin >> oi;
        }
    }

    if (k == 1) {
        cout << "YES\n";
        return;
    }

    int l = find(os[1].begin(), os[1].end(), os[0][0]) - os[1].begin();

    vector<int> org(os[0].begin() + 1, os[0].end());
    if (is_valid(os, org, l - 1) or is_valid(os, org, l) or is_valid(os, org, l + 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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