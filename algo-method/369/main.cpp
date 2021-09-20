#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,k;
  cin >> n >> k;
  vector<double> l(n);
  REP(i,n) cin >> l[i];

  double ok = 0, ng = 100001;
  while(abs(ok - ng) > 1e-6) {
    double mid = (ok + ng) / 2;
    int cnt = 0;
    REP(i,n) {
      cnt += floor( l[i] / mid );
    }
    if (k <= cnt) ok = mid;
    else ng = mid;
  }
  cout << fixed << setprecision(10) << ok << endl;
  return 0;
}