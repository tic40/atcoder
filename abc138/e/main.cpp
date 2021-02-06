#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;

// dp[i][j] := i何番目以降に文字種jが現れる最初の位置
int dp[200005][26];

int main() {
  string s,t; cin >> s >> t;
  string s2 = s+s; // 簡単にするためsを2つを連結したものを作る
  int S = s.size(), S2 = s2.size();

  REP(i,26) dp[2*S][i]=INF;

  // 後ろから見ていく
  for(int i = S2-1; 0 <= i; i--) {
    REP(j,26) dp[i][j] = dp[i+1][j];
    dp[i][s2[i] - 'a'] = i+1;
  }

  ll current = 0; // 現在の位置
  for (char c: t) {
    int x = current % S;
    // 現在の位置からの文字cが最初に現れる位置
    int num = dp[x][c - 'a'];
    // 存在しない場合
    if (num == INF) { current = -1; break; }
    current += num - x; // 現在位置から必要な移動分(num-x)を加算する
  }

  cout << current << endl;
  return 0;
}