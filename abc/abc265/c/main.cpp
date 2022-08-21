#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector<string> g(h);
  REP(i,h) cin >> g[i];
  vector seen(h, vector<int>(w));

  int ni = 0, nj = 0;
  while(1) {
    seen[ni][nj]++;
    if (seen[ni][nj] == 2) {
      cout << -1 << endl;
      return 0;
    }

    char now = g[ni][nj];
    if (now == 'U' && ni > 0) ni--;
    else if (now == 'D' && ni < h-1) ni++;
    else if (now == 'L' && nj > 0) nj--;
    else if (now == 'R' && nj < w-1) nj++;
    else {
      cout << ni+1 << " " << nj+1 << endl;
      return 0;
    }
  }

  return 0;
}