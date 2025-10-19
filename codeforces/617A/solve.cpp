#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int x; cin >> x;
  int steps = x / 5;
  if (x % 5 != 0) steps++;
  cout << steps << "\n";
}
