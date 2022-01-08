#include <bits/stdc++.h>
using namespace std;
#define COUT(x) cout<<(x)<<"\n"
#define REP(i,n) for(int i=0;i<n;i++)
template<class T>bool chmin(T &a,const T &b) {if(b<a){a=b; return 1;} return 0;}
const int INF = 1e9;

int n,m;
vector<int> a,b;
vector<vector<int>> c;

int dp[1005][1<<12];
// dp[ i ][ S ] := 最初の i 個の鍵からいくつか選んで、開いた宝箱の集合が S で表されるような場合についての、最小コスト

void solve() {

  // cの入力をbit数値にする
  vector<int> cbit(m,0);
  REP(i,m) {
    for(int x: c[i]) cbit[i] += 1<<x;
  }

  // dp配列初期値はINFしておく
  REP(i,1005) REP(j,1<<n) dp[i][j] = INF;
  dp[0][0] = 0;

  REP(i,m) REP(j,1<<n) {
    // 既に開いた宝箱は鍵が1個増えても関係ないのでそのまま移行する
    chmin(dp[i+1][j], dp[i][j]);

    // 追加した鍵が開けられる宝箱の和を取る
    int nj = j | cbit[i];
    // コストが低いければnjを更新
    chmin(dp[i+1][nj], dp[i][j] + a[i]);
  }

  // 宝箱を全て開けた状態 [m][(1<<n) - 1]
  int ans = dp[m][(1<<n)-1];

  if (ans == INF) COUT(-1); // 宝箱を全て開けられなかった場合
  else COUT(ans);

  return;
}

int main() {
  cin >> n >> m;
  a.resize(m);
  b.resize(m);
  c.resize(m);
  int _c;
  REP(i,m) {
    cin >> a[i] >> b[i];
    REP(j,b[i]) {
      cin >> _c; _c--;
      c[i].push_back(_c);
    }
  }

  solve();
  return 0;
}