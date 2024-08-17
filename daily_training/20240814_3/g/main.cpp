#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n+2);
  REP(i,n) cin >> a[i+1];
  n+=2;

  vector<int> dl(n),dr(n);
  for(int i = 1; i < n; i++) dl[i] = min(dl[i-1]+1,a[i]);
  for(int i = n-2; i >= 0; i--) dr[i] = min(dr[i+1]+1,a[i]);

  int ans = 0;
  REP(i,n) ans = max(ans, min(dl[i],dr[i]));
  cout << ans << endl;
  return 0;
}