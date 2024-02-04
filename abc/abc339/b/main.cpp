#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int h,w,n; cin >> h >> w >> n;

  vector<string> a(h,string(w,'.'));
  int dir = 0; // 0: u, 1: r, 2: d, 3: l
  int i = 0, j = 0;
  REP(_,n) {
    if (a[i][j] == '.') {
      a[i][j] = '#';
      dir = (dir+1) % 4;
    } else {
      a[i][j] = '.';
      dir = (dir-1+4)%4;
    }
    i += di[dir];
    i = (i + h) % h;
    j += dj[dir];
    j = (j + w) % w;
  }

  REP(i,h) cout << a[i] << endl;
  return 0;
}