#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

ll gcd(ll a, ll b) {
  return b ? gcd(b, a%b) : a;
}
ll lcm(ll a, ll b) {
  return a / gcd(a,b) * b;
}

int main() {
  ll a,b,k;
  cin >> a >> b >> k;
  cout << k * lcm(a,b) << endl;

  return 0;
}