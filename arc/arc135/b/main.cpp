#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const ll LINF = 1e18;

int main() {
  int n; cin >> n;
  vector<int> s(n);
  REP(i,n) cin >> s[i];

  vector<ll> x;
  x.push_back(0);
  x.push_back(0);

  REP(i,n) x.push_back(s[i] - x[i] - x[i+1]);

  vector<ll> mn(3, LINF);
  REP(i, n+2) mn[i%3] = min(mn[i%3], x[i]);

  if (mn[0] + mn[1] + mn[2] < 0) {
    cout << "No" << endl;
    return 0;
  }

  mn[0] = - (mn[1] + mn[2]);
  REP(i,n+2) x[i] -= mn[i%3];

  cout << "Yes" << endl;
  for(int v: x) cout << v << " ";
  cout << endl;

  return 0;
}