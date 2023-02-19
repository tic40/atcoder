#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int ans = 0;
  REP(i,m) {
    int b; cin >> b;
    ans += a[b-1];
  }
  cout << ans << endl;
  return 0;
}