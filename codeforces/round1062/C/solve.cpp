#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool pode_trocar(int a, int b) {
  return a % 2 != b % 2 && a > b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> entrada(n);
    for (int i = 0; i < n; i++) cin >> entrada[i];

    while (true) {
      bool trocou = false;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (pode_trocar(entrada[i], entrada[j]) && i != j) {
            int aux = entrada[i];
            entrada[i] = entrada[j];
            entrada[j] = aux;
            trocou = true;
          }
        }
      }

      if (!trocou) break;
    }

    for (int i : entrada) {
      cout << i << " ";
    }
    cout << "\n";
    
  }
  
  
  return 0;
}