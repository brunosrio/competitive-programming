#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string a, b; cin >> a >> b;
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  transform(b.begin(), b.end(), b.begin(), ::tolower);

  int ans; 
  if (a < b) ans = -1;
  else if (a > b) ans = 1;
  else ans = 0;
  
  cout << ans << "\n";
  return 0;
}