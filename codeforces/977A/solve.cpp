#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;
  while (k--) {
    if (n % 10 == 0) n = n/10;
    else n--;
  }

  cout << n << "\n";

  return 0;
}
