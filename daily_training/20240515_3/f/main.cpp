#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  dsu uf(n);
  int ans = 0;
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    if (uf.leader(a) == uf.leader(b)) ans++;
    uf.merge(a,b);
  }
  cout << ans << endl;
  return 0;
}