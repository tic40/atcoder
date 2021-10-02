#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int f(int x) {
  if (x == 0) return 0;
  return x + f(x-1);
}

int main() {
  int n; cin >> n;
  cout << f(n) << endl;
  return 0;
}