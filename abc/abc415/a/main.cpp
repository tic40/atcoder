#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int x; cin >> x;
  int ok = 0;
  REP(i,n) ok |= a[i] == x;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}