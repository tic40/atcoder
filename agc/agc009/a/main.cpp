#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<ll> a,b;

void solve() {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  vector<ll> s(n+1);

  REP(i,n) {
    a[i] += s[i];
    s[i+1] = s[i];
    int m = a[i] % b[i];
    if (m) s[i+1] += b[i] - m;
  }
  cout << s[n] << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  REP(i,n) cin >> a[i] >> b[i];

  solve();
  return 0;
}