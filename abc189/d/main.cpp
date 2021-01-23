#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<string> s;
ll dp[65][2]; // dp[n][x]:= n個までの文字列で結果がx(0/1)になるケースの数

void solve() {
  dp[0][0]=1; // dp[0][0]の場合は false のみで1通り
  dp[0][1]=1; // true のみで1通り

  REP(i,n) {
    // jの状態にｋを追加する処理
    // 4通りの組み合わせ: 00,01,10,11
    REP(j,2) REP(k,2) {
      if (s[i] == "AND") {
        // ANDは論理積のため j&k
        dp[i+1][j&k] += dp[i][j];
      } else {
        // ORは論理和 j|k
        dp[i+1][j|k] += dp[i][j];
      }
    }
  }

  // n個の文字列で結果が1になるケースの数
  cout << dp[n][1] << endl;
}

int main() {
  cin >> n;
  s.resize(n);
  REP(i,n) cin >> s[i];

  solve();
  return 0;
}