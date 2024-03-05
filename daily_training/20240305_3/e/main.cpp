#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m);
  REP(i,m) cin >> a[i];
  for(int i = 1; i <= n; i++) {
    auto it = lower_bound(a.begin(),a.end(),i);
    cout << *it - i << endl;
  }
  return 0;
}