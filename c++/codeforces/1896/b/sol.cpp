#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    size_t fai = s.find_first_of('A');
    size_t fbi = s.find_last_of('B');
    if (fai != string::npos and fbi != string::npos and fai < fbi) {
        cout << fbi - fai << '\n';
    } else {
        cout << 0 << '\n';
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