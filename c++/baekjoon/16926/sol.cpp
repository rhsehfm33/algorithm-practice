#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M, R;
    cin >> N >> M >> R;
    vector<vector<int>> A(N, vector<int>(M));
    for (auto& Ai : A) {
        for (auto& Aij : Ai) {
            cin >> Aij;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int ni = i, nj = j;
            int d = min({i, N - 1 - i, j, M - 1 - j});
            int r = R % (N + N + M + M - (d + d + 1) * 4);
            while (r) {
                int c;
                if (nj == d) {
                    c = min(r, ni - d);
                    r -= c;
                    ni -= c;
                }
                if (ni == d) {
                    c = min(r, M - 1 - d - nj);
                    r -= c;
                    nj += c;
                }
                if (nj == M - 1 - d) {
                    c = min(r, N - 1 - d - ni);
                    r -= c;
                    ni += c;
                }
                if (ni == N - 1 - d) {
                    c = min(r, nj - d);
                    r -= c;
                    nj -= c;
                }
            }
            cout << A[ni][nj] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}