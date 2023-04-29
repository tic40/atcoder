#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

mint mem[101][101][2];
bool visited[101][101][2];

int main() {
  int n,a,b,p,q;
  cin >> n >> a >> b >> p >> q;

  mint ip = mint(1)/p;
  mint iq = mint(1)/q;

  // メモ化再帰
  // a: 高橋, b: 青木, t: どちらの手番か
  auto f = [&](auto f, int a, int b, int t) -> mint {
    if (a >= n) return 1; // 高橋の勝ち
    if (b >= n) return 0;
    if (visited[a][b][t]) return mem[a][b][t];
    visited[a][b][t] = true;

    mint res;
    if (t == 0) {
      for(int i = 1; i <= p; i++) res += f(f,a+i,b,1);
      res *= ip;
    } else {
      for(int i = 1; i <= q; i++) res += f(f,a,b+i,0);
      res *= iq;
    }
    return mem[a][b][t] = res;
  };

  cout << f(f,a,b,0).val() << endl;
  return 0;
}