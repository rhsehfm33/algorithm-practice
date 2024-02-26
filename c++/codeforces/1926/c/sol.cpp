#include <bits/stdc++.h>

using namespace std;

vector<int> ps = {0};

void preset() {
    for (int i = 1, sum = 0; i <= 200000; ++i) {
        string s = to_string(i);
        sum += accumulate(s.begin(), s.end(), 0) - (int)('0' * s.size());
        ps.push_back(sum);
    }
}

void solve(int _ti) {
    int n;
    cin >> n;
    cout << ps[n] << '\n';
}

int main() {
    preset();

    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}