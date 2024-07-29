#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w,si,sj;
  cin >> h >> w >> si >> sj;
  si--; sj--;
  vector<string> c(h);
  REP(i,h) cin >> c[i];
  string x; cin >> x;

  for(auto v: x) {
    int ti = si, tj = sj;
    if (v == 'L') sj--;
    if (v == 'R') sj++;
    if (v == 'U') si--;
    if (v == 'D') si++;
    if (si < 0 || sj < 0 || si >= h || sj >= w || c[si][sj] == '#') {
      si = ti, sj = tj;
    }
  }
  cout << si+1 << " " << sj+1 << endl;
  return 0;
}