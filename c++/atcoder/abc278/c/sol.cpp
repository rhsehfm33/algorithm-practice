#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    set<pair<int, int>> s;
    while (Q--) {
        int T, A, B;
        cin >> T >> A >> B;
        if (T == 1) {
            s.insert({A, B});
        }
        else if (T == 2) {
            s.erase({A, B});
        }
        else {
            if (s.count({A, B}) and s.count({B, A})) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}