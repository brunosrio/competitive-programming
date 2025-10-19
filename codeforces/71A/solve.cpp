#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  string word;
  for (int i = 0; i < n; i++) {
    cin >> word;
    int t = word.size();
    if (t <= 10) cout << word << "\n";
    else cout << word[0] << (t - 2) << word[t - 1] << "\n";
  }

  return 0;
}
