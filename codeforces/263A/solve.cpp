#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;
  string s;
  int inc = 0, dec = 0, x = 0;
  while (t--) {
    cin >> s;
    for (int i = 0; i < 3; i++) {
      if (s[i] == '+') {
        x++;
        break;
      }
      if (s[i] == '-') {
        x--;
        break;
      }
    }
  }  

  cout << x << "\n";
  return 0;
}
