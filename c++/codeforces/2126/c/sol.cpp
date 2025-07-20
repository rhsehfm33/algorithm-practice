#include <bits/stdc++.h>
using namespace std;
int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto& hi : h) {
        cin >> hi;
    }
    int hk = h[k - 1];
    sort(h.begin(), h.end(), greater<>());
    while (h.back() < hk) {
        h.pop_back();
    }

    for (int i = h.size() - 1; i - 1 >= 0; --i) {
        if (h[i - 1] - h[i] > hk) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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