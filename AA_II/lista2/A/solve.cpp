#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e5 + 10;
ll t[4 * MAXN];
ll lazy[4 * MAXN];

void push(int node, int tl, int tr) {
  if (!lazy[node]) return;
  
  t[node] += (tr - tl + 1) * lazy[node];

  if (tl != tr) {
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
  }

  lazy[node] = 0;
}

void build(vector<int>& a, int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
    return;
  }

  int tm = (tl+tr)/2;
  build(a, v*2, tl, tm);
  build(a, v*2+1, tm+1, tr);

  t[v] = t[v*2] + t[v*2+1];
}

void update(int node, int tl, int tr, int ql, int qr, int v) {
  push(node, tl, tr);

  if (qr < tl || ql > tr) return;

  if (ql <= tl && tr <= qr) {
    lazy[node] += v;
    push(node, tl, tr);
    return;
  }

  int tm = (tl+tr)/2;
  update(node*2, tl, tm, ql, qr, v);
  update(node*2+1, tm+1, tr, ql, qr, v);

  t[node] = t[node*2] + t[node*2+1];
}

ll query(int node, int tl, int tr, int ql, int qr) {
  push(node, tl, tr);
  
  if (qr < tl || ql > tr) return 0;
  if (ql <= tl && tr <= qr) return t[node];

  int tm = (tl+tr)/2;
  return query(node*2, tl, tm, ql, qr) +
          query(node*2+1, tm+1, tr, ql, qr); 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T;
  while (T--) {
    memset(t, 0, sizeof(t));
    memset(lazy, 0, sizeof(lazy));

    int n, c; cin >> n >> c;
    while (c--) {
      int op, ql, qr; cin >> op >> ql >> qr;
      ql--; qr--;
      if (op) {
        cout << query(1, 0, n-1, ql, qr) << "\n";
      } else {
        int v; cin >> v;
        update(1, 0, n-1, ql, qr, v);
      }
    }
  }

  return 0;
}
