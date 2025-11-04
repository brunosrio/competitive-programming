#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cout << (i <= m ? "OK" : "Too Many Requests") << "\n";
  }

  return 0;
}

