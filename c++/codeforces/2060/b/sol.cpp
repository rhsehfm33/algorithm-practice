#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> decks(n, vector<int>(m));
    for (int i = n * m + 1; auto& deck : decks) {
        for (auto& card : deck) {
            cin >> card;
        }
        deck.push_back(i++);
        sort(deck.begin(), deck.end());
    }
    sort(decks.begin(), decks.end());

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (decks[i][j] != j * n + i) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    for (auto& deck : decks) {
        cout << deck.back() - n * m << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}