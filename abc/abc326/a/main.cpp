#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int x,y; cin >> x >> y;
  int d = y-x;
  if (d > 2) cout << "No" << endl;
  else if (d < -3) cout << "No" << endl;
  else cout << "Yes" << endl;

  return 0;
}