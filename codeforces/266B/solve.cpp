#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
 
  int n, t; cin >> n >> t;
  string s; cin >> s;
  char s1[n];
  for (int i = 0; i < n; i++) {
    s1[i] = s[i];
  }
 
  while (t--) {
    int i = 0;
    while (i < n) {
      bool trocou = false;
      if (i+1 < n && s1[i] == 'B' && s1[i+1] == 'G') {
        trocou = true;
        swap(s1[i], s1[i+1]);
      }
 
      if (trocou) i += 2;
      else i++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << s1[i];
  }
 
  cout << "\n";
 
  return 0;
}