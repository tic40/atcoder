#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int h,w;
  cin >> h >> w;

  vector<string> s(h);
  REP(i,h) cin >> s[i];

  int ans = 0;
  REP(i,h) REP(j,w) if (s[i][j] == '#') ans++;
  cout << ans << endl;
  return 0;
}