#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  set<char> letras;
  for (int i = 0; i < s.length(); i++) {
    letras.insert(s[i]);
  }

  if (letras.size() % 2 == 0) cout << "CHAT WITH HER!";
  else cout << "IGNORE HIM!";
  
  return 0;
}