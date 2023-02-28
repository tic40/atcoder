#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  sort(a.begin(),a.end());
  sort(b.rbegin(),b.rend());
  int ans = 0;
  REP(i,n) ans += a[i]*b[i];
  cout << ans << endl;
  return 0;
}