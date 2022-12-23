#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_up_letter(char ch) {
    return ch >= 'A' and ch <= 'Z';
}

bool is_deci_digit(string s) {
    for (char ch : s) {
        if (ch < '0' or ch > '9') {
            return false;
        }
    }
    
    return stoi(s) >= 100000;
}

void solve() {
    string S;
    cin >> S;
    if (S.size() == 8 and
    is_up_letter(S[0]) and
    is_deci_digit(S.substr(1, 6)) and
    is_up_letter(S[7])) {
        cout << "Yes\n";
        return;
    }
    else {
        cout << "No\n";
        return;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}