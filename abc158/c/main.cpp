#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int a,b;
  cin >> a >> b;
  int x1 = a/0.08;
  int x2 = b/0.1;

  for(int i = min(x1,x2); i <= max(x1,x2)+1; i++) {
    if (floor(i * 0.08) == a && floor(i*0.1) == b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}