#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int p; cin >> p;

  if (p == 1) {
    cout << 1 << endl;
    return 0;
  }

  int cur = 1, i = 1;
  while(cur * i < p) {
    cur *= i;
    i++;
  }
  i--;

  int ans = 0;
  while(0 < i) {
    ans += p / cur;
    p %= cur;
    cur /= i;
    i--;
  }

  cout << ans << endl;
  return 0;
}