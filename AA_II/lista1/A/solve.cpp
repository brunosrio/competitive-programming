#include <bits/stdc++.h>
using namespace std;
using ll = long long;;

const int MAXN = 200000;

ll t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
    return;
  }

  int tm = (tl + tr) / 2;
  build(a, v*2, tl, tm);
  build(a, v*2+1, tm+1, tr);
  t[v] = t[v*2] + t[v*2+1];
}

ll sum(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl == l && tr == r) return t[v];

  int tm = (tl + tr) /2;
  return sum(v*2, tl, tm, l, min(r, tm)) +
        sum(v*2+1, tm+1, tr, max(l, tm+1), r); 
}

void update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr) {
    t[v] = new_val;
    return;
  }

  int tm = (tl + tr) / 2;
  if (pos <= tm)
    update(v*2, tl, tm, pos, new_val);
  else
    update(v*2+1, tm+1, tr, pos, new_val);

  t[v] = t[v*2] + t[v*2+1];
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q; cin >> n >> q;
  int arr[n];
  for (int i = 0; i<n; i++) cin >> arr[i];
  
  build(arr, 1, 0, n-1);

  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      int k, u; cin >> k >> u;
      update(1, 0, n-1, k-1, u);
    } else {
      int a, b; cin >> a >> b;
      cout << sum(1, 0, n-1, a-1, b-1) << "\n";
    }
  }


  return 0;
}