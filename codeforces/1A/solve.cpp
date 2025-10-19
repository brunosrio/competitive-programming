#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, m, a; 
  cin >> n >> m >> a;
  ll x = (n/a) + (n%a != 0);
  ll y = m/a + (m%a != 0);
  cout << x*y << "\n";
  return 0;
}
