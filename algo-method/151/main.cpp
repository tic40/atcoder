#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int a = 0b11101;
  int b = 0b11001;
  int ans = 0;
  REP(i, 5) {
    if (a >> i & 1 && b >> i & 1) ans++;
  }
  cout << ans << endl;
  return 0;
}