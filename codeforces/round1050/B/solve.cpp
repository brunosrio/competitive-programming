#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> horiz;
    for (int i = 0; i< n; i++) {
      int a; cin >> a; horiz.push_back(a);
    }

    vector<int> vert;
    for (int i = 0; i< m; i++) {
      int a; cin >> a; vert.push_back(a);
    }

    cout << n + m << "\n";
  }
  
  return 0;
}