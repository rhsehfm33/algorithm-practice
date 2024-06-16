#include <bits/stdc++.h>

using namespace std;

vector<int> fail(string s) {
    vector<int> p(s.size());
    p[0] = -1;
    for (int i = 1, pi = 0; i < s.size(); ++i) {
        while (pi and s[pi] != s[i]) {
            pi = p[pi - 1] + 1;
        }
        p[i] = s[i] == s[pi] ? pi++ : -1;
    }
    return p;
}

vector<int> match(string ss, string ps, vector<int>& p) {
    vector<int> m;
    for (int i = 0, pi = 0; i < ss.size(); ++i) {
        while (pi and ps[pi] != ss[i]) {
            pi = p[pi - 1] + 1;
        }
        if (ps[pi] == ss[i]) {
            ++pi;
        }
        if (pi == ps.size()) {
            m.push_back(i);
            pi = p[pi - 1] + 1;
        }
    }
    return m;
}

int main() {
    return 0;
}