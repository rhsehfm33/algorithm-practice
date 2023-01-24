#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int k, n;
    cin >> k >> n;

    vector<int> ans;
    ans.push_back(1);
    for (int i = 1, added = 1, left = k - 1; left; --left) {
        if (n - (i + added) >= left - 1) {
            ans.push_back(i + added);
            i += added;
            ++added;
        }
        else {
            ans.push_back(++i);
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
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