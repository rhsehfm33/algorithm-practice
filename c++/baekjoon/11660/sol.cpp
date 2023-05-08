#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> presum(N + 1, vector<int>(N + 1));
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            cin >> presum[x][y];
        }
    }

    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            presum[x][y] += presum[x - 1][y] + presum[x][y - 1] - presum[x - 1][y - 1];
        }
    }

    while (M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << presum[x2][y2] - presum[x1 - 1][y2] - presum[x2][y1 - 1] + presum[x1 - 1][y1 - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}