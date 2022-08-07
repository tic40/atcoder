#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  int n,C;
  cin >> n >> C;
  vector d(C,vector<int>(C));
  REP(i,C) REP(j,C) cin >> d[i][j];
  vector c(n,vector<int>(n));
  REP(i,n) REP(j,n) {
    cin >> c[i][j];
    c[i][j]--;
  }

  // cost[i][j] := i(0-2)のときの,色をjにするときの総コスト
  vector cost(3,vector<int>(C));
  REP(x,C) REP(i,n) REP(j,n) {
    cost[ (i+j)%3 ][x] += d[ c[i][j] ][x];
  }

  int ans = INF;
  REP(i,C) REP(j,C) REP(k,C) {
    if (i==j || j==k || k==i) continue;
    ans = min(ans, cost[0][i]+cost[1][j]+cost[2][k]);
  }

  cout << ans << endl;
  return 0;
}