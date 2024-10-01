#include <bits/stdc++.h>

using namespace std;

int _ti;

void ask(string s, int& r) {
    cout << "? " + s << endl;
    cin >> r;
}

void answer(string s) {
    cout << "! " + s << endl;
}

void solve() {
    int n, i0, i1; cin >> n;
    string s = "0";
    ask(s, i0);
    if (i0 == 0) {
        answer(string(n, '1'));
        return;
    }

    while (s.size() < n) {
        ask("0" + s, i0);
        ask("1" + s, i1);
        if (i0) {
            s = "0" + s;
        } else if (i1) {
            s = "1" + s;
        } else {
            break;
        }
    }

    while (s.size() < n) {
        ask(s + "0", i0);
        if (i0) {
            s += "0";
        } else {
            s += "1";
        }
    }

    answer(s);
}

int main() {
    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}