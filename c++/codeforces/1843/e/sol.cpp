#include <bits/stdc++.h>

using namespace std;

bool isBeautiful(vector<array<int, 2>>& lr, vector<int>& qs, int n, int mid) {
    vector<int> presum(n + 1);
    for (int i = 0; i < mid; ++i) {
        presum[qs[i]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        presum[i] += presum[i - 1];
    }

    for (const auto& [li, ri] : lr) {
        if (presum[ri] - presum[li - 1] > (ri - li + 1) / 2) {
            return true;
        }
    }
    return false;
}

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> lr(m);
    for (auto& [li, ri] : lr) {
        cin >> li >> ri;
    }

    int q;
    cin >> q;
    vector<int> qs(q);
    for (int& qi : qs) {
        cin >> qi;
    }

    int low = 0, high = q;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isBeautiful(lr, qs, n, mid)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (high == q) {
        cout << -1 << '\n';
    }
    else {
        cout << high + 1 << '\n';
    }
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