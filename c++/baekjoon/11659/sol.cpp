#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    vector<int> presum(N + 1);
    for (int i = 1; i <= N; ++i) {
        presum[i] = a[i] + presum[i - 1];
    }

    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << presum[j] - presum[i - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}