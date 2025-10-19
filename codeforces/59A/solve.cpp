#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  int up_count = 0;
  int low_count = 0;
  for (int i = 0; i < s.size(); i++) {
    if (islower(s[i])) low_count++;
    else up_count++;
  }

  transform(s.begin(), s.end(), s.begin(), (up_count > low_count ? ::toupper : ::tolower));
  
  cout << s << "\n";
  return 0;
}
