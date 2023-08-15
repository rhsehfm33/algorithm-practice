#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> getSegs(map<int, int>& m) {
    vector<array<int, 2>> result;

    int sum = 0, prvsum = 0, start = 0;
    for (auto& [pos, cnt] : m) {
        sum += cnt;
        if (prvsum == 0 and sum != 0) {
            start = pos;
        }
        else if (prvsum != 0 and sum == 0) {
            result.push_back({start, pos});
        }
        prvsum = sum;
    }

    return result;
}

void solve(int _ti) {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        ++m[l];
        --m[b];
    }

    vector<array<int, 2>> segs = getSegs(m);
    int q;
    cin >> q;
    while (q--) {
        int xi;
        cin >> xi;
        array<int, 2> target = {xi, -1};
        auto seg = lower_bound(segs.begin(), segs.end(), target);
        if (seg != segs.end() and xi == seg->at(0)) {
            cout << seg->at(1) << ' ';
        }
        else if (seg != segs.begin() and xi <= prev(seg)->at(1)) {
            cout << prev(seg)->at(1) << ' ';
        }
        else {
            cout << xi << ' ';
        }
    }
    cout << '\n';
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