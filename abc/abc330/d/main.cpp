#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  vector sr(n+1, vector<int>(n+1));
  vector sc(n+1, vector<int>(n+1));
  REP(i,n) REP(j,n) {
    sr[i][j+1] = sr[i][j] + (s[i][j] == 'o' ? 1 : 0);
    sc[i+1][j] = sc[i][j] + (s[i][j] == 'o' ? 1 : 0);
  }
  ll ans = 0;
  REP(i,n) REP(j,n) {
    if(s[i][j] == 'x') continue;
    int row = sr[i][n] - 1;
    int col = sc[n][j] - 1;
    if (col <= 0 || row <= 0) continue;
    ans += col*row;
  }

  cout << ans << endl;
  return 0;
}