#include <bits/stdc++.h>
#define MAXN 1e5
using namespace std;

int t[20*(int)MAXN];

int gcd(int a, int b) {
  if (b==0) return a;
  return gcd(b, a%b);
}

void build(vector<int>& a, int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
    return;
  }

  int tm = (tl+tr)/2;
  build(a, v*2, tl, tm);
  build(a, v*2+1, tm+1, tr);

  t[v] = gcd(t[v*2], t[v*2+1]);
}

void update(int v, int tl, int tr, int pos, int newval) {
  if (tl == tr) {
    t[v] = newval;
    return;
  }

  int tm = (tl+tr)/2;
  if (pos <= tm) update(v*2, tl, tm, pos, newval);
  else update(v*2+1, tm+1, tr, pos, newval);

  t[v] = gcd(t[v*2], t[v*2+1]);
}

int query(int v, int tl, int tr, int l, int r, int x) {
  if (l > r) return 0;
  if (tl == l && tr == r) {
    if (t[v] % x == 0) return 0;
  }

  if (tl == tr) {
    if (t[v] % x == 0) return 0;
    else return 1;
  }

  int tm = (tl + tr) / 2;
  int left = query(v*2, tl, tm, l, min(r, tm), x);
  
  if (left > 1) return 2;

  int right = query(v*2+1, tm+1, tr, max(tm+1, l), r, x);

  return left + right;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> vetor(n);
  for (int i =0; i<n; i++) cin>>vetor[i];

  build(vetor, 1, 0, n-1);

  int q; cin>>q;
  while (q--) {
    int op; cin>>op;
    if (op == 2) {
      int i, val; cin >> i >> val;
      update(1, 0, n-1, i-1, val);
    } else {
      int l, r, x; cin >> l >> r >> x;
      int ans = query(1, 0, n-1, l-1, r-1, x);
      string res = "";
      if (ans > 1) res = "NO";
      else res = "YES";
      cout << res << "\n";
    }
  }

  return 0;
}