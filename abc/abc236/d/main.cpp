#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;

int n;
ll a[20][20];
ll ans = 0;

void dfs(vector<bool> memo, ll tot, int idx) {
  while(memo[idx]) {
    idx++;
    if (2*n <= idx) break;
  }
  memo[idx] = true;

  if(idx >= 2*n) {
    ans = max(ans,tot);
    return;
  }

  for(int j = idx+1; j < 2*n; j++) {
    if (!memo[j]) {
      memo[j] = true;
      dfs(memo, tot ^ a[idx][j], idx+1);
      memo[j] = false;
    }
  }

  return;
}

int main() {
  cin >> n;
  REP(i,2*n) {
    for(int j = i+1; j < 2*n; j++) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }

  vector<bool> memo(n*2+5);
  dfs(memo, 0, 0);

  cout << ans << endl;
  return 0;
}