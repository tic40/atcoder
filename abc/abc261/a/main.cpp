#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int l1,r1,l2,r2;
  cin >> l1 >> r1 >> l2 >> r2;

  int r = min(r1,r2);
  int l = max(l1,l2);
  cout << max(0, r-l) << endl;
  return 0;
}