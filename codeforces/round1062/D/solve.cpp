#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<ll> entrada(n);
    bool tem_impar = false;
    ll menor_par = -1;
    for (int i = 0; i < n; i++) {
      cin >> entrada[i];

      if (entrada[i] % 2 == 1) tem_impar = true;
      else {
        if (menor_par == -1 || entrada[i] < menor_par) {
          menor_par = entrada[i];
        }
      }
    }

    if (tem_impar) {
      cout << 2 << "\n";
      continue;
    }

    for (ll i = 3; i <= 1e6+7; i++) {
      if (gcd(menor_par, i) == 1) {
        cout << i << "\n";
        break;
      }
    }
  }
  
  
  return 0;
}