#include <bits/stdc++.h>

using namespace std;

void solve() {
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    unordered_map<int, int> um;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            ++um[A[i][j]];
        }
    }

    for (int i = 0; i + h <= H; ++i) {
        unordered_map<int, int> um2 = um;
        for (int i2 = i; i2 < i + h; ++i2) {
            for (int j2 = 0; j2 < w; ++j2) {
                if (--um2[A[i2][j2]] == 0) {
                    um2.erase(A[i2][j2]);
                }
            }
        }
        
        cout << um2.size() << ' ';
        for (int j2 = w; j2 < W; ++j2) {
            for (int i2 = i; i2 < i + h; ++i2) {
                if (--um2[A[i2][j2]] == 0) {
                    um2.erase(A[i2][j2]);
                }
            }

            for (int i2 = i; i2 < i + h; ++i2) {
                ++um2[A[i2][j2 - w]];
            }
            
            cout << um2.size() << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}