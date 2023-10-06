#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m, d;
    cin >> n >> m >> d;
    vector<array<int, 2>> sci(m + 2);
    sci[0] = {1, 1};
    sci[m + 1] = {n, 0};
    for (int i = 1; i <= m; ++i) {
        cin >> sci[i][0];
        sci[i][1] = (sci[i - 1][0] != sci[i][0]) + sci[i - 1][1] + max(0, (sci[i][0] - sci[i - 1][0] - 1)) / d;
    }
    sci[m + 1][1] = sci[m][1] + max(0, (sci[m + 1][0] - sci[m][0])) / d;

    int ans1 = sci[m + 1][1], ans2 = 0;
    for (int i = 1; i <= m; ++i) {
        int li = sci[i - 1][0];
        int lc = sci[i - 1][1];
        int ri = sci[i + 1][0];
        int rc = sci[i + 1][1];
        int cc = rc - lc;
        int mcc = i == m ? (ri - li) / d : (ri - li - 1) / d + 1;
        int sum = (sci[m + 1][1] - (cc - mcc));
        if (sum < ans1) {
            ans1 = sum;
            ans2 = 1;
        }
        else if (sum == ans1) {
            ans2 += 1;
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';
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