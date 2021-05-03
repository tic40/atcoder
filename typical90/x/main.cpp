#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n,k;
vector<int> a,b;

bool solve() {
  ll sum = 0;
  REP(i,n) k -= abs(a[i]-b[i]);
  if (k < 0) return false;
  return k%2 == 0;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  b.resize(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}