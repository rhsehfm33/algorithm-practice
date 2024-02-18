#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    priority_queue<array<int, 2>> pq;
    for (int i = 0; i < n; ++i) {
        string ai;
        cin >> ai;
        int sz = ai.size();
        while (ai.size() and ai.back() == '0') {
            ai.pop_back();
        }
        pq.push({sz - (int)ai.size(), sz});
    }

    int is_alice = 1;
    while (true) {
        if (pq.size() == 1) {
            if (pq.top()[1] - pq.top()[0] - 1 < m) {
                cout << "Anna\n";
            } else {
                cout << "Sasha\n";
            }
            return;
        }

        if (is_alice) {
            auto [z, sz] = pq.top(); pq.pop();
            pq.push({0, sz - z});
        } else {
            auto [z1, sz1] = pq.top(); pq.pop();
            auto [z2, sz2] = pq.top(); pq.pop();
            pq.push({z2, sz1 + sz2});
        }
        is_alice ^= 1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}