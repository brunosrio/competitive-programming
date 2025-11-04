#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n_audios, tot_m; cin >> n_audios >> tot_m;
    int atual_m = 0, pos_atual = 0, ans = 0;
    for (int i = 0; i < n_audios; i++) {
      int a, b; cin >> a >> b;
      int diff = a - atual_m;
      if (diff == 1) {
        if (b != pos_atual) {
          ans++;
          atual_m++;
          pos_atual = b;
          continue;
        }
      } else if (diff % 2 == 0) {
        if (b == pos_atual) {
          ans += diff;
        } else {
          ans += diff - 1;
        }
      } else {
        if (b == pos_atual) {
          ans += diff - 1;
        } else {
          ans += diff;
        }
      }
      atual_m += diff;
      pos_atual = b;
    }
    if (atual_m < tot_m) {
      ans += (tot_m - atual_m);
    }
    cout << ans << "\n";
  }
  
  return 0;
}