#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector<int> a(9),b(8);
  REP(i,9) cin >> a[i];
  REP(i,8) cin >> b[i];

  int sa = accumulate(a.begin(),a.end(),0);
  int sb = accumulate(b.begin(),b.end(),0);
  int d = sa - sb;
  cout << d+1 << endl;
  return 0;
}