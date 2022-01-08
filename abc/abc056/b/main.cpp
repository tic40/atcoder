#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int w,a,b; cin >> w >> a >> b;
  cout << max(0, abs(a-b)-w) << endl;
  return 0;
}
