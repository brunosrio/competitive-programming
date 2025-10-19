#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int w; cin >> w;
  
  if (w == 2) {
    cout << "NO" << "\n";
    return 0;
  }

  cout << (w % 2 == 0 ? "YES" : "NO") << "\n"; 

  return 0;
}
