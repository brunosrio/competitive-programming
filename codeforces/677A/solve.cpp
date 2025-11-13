#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, h; cin >> n >> h;
  vector<int> vetor(n);
  int ones = 0, twos = 0;
  for(int i = 0; i<n; i++) {
    cin >> vetor[i];
    if (vetor[i] > h) twos++;
    else ones++;
  }

  cout << ones + twos*2 << "\n"; 

  return 0;
}
