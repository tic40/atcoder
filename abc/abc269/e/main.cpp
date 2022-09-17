#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;

  int x,y;
  REP(ti,2) {
    int ok = n, ng = 0;
    while(ok-ng > 1) {
      int mid = (ok+ng)/2;
      if (ti == 0) printf("? %d %d %d %d\n", 1, mid, 1, n);
      else printf("? %d %d %d %d\n", 1, n, 1, mid);
      fflush(stdout);
      int res; cin >> res;
      if (res != mid) ok = mid;
      else ng = mid;
    }
    x = ok; swap(x,y);
  }
  printf("! %d %d\n",x,y);
  return 0;
}