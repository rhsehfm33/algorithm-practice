#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;
    string s2 = s.substr(1, s.size() - 2);
    auto ai = s2.find_first_of('a');
    auto bi = s2.find_first_of('b');
    if (ai != string::npos) {
        cout << s.substr(0, ai + 1) << ' ';
        cout << s.substr(ai + 1, 1) << ' ';
        cout << s.substr(ai + 2) << '\n';
    }
    else {
        cout << s.substr(0, bi + 1) << ' ';
        cout << s.substr(bi + 1, s.size() - (bi + 1) - 1) << ' ';
        cout << s.back() << '\n';
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