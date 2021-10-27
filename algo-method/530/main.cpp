#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

vector<ll> divisor(ll n) {
  vector<ll> vec;
  for(ll i = 1; i*i <= n; i++) {
    if (n % i == 0) {
      vec.push_back(i);
      if (n / i != i) vec.push_back(n/i);
    }
  }
  return vec;
}

int main() {
  ll n,m;
  cin >> n >> m;

  auto d = divisor(m);
  cout << d.size() << endl;
  return 0;
}