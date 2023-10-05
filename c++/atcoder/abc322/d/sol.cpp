#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

void rotate(vvc& Pi) {
    vvc t = Pi;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            t[j][3 - i] = Pi[i][j];
        }
    }
    Pi = t;
}

bool paint(vvc& Pi, vvc& t, int dj, int dk) {
    for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 4; ++k) {
            if (Pi[j][k] != '#') {
                continue;
            }

            int tj = j + dj;
            int tk = k + dk;
            if (tj < 0 or tj >= 4 or tk < 0 or tk >= 4) {
                return false;
            }
            if (t[tj][tk] == '#') {
                return false;
            }
            t[tj][tk] = '#';
        }
    }
    return true;
}

bool go(vvvc& P, vvc t, int idx) {
    if (idx == 3) {
        return true;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = -3; j <= 3; ++j) {
            for (int k = -3; k <= 3; ++k) {
                vvc nt = t;
                if (paint(P[idx], nt, j, k) and go(P, nt, idx + 1)) {
                    return true;
                }
            }
        }
        rotate(P[idx]);
    }

    return false;
}

void solve() {
    int sum = 0;
    vvvc P(3, vvc(4, vc(4)));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                cin >> P[i][j][k];
                if (P[i][j][k] == '#') {
                    sum += 1;
                }
            }
        }
    }

    if (sum != 16) {
        cout << "No\n";
        return;
    }

    vvc t(4, vc(4, '.'));
    if (go(P, t, 0)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}