#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;

  double t = 3.5;
  for(int i = 1; i < n; i++) {
    double now = 0;
    for(int j = 1; j <= 6; j++) {
      if ((double)j < t) now += t;
      else now += (double)j;
    }
    t = now / 6.0;
  }

  printf("%0.10f\n", t);
  return 0;
}