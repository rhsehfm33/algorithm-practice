#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> cases;

void preset() {
    cases.resize(10);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                int sum = i + j + k;
                if (sum < 10) {
                    ++cases[sum];
                }
            }
        }
    }
}

void solve(int _ti) {
    ll ans = 1;

    string n;
    cin >> n;
    for (int i = 0; i < n.size(); ++i) {
        ans = ans * cases[n[i] - '0'];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    preset();

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}