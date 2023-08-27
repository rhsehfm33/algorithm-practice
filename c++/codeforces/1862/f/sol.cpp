#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e9;

void solve(int _ti) {
    int w, f, n;
    cin >> w >> f >> n;
    vector<int> s(n);
    for (auto& si : s) {
        cin >> si;
    }

    vector<int> ssum(n);
    ssum[0] = s[0];
    for (int i = 1; i < n; ++i) {
        ssum[i] = ssum[i - 1] + s[i];
    }

    int sum = accumulate(s.begin(), s.end(), 0ll);
    vector<int> dp(sum + 1, MAX);
    dp[s[0]] = (s[0] + w - 1) / w;
    dp[0] = (s[0] + f - 1) / f;
    queue<int> q;
    q.push(s[0]);
    q.push(0);
    for (int i = 1; i < s.size(); ++i) {
        vector<int> ndp(sum + 1, 2e9);
        int ql = q.size();
        while (ql--) {
            int uw = q.front(); q.pop();
            int uf = ssum[i - 1] - uw;
            int cnt = dp[uw];
            int wl = cnt * w - uw;
            int fl = cnt * f - uf;

            int wncnt = cnt + (max(0, s[i] - wl) + w - 1) / w;
            if (ndp[uw + s[i]] == MAX) {
                q.push(uw + s[i]);
            }
            ndp[uw + s[i]] = min(ndp[uw + s[i]], wncnt);

            int fncnt = cnt + (max(0, s[i] - fl) + f - 1) / f;
            if (ndp[uw] == MAX) {
                q.push(uw);
            }
            ndp[uw] = min(ndp[uw], fncnt);
        }
        dp.swap(ndp);
    }

    cout << *min_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}