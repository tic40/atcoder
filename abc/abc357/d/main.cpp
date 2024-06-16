#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353; // modint1000000007;

int main() {
  ll n; cin >> n;
  mint a = 1;
  {
    ll x = n;
    while(x) { a *= 10; x /= 10; }
  }

  mint s = n * (a.pow(n) - 1) / (a - 1);
  cout << s.val() << endl;
  return 0;
}