#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  string s; cin >> s;
  int a=0, d=0;
  for(int i = 0; i< n; i++) {
    if (s[i] == 'A') a++;
    else if (s[i] == 'D') d++;
  }

  if (a==d) cout << "Friendship";
  else if (a > d) cout << "Anton";
  else cout << "Danik";

}
