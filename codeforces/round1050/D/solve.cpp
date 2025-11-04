#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> odd_fields;
    ll ans = 0;
    for (int i = 0; i< n; i++) {
      int a; cin >> a;
      if (a % 2 == 1) odd_fields.push_back(a);
      else ans += a;
    }

    if (odd_fields.size() == 0) {
      cout << 0 << "\n";
      continue;
    }

    sort(odd_fields.begin(), odd_fields.end());
    
    int num_odds = odd_fields.size();
    int limit = num_odds % 2 == 0 ? num_odds/2 : num_odds/2 + 1;
    int p = num_odds - 1;
    while (limit--) {
      ans += odd_fields[p];
      p--;
    }

    cout << ans << "\n";
  }
  
  return 0;
}