#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll k, n, w; cin >> k >> n >> w;
  ll soma = (k + k*w) * w / 2;
  cout << (soma > n ? soma-n : 0) << "\n";
}
