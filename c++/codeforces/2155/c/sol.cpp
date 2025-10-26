#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

int _ti;

bool check(vector<int>& a, string s) {
    int rc = s[0] == ')';
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] > a[i - 1]) {
            s += "(";
        } else if (a[i] < a[i - 1]) {
            s += ")";
        } else {
            s += (s[i - 1] == '(' ? ")" : "(");
        }
        rc += s[i] == ')';
    }

    int lo = 0;
    for (int i = 0; i < a.size(); ++i) {
        lo += (i && s[i - 1] == '(');
        rc -= (s[i] == ')');
        if (a[i] != lo + rc + 1) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << (check(a, "(") + check(a, ")")) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}