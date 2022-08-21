#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int x,y,n; cin >> x >> y >> n;
  int sumx = x*n;
  int sumy = y*(n/3);
  if (n%3) sumy += x * (n%3);
  cout << min(sumx, sumy) << endl;

  return 0;
}