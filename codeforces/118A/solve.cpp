#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s; cin >> s;
  map<char, int> mapa;
  mapa['A'] = 1;
  mapa['E'] = 1;
  mapa['I'] = 1;
  mapa['O'] = 1;
  mapa['U'] = 1;
  mapa['Y'] = 1;

  for (int i = 0; i < s.size(); i++) {
    if (!mapa.count(toupper(s[i]))) {
      char saida = tolower(s[i]);
      cout << '.' << saida;
    } 
  }

  cout << "\n";
  return 0;
}
