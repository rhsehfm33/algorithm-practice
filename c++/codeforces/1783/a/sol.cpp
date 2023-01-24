#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    if (a.front() == a.back()) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    a.insert(a.begin(), a.back());
    a.pop_back();
    for (auto ai : a) {
        cout << ai << ' ';
    }
    cout << '\n';
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