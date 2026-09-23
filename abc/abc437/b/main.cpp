#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w,n; cin >> h >> w >> n;
  vector a(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> a[i][j];
  set<int> st;
  REP(i,n) { int b; cin >> b; st.insert(b); }

  int ans = 0;
  REP(i,h) {
    int cnt = 0;
    REP(j,w) cnt += st.count(a[i][j]);
    ans = max(ans,cnt);
  }
  cout << ans << endl;
  return 0;
}
