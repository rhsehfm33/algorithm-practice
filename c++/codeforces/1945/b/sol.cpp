#include <iostream>
#include <string>
 
using namespace std;
 
typedef long long ll;
 
void solve(int _t) {
    ll a, b, m;
    cin >> a >> b >> m;
    cout << m / a + 1 + m / b + 1 << '\n';
}
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i);
    }
}