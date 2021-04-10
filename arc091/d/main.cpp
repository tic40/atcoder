#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  ll n,k; cin >> n >> k;

  if (k==0) {
    cout << n*n << endl;
    return 0;
  }

  ll ans = 0;
  for(ll b = k+1; b <= n; b++) {
    ans += n/b * (b-k);
    ans += max(0LL, (n%b+1-k));
  }

  cout << ans << endl;
  return 0;
}