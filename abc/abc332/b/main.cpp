#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int k,g,m; cin >> k >> g >> m;
  int ng = 0,mg = 0;
  REP(i,k) {
    if (ng == g) ng = 0;
    else if (mg == 0) mg = m;
    else {
      ng += mg; mg = 0;
      if (ng > g) { mg = ng-g; ng = g; }
    }
  }

  cout << ng << " " << mg << endl;
  return 0;
}