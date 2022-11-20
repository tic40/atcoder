#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int h,m; cin >> h >> m;

  auto f = [](int h, int m) {
    int nh = h/10*10 + m/10;
    int nm = h%10*10 + m%10;
    return nh < 24 && nm < 60;
  };

  while(!f(h,m)) {
    m = (m+1)%60;
    if (m == 0) h = (h+1)%24;
  }
  cout << h << " " << m << endl;
  return 0;
}