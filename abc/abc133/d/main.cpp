#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> x(n);
  REP(i,n) x[0] += i%2 ? -a[i] : a[i];

  for(int i = 1; i < n; i++) x[i] = 2*a[i-1] - x[i-1];
  for(int v: x) cout << v << " ";
  cout << endl;
  return 0;
}