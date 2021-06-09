#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll k,a,b;
int main() {
  cin >> k >> a >> b;

  if (b-a <= 2) {
    cout << k+1 << endl;
    return 0;
  }

  if (k < a-1) {
    cout << k+1 << endl;
    return 0;
  }

  ll ans = a;
  k -= a-1;

  if (k%2) {
    ans++;
    k--;
  }
  ans += k/2*(b-a);
  cout << ans << endl;

  return 0;
}