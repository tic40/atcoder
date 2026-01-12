#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int x,y,z; cin >> x >> y >> z;
  if ( (x-z*y) % (z-1) != 0 ) { cout << "No" << endl; return 0; }
  if (x - z*y < 0) { cout << "No" << endl; return 0; }
  cout << "Yes" << endl;
  return 0;
}