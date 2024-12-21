#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector<int> a(3);
  REP(i,3) cin >> a[i];
  sort(a.begin(),a.end());
  int ok = 0;
  if (a[0]+a[1] == a[2]) ok |= 1;
  if (a[0] == a[1] && a[0] == a[2]) ok |= 1;

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}