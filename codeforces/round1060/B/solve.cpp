#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> arr;
    vector<int> maiores;
    int maior = -1, op = 0;
    for (int i = 0; i < n; i++) {
      int a; cin >> a;
      arr.push_back(a);
      maior = max(maior, a);
      maiores.push_back(maior);
    }

    for (int i = 0; i < n-1; i++) {
      if (i % 2 == 0 && arr[i] >= arr[i+1]) {
        if (arr[i+1] < maiores[i]) arr[i+1] = maiores[i];
        
        if (arr[i] >= arr[i+1]) {
          int diff = (arr[i] - arr[i+1]) + 1;
          arr[i] -= diff;
          op += diff;
        }

      } else if (i % 2 == 1 && arr[i] <= arr[i+1]) {
        if (arr[i] < maiores[i]) arr[i] = maiores[i];

        if (arr[i] <= arr[i+1]) {
          int diff = (arr[i+1] - arr[i]) + 1;
          arr[i+1] -= diff;
          op += diff;
        }
      }
    }

    cout << op << "\n";
  }
  
  return 0;
}
