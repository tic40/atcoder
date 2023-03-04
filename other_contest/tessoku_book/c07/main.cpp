#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> c(n);
  REP(i,n) cin >> c[i];

  sort(c.begin(),c.end());
  vector<int> s(n+1);
  REP(i,n) s[i+1] = s[i]+c[i];

  int q; cin >> q;
  REP(_,q) {
    int x; cin >> x;
    int ans = upper_bound(s.begin(),s.end(),x) - s.begin() - 1;
    cout << ans << endl;
  }
  return 0;
}