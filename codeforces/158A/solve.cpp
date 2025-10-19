#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k; 
  cin >> n >> k;
  vector<int> entrada;
  for (int i = 0; i < n; i++) {
    int x; cin >> x; entrada.push_back(x);
  }

  int l = 0, r = n-1, pos_maior = -1, limite = entrada[k-1];
  while (l <= r) {
    int mid = (l+r)/2;
    int x = entrada[mid];
    if (x >= limite && x > 0) {
      pos_maior = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  int ans = pos_maior == -1 ? 0 : pos_maior + 1;

  cout << ans << "\n";
  return 0;
}
