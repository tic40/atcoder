#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int ok = 1;
  // a[1]/a[0] == a[i+1]/a[i]
  // a[1]*a[i] == a[i+1]*a[0];
  REP(i,n-1) ok &= (ll)a[1] * a[i] == (ll)a[i+1] * a[0];
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}