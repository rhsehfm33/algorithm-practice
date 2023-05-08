#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> scores(N);
    for (auto& score : scores) {
        cin >> score;
    }

    double max_score = *max_element(scores.begin(), scores.end());
    double sum = 0;
    for (auto score : scores) {
        sum += score / max_score * 100;
    }

    cout << sum / (double)N << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}