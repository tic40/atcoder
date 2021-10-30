#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  ll a,r,n;
  cin >> a >> r >> n;

  REP(i,n-1) {
    a *= r;
    if ((ll)1e9 < a) {
      cout << "large" << endl;
      return 0;
    }
  }

  cout << a << endl;
  return 0;
}