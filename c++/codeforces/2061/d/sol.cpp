#include <bits/stdc++.h>

using namespace std;

int _ti;

bool dnq(multiset<int>& ms, int num) {
    if (num == 0) {
        return false;
    }
    if (ms.count(num)) {
        ms.erase(ms.find(num));
        return true;
    }

    return dnq(ms, num / 2) and dnq(ms, num / 2 + num % 2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> ms;
    while (n--) {
        int ai;
        cin >> ai;
        ms.insert(ai);
    }
    vector<int> b(m);
    for (auto& bi : b) {
        cin >> bi;
    }

    for (auto& bi : b) {
        if (!dnq(ms, bi)) {
            cout << "No\n";
            return;
        }
    }

    cout << (ms.size() ? "No\n" : "Yes\n");
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