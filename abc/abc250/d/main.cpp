#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

vector<int> eratosthenes(int n) {
  vector<int> p, is_prime(n+1, 1);
  for(int i=2; i<=n; i++) {
    if(is_prime[i]) {
      for(int j=2*i; j<=n; j+=i) is_prime[j] = 0;
      p.push_back(i);
    }
  }
  return p;
}

ll n;
bool f(ll p, ll q) {
  REP(_,3) {
    if (n/q < p) return false;
    p *= q;
  }
  return true;
}

int main() {
  cin >> n;
  auto p = eratosthenes(1e6);
  p.push_back(1e9);
  int sz = p.size();

  ll ans = 0;
  REP(i,sz) {
    int ok = i;
    int ng = sz-1;
    while (abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      if (f(p[i],p[mid])) ok = mid;
      else ng = mid;
    }
    ans += ok - i;
  }

  cout << ans << endl;
  return 0;
}