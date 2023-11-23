#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S;
    cin >> S;

    string ans = "";
    for (char ch : S) {
        ans += ch;
        while (ans.size() >= 3 and ans.substr(ans.size() - 3) == "ABC") {
            ans.pop_back(); ans.pop_back(); ans.pop_back();
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}