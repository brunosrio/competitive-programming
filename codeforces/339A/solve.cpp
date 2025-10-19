#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;
  vector<int> v;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') v.push_back(1); 
    else if (s[i] == '2') v.push_back(2); 
    else if (s[i] == '3') v.push_back(3); 
  }

  sort(v.begin(), v.end());

  cout << v[0];
  for (int i = 1; i < v.size(); i++) {
    cout << "+" << v[i];
  }
  return 0;
}
