#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int N;
    string S;
    cin >> N >> S;
    for (int i = 0; i + 1 < S.size(); ++i) {
        if ((S[i] == 'a' and S[i + 1] == 'b') or (S[i] == 'b' and S[i + 1] == 'a')) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}