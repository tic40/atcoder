#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int x,y; cin >> x >> y;
  int cnt = 0;
  for(int i = 1; i <= 6; i++) for(int j = 1; j <= 6; j++) {
    if (i+j >= x || abs(i-j) >= y) cnt++;
  }
  printf("%.10f\n", (double)cnt/36.0);
  return 0;
}