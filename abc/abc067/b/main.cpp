#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  int l[n];
  REP(i,n) cin >> l[i];
  sort(l,l+n, greater<int>());
  int ans=0;
  REP(i,k) ans+=l[i];
  cout << ans << endl;
  return 0;
}
