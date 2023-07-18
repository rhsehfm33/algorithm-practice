#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, m, h;
    cin >> n >> m >> h;

    vector<vector<ll>> t(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> t[i][j];
        }
    }

    array<ll, 2> rudolf;
    vector<array<ll, 2>> scores;
    for (ll i = 0; i < n; ++i) {
        array<ll, 2> score = {0, 0};

        sort(t[i].begin(), t[i].end());
        for (ll j = 0, passed = 0; j < m and passed + t[i][j] <= h; ++j) {
            passed += t[i][j];
            score[0] += 1;
            score[1] += passed;
        }
        scores.push_back(score);

        if (i == 0) {
            rudolf = score;
        }
    }

    sort(scores.begin(), scores.end(), [](const auto& l, const auto& r) {
        if (l[0] != r[0]) {
            return l[0] > r[0];
        }
        else {
            return l[1] < r[1];
        }
    });

    for (int i = 0; i < n; ++i) {
        if (scores[i] == rudolf) {
            cout << i + 1 << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}