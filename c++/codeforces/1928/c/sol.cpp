#include <bits/stdc++.h>

using namespace std;

bool is_valid(int tn, int x, int num) {
    return (tn % num == 0 and num % 2 == 0 and (num + 2) / 2 >= x);
}

void set_factors(set<int>& k, int tn, int x) {
    for (int i = 1; i * i <= tn; ++i) {
        if (is_valid(tn, x, i)) {
            k.insert((i + 2) / 2);
        }
        if (tn % i == 0 and is_valid(tn, x, tn / i)) {
            k.insert((tn / i + 2) / 2);
        }
    }
}

void solve(int _ti) {
    set<int> k;

    int n, x;
    cin >> n >> x;
    set_factors(k, n - x, x);
    set_factors(k, n + x - 2, x);
    
    cout << k.size() << '\n';
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