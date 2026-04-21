#include <bits/stdc++.h>
using namespace std;

int _ti;

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int result;
    cin >> result;
    return result;
}

void answer(int k) {
    cout << "! " << k << endl;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        if (ask(i, i + n)) {
            answer(i);
            return;
        }
    }
    if (ask(n - 1, n + n) or ask(n + n - 1, n + n)) {
        answer(n + n);
        return;
    } else {
        answer(n);
        return;
    }
}

int main() {
    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}