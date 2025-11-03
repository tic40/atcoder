#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int tot = accumulate(a.begin(),a.end(),0);
  bool ok = false;
  REP(i,n) if (m == tot - a[i]) ok = true;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}