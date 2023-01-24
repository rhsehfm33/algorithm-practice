#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int NONE = 0;
const int BLACK = 1;
const int WHITE = 2;

array<ll, 3> bfs(vector<int>& color, vector<vector<int>>& u2v, int s) {
    ll edges = 0, black = 0, white = 0;
    queue<int> q;
    q.push(s);
    color[s] = BLACK;

    while (q.size()) {
        if (color[q.front()] == BLACK) {
            black += q.size();
        }
        else {
            white += q.size();
        }

        int ql = q.size();
        while (ql--) {
            int u = q.front(); q.pop();
            edges += u2v[u].size();
            for (int v : u2v[u]) {
                if (color[v] == color[u]) {
                    return {-1, -1, -1};
                }
                else if (color[v] == NONE) {
                    color[v] = color[u] == BLACK ? WHITE : BLACK;
                    q.push(v);
                }
            }
        }
    }

    return {black, white, edges / 2};
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> u2v(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    vector<int> color(N + 1);
    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        // cout << i << ' ' << color[i] << '\n';
        if (color[i] != NONE) {
            continue;
        }
        auto [black, white, edges] = bfs(color, u2v, i);
        if (edges == -1) {
            cout << "0\n";
            return;
        }
        ans += edges ? (black * white - edges) * 2 : 0;
        // cout << i << ' ' << ans << ' ' << black << ' ' << white << '\n';
        ans += (black + white) * (N - black - white);
    }

    cout << ans / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}
