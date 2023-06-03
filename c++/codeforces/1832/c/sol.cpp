#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        if (a.empty() or a.back() != ai) {
            a.push_back(ai);
        }
    }

    n = a.size();
    int ans = n;
    for (int i = 1; i + 1 < n; ++i) {
        if ((a[i - 1] < a[i] and a[i] < a[i + 1])
        or (a[i - 1] > a[i] and a[i] > a[i + 1])) {
            --ans;
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}