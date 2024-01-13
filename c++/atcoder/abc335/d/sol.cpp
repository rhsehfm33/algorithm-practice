#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> g(N, vector<int>(N));
    g[0][0] = 1;
    g[N / 2][N / 2] = -1;

    int cx = 0, cy = 0, cd = 1, cn = 1;
    while (cn < N * N - 1) {
        int nx = cx + dx[cd];
        int ny = cy + dy[cd];
        if (nx >= 0 and nx < N and ny >= 0 and ny < N and g[nx][ny] == 0) {
            g[nx][ny] = ++cn;
        } else {
            cd = (cd + 1) % 4;
            nx = cx + dx[cd];
            ny = cy + dy[cd];
            if (nx >= 0 and nx < N and ny >= 0 and ny < N and g[nx][ny] == 0) {
                g[nx][ny] = ++cn;
            }
        }
        cx = nx;
        cy = ny;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (g[i][j] == -1) {
                cout << 'T' << ' ';
            } else {
                cout << g[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}