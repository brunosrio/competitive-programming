#include <bits/stdc++.h>
using namespace std;
using ll = long long;;

const int MAXN = 1e5+10;

vector<vector<int>> t(4*MAXN, vector<int>(2, -1));

vector<int> merge_nodes(vector<int>& a, vector<int>& b) {
  vector<int> merged(4);
  merge(a.begin(), a.end(), b.begin(), b.end(), merged.begin());
  return {merged[2], merged[3]};
}

void build(vector<int>& a, int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = {-1, a[tl]};
    return;
  }

  int tm = (tl+tr) / 2;
  build(a, v*2, tl, tm);
  build(a, v*2+1, tm+1, tr);

  t[v] = merge_nodes(t[v*2], t[v*2+1]);
}

void update(int v, int pos, int newval, int tl, int tr) {
  if (tl == tr) {
    t[v] = {-1, newval};
    return;
  }
  
  int tm = (tl + tr) / 2;
  if (pos <= tm) {
    update(v*2, pos, newval, tl, tm);
  } else {
    update(v*2+1, pos, newval, tm+1, tr);
  }
  t[v] = merge_nodes(t[v*2], t[v*2+1]);
}

vector<int> max_sum(int v, int tl, int tr, int l, int r) {
  if (l > r) return {-1, -1};
  if (tl == l && tr == r) return t[v];
  
  int tm = (tl + tr) / 2;
  auto left = max_sum(v*2, tl, tm, l, min(r, tm));
  auto right = max_sum(v*2+1, tm+1, tr, max(l, tm+1), r);

  return merge_nodes(left, right);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> vetor(n);
  for (int i = 0; i<n; i++) cin >> vetor[i];

  build(vetor, 1, 0, n-1);

  int q; cin >> q;
  while (q--) {
    char op; cin >> op;
    if (op == 'U') {
      int pos, x; cin >> pos >> x;
      update(1, pos-1, x, 0, n-1);
    } else {
      int l, r; cin >> l >> r;
      auto ans = max_sum(1, 0, n-1, l-1, r-1);
      cout << ans[0] + ans[1] << "\n";
    }
  }

  return 0;
}