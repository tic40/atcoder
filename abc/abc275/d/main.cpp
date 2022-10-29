#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

map<ll,ll> memo;
ll f(ll k) {
  if (k == 0) return 1;
  if (memo[k]) return memo[k];
  return memo[k] = f(k/2) + f(k/3);
}

int main() {
  ll n; cin >> n;
  cout << f(n) << endl;
  return 0;
}