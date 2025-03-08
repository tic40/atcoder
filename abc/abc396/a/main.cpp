#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int ok = 0;
  REP(i,n-2) if (a[i] == a[i+1] && a[i] == a[i+2]) ok = 1;
  cout << (ok == 1 ? "Yes" : "No") << endl;
  return 0;
}
