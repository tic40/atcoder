#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<int> t;

bool dp[105][100005];
void solve() {
  int sum = 0;
  REP(i,n) sum += t[i];
  int mid = (sum+1)/2;

  dp[0][0] = true;
  REP(i,n) REP(j,100001) {
    if (dp[i][j]) {
      dp[i+1][j] = true;
      dp[i+1][j+t[i]] = true;
    }
  }

  for(int i = mid; i <= 100000; i++) {
    if (dp[n][i]) {
      cout << i << endl;
      return;
    }
  }

  return;
}

int main() {
  cin >> n;
  t.resize(n);
  REP(i,n) cin >> t[i];

  solve();
  return 0;
}