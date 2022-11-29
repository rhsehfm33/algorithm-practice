#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string x;
    cin >> x;
    int k;
    cin >> k;

    unordered_map<int, queue<int>> d2i;
    for (int i = 0; i < x.size(); ++i) {
        d2i[x[i] - '0'].push(i);
    }

    string ans = "";
    for (int i = 0; i < x.size();) {
        bool isSuccess = false;
        for (int j = (ans.empty() ? 1 : 0); j < x[i] - '0'; ++j) {
            while (d2i[j].size() and d2i[j].front() <= i) {
                d2i[j].pop();
            }
            if (d2i[j].size() and d2i[j].front() - i <= k) {
                k -= (d2i[j].front() - i);
                isSuccess = true;
                i = d2i[j].front();
                break;
            }
        }
        if (!isSuccess) {
            ans += x[i++];
        }
    }

    while (k--) {
        ans.pop_back();
    }

    cout << ans << '\n';
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