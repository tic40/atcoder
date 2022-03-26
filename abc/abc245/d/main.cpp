#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n+1),c(n+m+1),b(m+1);
  REP(i,n+1) cin >> a[i];
  REP(i,n+m+1) cin >> c[i];
  reverse(a.begin(),a.end());
  reverse(c.begin(),c.end());

  REP(i,m+1) {
    b[i] = c[i] / a[0];
    REP(j,n+1) c[i+j] -= a[j] * b[i];
  }

  reverse(b.begin(),b.end());
  for(int v: b) cout << v << endl;
  return 0;
}