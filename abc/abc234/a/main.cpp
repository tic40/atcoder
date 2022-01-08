#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int f(int t) {
  return t*t + 2*t + 3;
}

int main() {
  int t; cin >> t;
  cout << f(f(f(t)+t) + f(f(t))) << endl;
  return 0;
}