#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int t; cin >> t;
  REP(_,t) {
    ll n,d,k; cin >> n >> d >> k;
    k--;
    ll r = n / gcd(n,d);
    ll ans = d * k % n + k / r;
    cout << ans << endl;
  }
  return 0;
}