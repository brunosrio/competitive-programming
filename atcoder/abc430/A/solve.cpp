#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c, d; cin >> a >> b >> c >> d;
  if (c >= a && d >= b) {
    cout << "No" << "\n";
  } else if (c < a) {
    cout << "No" << "\n";
  } else {
    cout << "Yes" << "\n";
  }
}

