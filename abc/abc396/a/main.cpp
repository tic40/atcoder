#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n; cin >> n;
  vector<int> a(n);
  int ok = 0;
  REP(i,n) cin >> a[i];
  REP(i,n-2) ok |= (a[i] == a[i+1] && a[i] == a[i+2]);
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
