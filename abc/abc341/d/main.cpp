#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

int main() {
  ll n,m,k; cin >> n >> m >> k;
  ll l = lcm(n,m);
  ll ng = 0, ok = 1e18;
  while(abs(ok-ng) > 1) {
    ll mid = (ok+ng)/2;
    ll now = 0;
    now = mid/n + mid/m;
    now -= mid / l * 2;
    if (now < k) ng = mid;
    else ok = mid;
  }
  cout << ok << endl;
  return 0;
}