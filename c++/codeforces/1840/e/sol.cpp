#include <bits/stdc++.h>

using namespace std;

int isSame(array<string, 2>& ss, int i) {
    return ss[0][i] == ss[1][i];
}

void solve(int _ti) {
    array<string, 2> ss;
    cin >> ss[0] >> ss[1];

    int match = 0;
    for (int i = 0; i < ss[0].size(); ++i) {
        match += isSame(ss, i);
    }

    int t, q;
    cin >> t >> q;
    queue<array<int, 2>> que;
    for (int ti = 0; ti < q; ++ti) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            cin >> pos;
            --pos;

            match -= isSame(ss, pos);
            que.push({ti + t, pos});
        }
        else if (type == 2) {
            int i1, pos1, i2, pos2;
            cin >> i1 >> pos1 >> i2 >> pos2;
            --i1, --pos1, --i2, --pos2;
            
            if (pos1 != pos2) {
                match -= (isSame(ss, pos1) + isSame(ss, pos2));
                swap(ss[i1][pos1], ss[i2][pos2]);
                match += (isSame(ss, pos1) + isSame(ss, pos2));
            }
            else if (i1 != i2) {
                swap(ss[i1][pos1], ss[i2][pos2]);
            }
        }
        else {
            while (que.size() and que.front().at(0) <= ti) {
                match += isSame(ss, que.front().at(1));
                que.pop();
            }

            if (match == ss[0].size() - que.size()) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}