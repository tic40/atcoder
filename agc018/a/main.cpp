#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int n,k;
vector<int> a;

bool solve() {
  int mx = 0;
  REP(i,n) {
    if (a[i] == k) return true;
    mx = max(mx,a[i]);
  }
  if (mx < k) return false;

  int g = a[0];
  REP(i,n) g = gcd(g,a[i]);

  return k % g == 0;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  if (solve()) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;

  return 0;
}