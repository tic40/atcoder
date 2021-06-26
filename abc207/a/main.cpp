#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  vector<int> a(3);
  REP(i,3) cin >> a[i];

  sort(a.begin(), a.end());
  cout << (a[1] + a[2]) << endl;
  return 0;
}