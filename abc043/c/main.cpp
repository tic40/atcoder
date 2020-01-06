#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n,ans=INT_MAX;
  cin >> n;
  int a[n];
  int l=1000,m=0;
  REP(i,n) { cin>>a[i]; l=min(l,a[i]); m=max(m,a[i]); }
  if (l == m) { cout << 0 << endl; return 0; }
  for(int x = l; x <= m; x++) {
    int sum = 0;
    REP(i,n) sum += pow(a[i]-x, 2);
    ans = min(ans, sum);
  }
  cout << ans << endl;
}