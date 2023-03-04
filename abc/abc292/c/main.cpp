#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

vector<ll> memo(2e5+1,-1);
ll divisor_num(ll n) {
  if (memo[n] != -1) return memo[n];
  ll res = 0;
  for (int i = 1; i*i <= n; i++) {
    if (n % i == 0) {
      res++;
      res += i != n/i;
    }
  }
  return memo[n] = res;
}

int main() {
  int n; cin >> n;
  ll ans = 0;
  for(ll ab = 0; ab <= n; ab++) {
    ll cd = n - ab;
    auto add = divisor_num(ab);
    auto cdd = divisor_num(cd);
    ans += add*cdd;
  }
  cout << ans << endl;
  return 0;
}