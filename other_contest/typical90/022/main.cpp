#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

int main() {
  ll a,b,c;
  cin >> a >> b >> c;

  // 一辺の長さ
  ll x = gcd(a, gcd(b,c));
  ll ans = (a+b+c)/x - 3;
  cout << ans << endl;
  return 0;
}