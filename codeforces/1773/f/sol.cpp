#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int d = 0;
    vector<pair<int, int>> results;
    for (int i = 0; i < n; ++i) {
        if (a == 0 and b == 0) {
            results.push_back({0, 0});
            d += 1;
        }
        else if (i == n - 1) {
            if (a == b) {
                if (results.size()) {
                    results.back().first += 1;
                    results.push_back({a - 1, b});
                }
                else {
                    results.push_back({a, b});
                    d += 1;
                }
            }
            else {
                results.push_back({a, b});
            }
        }
        else if (a) {
            results.push_back({1, 0});
            a -= 1;
        }
        else {
            results.push_back({0, 1});
            b -= 1;
        }
    }

    cout << d << "\n";
    for (auto [ca, cb] : results) {
        cout << ca << ":" << cb << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}