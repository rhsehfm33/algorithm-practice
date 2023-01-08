#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll A, B;
    cin >> A >> B;
    ll result = 1;
    while (B--) {
        result *= A;
    }
    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}