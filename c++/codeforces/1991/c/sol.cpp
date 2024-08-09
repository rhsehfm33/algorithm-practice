#include <bits/stdc++.h>

using namespace std;

int _ti;

int cal(vector<int>& a) {
    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    int mid = (mn + mx) / 2;
    if (mn + mx == 1) {
        return -1;
    } else if (mn + mx == 0) {
        return 0;
    }
    
    for (auto& ai : a) {
        ai = abs(ai - mid);
    }
    return mid;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<int> ans;
    while (true) {
        ans.push_back(cal(a));
        if (ans.back() <= 0) {
            break;
        }
    }

    if (ans.back() == -1) {
        cout << "-1\n";
        return;
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
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