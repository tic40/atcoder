#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,a,b,p,q;
  cin >> n >> a >> b >> p >> q;

  mint ip = mint(1)/p;
  mint iq = mint(1)/q;

  vector mem(n, vector(n, vector<mint>(2)));
  vector visited(n, vector(n, vector<bool>(2)));

  // メモ化再帰. a: 高橋, b: 青木, t: どちらの手番か
  auto dfs = [&](auto dfs, int a, int b, int t) -> mint {
    if (a >= n) return 1;
    if (b >= n) return 0;
    if (visited[a][b][t]) return mem[a][b][t];
    mint res;
    if (t == 0) {
      for(int i = 1; i <= p; i++) res += dfs(dfs,a+i,b,1);
      res *= ip;
    } else {
      for(int i = 1; i <= q; i++) res += dfs(dfs,a,b+i,0);
      res *= iq;
    }

    visited[a][b][t] = true;
    return mem[a][b][t] = res;
  };

  cout << dfs(dfs,a,b,0).val() << endl;
  return 0;
}