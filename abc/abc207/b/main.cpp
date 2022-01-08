#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int a,b,c,d;

int solve() {
  int blue = a, red = 0;
  REP(i,a) {
    if (blue <= red) return i;
    blue += b;
    red += c*d;
  }
  return -1;
}

int main() {
  cin >> a >> b >> c >> d;
  cout << solve() << endl;
  return 0;
}