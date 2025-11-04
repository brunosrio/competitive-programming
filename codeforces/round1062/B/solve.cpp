#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    map<char, int> s_count;
    map<char, int> t_count;
    string s, t; cin >> s >> t;
    for (char l : s) {
      if (s_count.count(l)) {
        s_count[l]++;
      } else {
        s_count[l] = 1;
      }
    }

    for (char l : t) {
      if (t_count.count(l)) {
        t_count[l]++;
      } else {
        t_count[l] = 1;
      }
    }

    bool ans = true;
    for (int i = 0; i < n; i++) {
      char letter = s[i];
      if (t_count[letter] != s_count[letter]) {
        ans = false;
        break;
      }
    }

    cout << (ans ? "YES" : "NO") << "\n";
  }
  
  
  return 0;
}