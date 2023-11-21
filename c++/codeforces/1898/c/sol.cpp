#include <bits/stdc++.h>

using namespace std;

void printColor(vector<vector<char>>& ans) {
    for (auto& l : ans) {
        for (auto& c : l) {
            cout << c << ' ';
        }
        cout << '\n';
    }
}

void solve(int _ti) {
    int n, m, k;
    cin >> n >> m >> k;
    if ((n + m - 2) % 2 != k % 2 or n + m - 2 > k) {
        cout << "NO\n";
        return;
    }

    int ni = 1, mi = 0;
    vector<vector<char>> ans1(n, vector<char>(m - 1, 'R')), ans2(n - 1 ,vector<char>(m, 'B'));
    for (; ni < n - 1; ++ni) {
        ans2[ni][0] = ni % 2 ? 'B' : 'R';
        ans2[ni][1] = ni % 2 ? 'R' : 'B';
    }
    for (; mi < m - 1; ++mi) {
        ans1[n - 1][mi] = (ni + mi) % 2 ? 'B' : 'R';
    }
    
    cout << "YES\n";
    printColor(ans1);
    printColor(ans2);
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