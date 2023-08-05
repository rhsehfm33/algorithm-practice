#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        ++m[ai];
    }

    vector<int> counts(n + 1);
    for (auto [originalDistance, count] : m) {
        int currentDistance = originalDistance;
        while (currentDistance <= n) {
            counts[currentDistance] += count;
            currentDistance += originalDistance;
        }
    }

    cout << *max_element(counts.begin(), counts.end()) << '\n';
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