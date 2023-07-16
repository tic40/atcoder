#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,p,q; cin >> n >> p >> q;
  vector<int> d(n);
  REP(i,n) cin >> d[i];
  sort(d.begin(),d.end());

  int ans = min(q+d[0],p);
  cout << ans << endl;
  return 0;
}