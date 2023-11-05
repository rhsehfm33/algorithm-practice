#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    vector<set<int>> rs(9), cs(9), gs(9);
    vector<vector<int>> A(9, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> A[i][j];
            rs[i].insert(A[i][j]);
            cs[j].insert(A[i][j]);
            gs[i / 3 + (j / 3) * 3].insert(A[i][j]);
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (rs[i].size() != 9 or cs[i].size() != 9 or gs[i].size() != 9) {
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