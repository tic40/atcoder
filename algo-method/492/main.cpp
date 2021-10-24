#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;
  vector<pair<int,int>> vp(n);
  REP(i,n) {
    int a; cin >> a;
    vp[i] = { a, i };
  }
  sort(vp.rbegin(), vp.rend());

  vector<int> ans(n);
  int cnt = 0;
  REP(i,n) {
    auto [ score, num ] = vp[i];
    if (0 < i && vp[i-1].first != vp[i].first) cnt++;
    ans[num] = cnt;
  }

  REP(i,n) cout << ans[i] << endl;
  return 0;
}