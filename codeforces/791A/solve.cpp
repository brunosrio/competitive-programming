#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int a, b; cin >> a >> b;
  int i = 0;
  while (a <= b) {
    i++;
    a *= 3;
    b *= 2;
  }

  cout << i << "\n";
  return 0;
}
