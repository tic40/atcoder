#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;

  dsu uf(n+1);
  REP(i,q) {
    int l,r; cin >> l >> r;
    l--;
    uf.merge(l,r);
  }
  cout << (uf.same(0,n) ? "Yes" : "No") << endl;
  return 0;
}