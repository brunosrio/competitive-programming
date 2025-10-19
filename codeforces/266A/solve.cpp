#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  string s; cin >> s;
  if (n == 1) {
    cout << 0 << "\n";
    return 0;
  }

  char ant = s[0];
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == ant) ans++;
    ant = s[i];
  }

  cout << ans << "\n";
}
