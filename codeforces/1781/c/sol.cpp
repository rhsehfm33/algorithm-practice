#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> vvec(26);
    for (int i = 0; i < n; ++i) {
        vvec[s[i] - 'a'].push_back(i);
    }

    vector<int> sorted_vvec(26);
    for (int i = 0; i < 26; ++i) {
        sorted_vvec[i] = i;
    }
    sort(sorted_vvec.begin(), sorted_vvec.end(), [&](int l, int r) {
        return vvec[l].size() > vvec[r].size();
    });

    int target = 0;
    for (int i = 1, mn_used = 1e9; i <= 26; ++i) {
        if (n % i != 0) {
            continue;
        }

        int used = 0;
        for (int j = 0; j < 26; ++j) {
            if (j < i) {
                used += abs(n / i - (int)vvec[sorted_vvec[j]].size());
            }
            else {
                used += (int)vvec[sorted_vvec[j]].size();
            }
        }
        if (used < mn_used) {
            mn_used = used;
            target = n / i;
        }
    }

    vector<int> indexes;
    for (int i = 0; i < 26; ++i) {
        if (i < n / target) {
            while (vvec[sorted_vvec[i]].size() > target) {
                indexes.push_back(vvec[sorted_vvec[i]].back());
                vvec[sorted_vvec[i]].pop_back();
            }
        }
        else {
            while (vvec[sorted_vvec[i]].size()) {
                indexes.push_back(vvec[sorted_vvec[i]].back());
                vvec[sorted_vvec[i]].pop_back();
            }
        }
    }

    cout << indexes.size() << '\n';
    for (int i = 0; i < n / target; ++i) {
        while (vvec[sorted_vvec[i]].size() < target) {
            vvec[sorted_vvec[i]].push_back(indexes.back());
            indexes.pop_back();
        }
    }

    for (int i = 0; i < 26; ++i) {
        while (vvec[i].size()) {
            s[vvec[i].back()] = 'a' + i;
            vvec[i].pop_back();
        }
    }
    cout << s << '\n';
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