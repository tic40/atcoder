#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n; cin >> n;
  vector a(n,vector<int>(6));
  REP(i,n) REP(j,6) cin >> a[i][j];

  vector<int> dic;
  dic.push_back(0);
  REP(i,n) REP(j,6) dic.push_back(a[i][j]);
  // 重複を除去
  sort(dic.begin(),dic.end());
  dic.erase(unique(dic.begin(),dic.end()),dic.end());

  vector q(n*6+1,vector<int>());
  REP(i,n) REP(j,6) {
    // a[i][j] 以上となる dic の最小の index
    int id = lower_bound(dic.begin(),dic.end(),a[i][j]) - dic.begin();
    // q[id] へ サイコロの番号を追加
    q[id].push_back(i);
  }

  // 出目が i である状態からサイコロを適切に振ったときのサイコロを振る回数の期待値の最大
  vector<double> dp(n*6+1);
  // tot[i] := サイコロ i を降ったときの期待値
  vector<double> tot(n+1);
  double mx = 0;
  // 取りうるサイコロの出目を大きいものから見ていく
  for(int i = dic.size()-1; i >= 0; i--) {
    dp[i] = mx+1;
    for(auto v: q[i]) {
      tot[v] += dp[i] / 6;
      chmax(mx,tot[v]);
    }
  }

  printf("%.10f\n",dp[0]);
  return 0;
}