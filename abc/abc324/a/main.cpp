#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  bool ok = true;
  REP(i,n-1) if (a[i] != a[i+1]) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}