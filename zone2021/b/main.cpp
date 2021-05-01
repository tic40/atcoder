#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  double n,d,h;
  cin >> n >> d >> h;
  double x = 1000;
  REP(i,n) {
    double _d, _h;
    cin >> _d >> _h;
    x = min(x, (h-_h)/(d-_d));
  }

  cout << fixed << setprecision(10) << max(0.0, h-x*d) << endl;
  return 0;
}