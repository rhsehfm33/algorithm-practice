#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<char> check0, check1;

void preset() {
    check0 = {'H', 'D', 'C', 'S'};
    check1 = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
}

void solve() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (auto& Si : S) {
        cin >> Si;
    }

    set<string> used;
    for (int i = 0; i < N; ++i) {
        if (check0.count(S[i][0]) == 0 or check1.count(S[i][1]) == 0 or used.count(S[i])) {
            cout << "No\n";
            return;
        }
        else {
            used.insert(S[i]);
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    preset();

    solve();

    return 0;
}