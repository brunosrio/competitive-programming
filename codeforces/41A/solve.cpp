#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s, test; cin >> s >> test;
  int l = 0, r = s.size()-1;
  string ans = "YES";

  if (s.size() != test.size()) {
    cout << "NO" << "\n";
    return 0;
  }

  while (l < s.size()) {
    if (s[l] != test[r]) {
      ans = "NO";
      break;
    }
    l++; r--;
  }

  cout << ans << "\n";
}