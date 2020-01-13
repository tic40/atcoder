#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n,k,m;
  cin>>n>>k>>m;
  int a[n];
  REP(i,n-1) { cin>>a[i]; a[i]-=m; }

  int sum = 0;
  REP(i,n-1) { sum+=a[i]; }
  int ans = max(-m, -sum);
  if ((ans+m) > k) { cout << -1; }
  else { cout << ans+m; }
  cout << endl;
}
