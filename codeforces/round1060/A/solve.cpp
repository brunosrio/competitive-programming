#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    set<int> pred;

    for (int i = 0; i < n; i++) {
      if (s[i] == '0') continue;
      int acc1 = 0;
      for (int j = i-1; j >= i - (k-1) && j >= 0; j--) {
        if (s[j] == '1') {
          acc1++; break;
        }
      }

      if (!acc1) pred.insert(i);
    }

    cout << pred.size() << "\n";
  }

  return 0;
}