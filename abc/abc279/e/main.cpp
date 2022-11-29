#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m);
  REP(i,m) { cin >> a[i]; a[i]--; }

  vector<int> s(m);
  {
    int p = 0;
    REP(i,m) {
      s[i] = p;
      // 右に移動するとき
      if (a[i] == p) p++;
      // 左に移動するとき
      else if (a[i]+1 == p) p--;
    }
  }

  vector<int> ans(m);
  {
    vector<int> p(n);
    REP(i,n) p[i] = i;
    for(int i = m-1; i >= 0; i--) {
      ans[i] = p[s[i]];
      swap(p[a[i]], p[a[i]+1]);
    }
  }
  REP(i,m) cout << ans[i]+1 << endl;

  return 0;
}