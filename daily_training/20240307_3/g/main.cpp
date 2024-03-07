#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll a,b; cin >> a >> b;
  ll ans = 0;
  while(a!=b) {
    if (a < b) swap(a,b);
    ll cnt = (a - b + b - 1) / b;
    a -= b*cnt;
    ans += cnt;
  }

  cout << ans << endl;
  return 0;
}