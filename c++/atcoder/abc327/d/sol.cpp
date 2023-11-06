#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>>& u2v, vector<int>& vis, int i) {
    if (vis[i] != -1) {
        return true;
    }

    queue<array<int, 2>> q;
    q.push({i, 0});
    vis[i] = 0;
    while (q.size()) {
        auto [ci, cb] = q.front(); q.pop();
        for (int ni : u2v[ci]) {
            if (vis[ni] == cb) {
                return false;
            }

            if (vis[ni] == -1) {
                q.push({ni, cb ^ 1});
            }
            vis[ni] = cb ^ 1;
        }
    }

    return true;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    vector<vector<int>> u2v(N + 1);
    for (int i = 0; i < M; ++i) {
        u2v[A[i]].push_back(B[i]);
        u2v[B[i]].push_back(A[i]);
    }

    vector<int> vis(N + 1, -1);
    for (int i = 1; i <= N; ++i) {
        if (bfs(u2v, vis, i) == false) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}