#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int soma = 0;
  string s; cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '4'|| s[i] == '7') soma++;
  }
  
  cout << (soma == 4 || soma == 7 ? "YES": "NO") << "\n";
  return 0;
}
