#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,m;
string s,t;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

void solve() {
  ll g = gcd(n,m);
  ll l = n/g*m;
  n /= g;
  m /= g;
  bool ok = true;
  REP(i,g) {
    if (s[i*n] != t[i*m]) ok = false;
  }
  cout << (ok ? l : -1) << endl;

  return;
}

int main() {
  cin >> n >> m;
  cin >> s >> t;

  solve();
  return 0;
}