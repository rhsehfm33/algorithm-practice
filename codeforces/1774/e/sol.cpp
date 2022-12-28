#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5;

int n, d, m1, m2;
vector<int> u2v[MAX + 1];
set<int> sa, sb;

pair<int, int> get_visited(int& visited, int pu, int cu, int depth) {
    int cmxa = sa.count(cu) ? depth : -1;
    int cmxb = sb.count(cu) ? depth : -1;
    for (int v : u2v[cu]) {
        if (v == pu) {
            continue;
        }
        auto [nmxa, nmxb] = get_visited(visited, cu, v, depth + 1);
        cmxa = max(cmxa, nmxa);
        cmxb = max(cmxb, nmxb);
    }

    if (cmxa >= depth or depth + d <= cmxb) {
        ++visited;
    }
    if (cmxb >= depth or depth + d <= cmxa) {
        ++visited;
    }

    return {cmxa, cmxb};
}

void solve() {
    cin >> n >> d;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    cin >> m1;
    while (m1--) {
        int ai;
        cin >> ai;
        sa.insert(ai);
    }
    sa.insert(1);

    cin >> m2;
    while (m2--) {
        int bi;
        cin >> bi;
        sb.insert(bi);
    }
    sb.insert(1);

    int visited = 0;
    get_visited(visited, 0, 1, 1);

    cout << (visited - 2) * 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}