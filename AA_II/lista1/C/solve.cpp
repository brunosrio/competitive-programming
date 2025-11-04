#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e6+10;

struct Node {
  int pares, abertos, fechados;
  Node() : pares(0), abertos(0), fechados(0){}
};

Node t[4*MAXN];

Node merge_node(Node &left, Node &right) {
  Node node;
  int novos_pares = min(left.abertos, right.fechados);
  node.pares = left.pares + right.pares + novos_pares;
  node.abertos = left.abertos + right.abertos - novos_pares;
  node.fechados = left.fechados + right.fechados - novos_pares;
  return node;
}

void build(string &s, int v, int tl, int tr) {
  if (tl == tr) {
    Node node;
    if (s[tl] == ')') node.fechados++;
    else node.abertos++;
    t[v] = node;
    return;
  }

  int tm = (tl+tr) / 2;
  build(s, v*2, tl, tm);
  build(s, v*2+1, tm+1, tr);

  t[v] = merge_node(t[v*2], t[v*2+1]);
}

Node query(int v, int tl, int tr, int l, int r) {
  if (l > r) return Node();
  if (tl == l && tr == r) return t[v];

  int tm = (tl+tr) / 2;
  Node left = query(v*2, tl, tm, l, min(r, tm));
  Node right = query(v*2+1, tm+1, tr, max(l, tm+1), r);

  return merge_node(left, right);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s; cin >> s;
  int n = s.size();
  int q; cin >> q;
  vector<int> ans_list;
  build(s, 1, 0, n-1);

  while (q--) {
    int l, r; cin >> l >> r;
    auto ans = query(1, 0, n-1, l-1, r-1);
    ans_list.push_back(ans.pares * 2);
  }

  for (int x : ans_list)
    cout << x << '\n';
  
  return 0;
}

