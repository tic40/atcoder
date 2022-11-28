#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> s(h),t(h);
  REP(i,h) cin >> s[i];
  REP(i,h) cin >> t[i];

  vector<string> rs(w),rt(w);
  REP(i,w) REP(j,h) {
    rs[i] += s[h-1-j][i];
    rt[i] += t[h-1-j][i];
  }

  sort(rs.begin(),rs.end());
  sort(rt.begin(),rt.end());
  cout << (rs == rt ? "Yes" : "No") << endl;
  return 0;
}