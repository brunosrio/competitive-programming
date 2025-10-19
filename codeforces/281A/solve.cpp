#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  char inicial = toupper(s[0]);
  cout << inicial << s.substr(1, (s.size() - 1)) << "\n";
  return 0;
}
