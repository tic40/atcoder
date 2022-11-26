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

  vector rs(w,vector<char>(h));
  vector rt(w,vector<char>(h));
  REP(i,w) REP(j,h) {
    rs[i][j] = s[h-1-j][i];
    rt[i][j] = t[h-1-j][i];
  }

  REP(i,w) {
    bool ok = false;
    for(int j = i; j < w; j++) {
      if (rs[j] == rt[i]) {
        swap(rs[i],rs[j]);
        ok = true; break;
      }
    }
    if (!ok) { cout << "No" << endl; return 0; }
  }
  cout << "Yes" << endl;
  return 0;
}