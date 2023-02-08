#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  double n; cin >> n;

  auto f = [](double x) { return x*x*x+x; };
  double ok = 100, ng = 0;
  while(ok-ng > 0.0001) {
    double mid = (ok + ng) / 2.0;
    if (f(mid) >= n) ok = mid;
    else ng = mid;
  }

  printf("%.10f\n", ok);
  return 0;
}