#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int x, n; cin >> x >> n;
    if (n%2==0) {
      cout << 0 << "\n";
    } else {
      cout << x << "\n";
    }
  }
  
  return 0;
}