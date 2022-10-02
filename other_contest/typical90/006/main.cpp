#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,k; string s;
  cin >> n >> k >> s;

  // 前計算. memo[i][j] := i項でアルファベットiを選んだときの最も左のsのindex
  vector memo(n+1, vector<int>(26,n));
  for(int i = n-1; 0 <= i; i--) {
    REP(j,26) {
      if (s[i]-'a' == j) memo[i][j] = i;
      else memo[i][j] = memo[i+1][j];
    }
  }

  string ans = "";
  int currentPos = 0;
  REP(i,k) REP(j,26) {
    int nextPos = memo[currentPos][j];
    int maxPossibleLength = n - nextPos;
    if (k - i <= maxPossibleLength) {
      ans += 'a'+j;
      currentPos = nextPos + 1;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}