#include <bits/stdc++.h>
using namespace std;

int t[4 * 200000];

void build(vector<int>& a, int node, int tl, int tr) {
  if (tl == tr) {
    t[node] = a[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  build(a, node*2, tl, tm);
  build(a, node*2+1, tm+1, tr);
  t[node] = max(t[node*2], t[node*2+1]);
}

void update(int node, int tl, int tr, int pos, int x) {
  if (tl == tr) {
    t[node] = x;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm) update(node*2, tl, tm, pos, x);
  else update(node*2+1, tm+1, tr, pos, x);
  t[node] = max(t[node*2], t[node*2+1]);
}

int query(int node, int tl, int tr, int x) {
  if (t[node] < x) return -1;
  if (tl == tr) return tl;

  int tm = (tl + tr) / 2;
  if (t[node*2] >= x) return query(node*2, tl, tm, x);
  else return query(node*2+1, tm+1, tr, x);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m; 
  cin >> n >> m;
  vector<int> hoteis(n), grupos(m);
  for (int i = 0; i < n; i++) cin >> hoteis[i];
  for (int i = 0; i < m; i++) cin >> grupos[i];

  build(hoteis, 1, 0, n-1);

  for (int g : grupos) {
    int ans = query(1, 0, n-1, g);
    if (ans != -1) {
      cout << ans + 1 << " ";
      hoteis[ans] -= g;
      update(1, 0, n-1, ans, hoteis[ans]);
    } else {
      cout << 0 << " ";
    }
  }

  cout << "\n";
}
