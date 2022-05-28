#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector<pair<int,int>> p;
  REP(i,h) REP(j,w) if(s[i][j] == 'o') p.emplace_back(i,j);
  int ans = abs(p[0].first - p[1].first) + abs(p[0].second - p[1].second);
  cout << ans << endl;

  return 0;
}