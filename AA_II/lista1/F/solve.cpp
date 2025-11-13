#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;
#define ll long long

const ll MINVAL = -1e18;

struct Node {
  ll soma, prefix_sum, sufix_sum, best;
  Node(): soma(0), prefix_sum(0), sufix_sum(0), best(0){}
  Node(ll val): soma(val), prefix_sum(val), sufix_sum(val), best(val){}
};

Node t[20*(ll)MAXN];

Node merge_nodes(Node left, Node right) {
  Node parent;
  parent.soma = left.soma + right.soma;
  parent.prefix_sum = max(left.prefix_sum, left.soma + right.prefix_sum);
  parent.sufix_sum = max(right.sufix_sum, right.soma + left.sufix_sum);
  parent.best = max({left.best, right.best, left.sufix_sum + right.prefix_sum});
  return parent;
}

void build(vector<ll>& a, int v, int tl, int tr) {
  if (tl == tr) {
    Node node(a[tl]);
    t[v] = node;
    return;
  } 

  int tm = (tl+tr)/2;
  build(a, v*2, tl, tm);
  build(a, v*2+1, tm+1, tr);

  t[v] = merge_nodes(t[v*2], t[v*2+1]);
}

void update(int v, int tl, int tr, int pos, int newval) {
  if (tl == tr) {
    t[v] = Node(newval);
    return;
  }

  int tm = (tl+tr)/2;
  if (pos <= tm) update(v*2, tl, tm, pos, newval);
  else update(v*2+1, tm+1, tr, pos, newval);

  t[v] = merge_nodes(t[v*2], t[v*2+1]);
}

Node query(int v, int tl, int tr, int l, int r) {
  if (l > r){
    Node node(MINVAL);
    node.soma = 0;
    return node;  
  }

  if (tl == l && tr == r) return t[v];

  int tm = (tl+tr)/2;
  Node left = query(v*2, tl, tm, l, min(r, tm));
  Node right = query(v*2+1, tm+1, tr, max(l, tm+1), r);
  
  return merge_nodes(left, right);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  vector<ll> vetor(n);
  for (int i = 0; i < n; i++) cin >> vetor[i];
  build(vetor, 1, 0, n-1);
  int q; cin >> q;
  while (q--) {
    int op, x, y; cin >> op >> x >> y; 
    if (op) {
      cout << query(1, 0, n-1, x-1, y-1).best << "\n";
    } else {
      update(1, 0, n-1, x-1, y);
    }
  }

  return 0;
}