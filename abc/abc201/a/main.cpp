#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  vector<int> a(3);
  REP(i,3) cin >> a[i];
  sort(a.begin(), a.end());

  bool ok = (a[2] - a[1] == a[1] - a[0]);
  if (ok) cout << "Yes" << endl;
  else cout << "No"<< endl;

  return 0;
}