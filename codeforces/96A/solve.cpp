#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  char last = s[0];
  int soma = 1;
  for (int i=1; i<s.size(); i++) {
    if (last == s[i]) soma++;
    else soma = 1;
    if (soma == 7) {
      cout << "YES" << "\n";
      return 0;
    }
    last = s[i];
  }

  cout << "NO" << "\n";
  return 0;
}
