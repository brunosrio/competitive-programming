#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  map<int, bool> mapa;
  int soma = 0;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    soma += a;
    mapa[a] = true;
  }

  if (soma < m) {
    cout << "No" << "\n";
  } else {
    if (mapa.count(soma-m)) cout << "Yes";
    else cout << "No";
    cout << "\n";
  }
}

