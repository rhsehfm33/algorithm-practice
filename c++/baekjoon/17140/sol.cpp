#include <bits/stdc++.h>

using namespace std;

void solve() {
    int r, c, k;
    cin >> r >> c >> k;
    --r; --c;
    vector<vector<int>> A(3, vector<int>(3));
    for (auto& Ai : A) {
        for (auto& Aij : Ai) {
            cin >> Aij;
        }
    }
    if (r < A.size() and c < A[r].size() and A[r][c] == k) {
        cout << "0\n";
        return;
    }

    int mr = A.size(), mc = A[0].size();
    for (int ci = 1; ci <= 100; ++ci) {
        bool is_r = A.size() >= A[0].size();
        int mx = max(A.size(), A[0].size());
        vector<vector<int>> cnt(mx, vector<int>(123));
        vector<vector<array<int, 2>>> NA(mx);
        for (int x = 0; x < A.size(); ++x) {
            for (int y = 0; y < A[0].size(); ++y) {
                if (is_r) {
                    ++cnt[x][A[x][y]];
                } else {
                    ++cnt[y][A[x][y]];
                }
            }
        }

        if (is_r) {
            mc = 0;
        } else {
            mr = 0;
        }
        for (int i = 0; i < mx; ++i) {
            for (int j = 1; j < 123; ++j) {
                if (cnt[i][j]) {
                    NA[i].push_back({cnt[i][j], j});
                }
            }
            if (is_r) {
                mc = max(mc, (int)NA[i].size() * 2);
            } else {
                mr = max(mr, (int)NA[i].size() * 2);
            }
            sort(NA[i].begin(), NA[i].end());
        }

        vector<vector<int>> A2(mr, vector<int>(mc));
        for (int x = 0; x < mr; ++x) {
            for (int y = 0; y < mc; ++y) {
                if (is_r and y / 2 < NA[x].size()) {
                    A2[x][y] = NA[x][y / 2][(y & 1) ^ 1];
                } else if (!is_r and x / 2 < NA[y].size()) {
                    A2[x][y] = NA[y][x / 2][(x & 1) ^ 1];
                }
            }
        }
        A = A2;

        if (r < A.size() and c < A[r].size() and A[r][c] == k) {
            cout << ci << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}