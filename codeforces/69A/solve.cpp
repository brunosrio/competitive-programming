#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  int x = 0, y = 0, z = 0;
  int a;
  while (n--) {
    cin >> a; x+=a;
    cin >> a; y+=a;
    cin >> a; z+=a;  
  }
  
  cout << (!x && !y && !z ? "YES": "NO") << "\n";
  return 0;
}
