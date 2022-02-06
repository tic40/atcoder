#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;
  vector<int> a(n+1);
  REP(i,n) cin >> a[i+1];
  REP(i,n) a[i+1] += a[i];
  REP(i,n+1) a[i] %= 360;

  sort(a.begin(),a.end());
  int ans = abs(360-a.back());
  REP(i,(int)a.size()-1) ans = max(ans, a[i+1]-a[i]);

  cout << ans << endl;
  return 0;
}