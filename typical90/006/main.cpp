#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int memo[100005][26];

int main() {
  int n,k;
  string s;
  cin >> n >> k >> s;

  int memo[n+1][26];
  REP(i,26) memo[n][i] = n;

  // 前計算
  for(int i = n-1; 0 <= i; i--) {
    REP(j,26) {
      if (s[i]-'a' == j) memo[i][j] = i;
      else memo[i][j] = memo[i+1][j];
    }
  }

  string ans = "";
  int currentPos = 0;
  // 貪欲
  REP(i,k) {
    REP(j,26) {
      int nextPos = memo[currentPos][j];
      int maxPossibleLength = s.size() - nextPos - 1 + (i+1);
      if (k <= maxPossibleLength) {
        ans += 'a'+j;
        currentPos = nextPos + 1;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}