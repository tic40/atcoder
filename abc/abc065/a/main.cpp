#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int x,a,b; cin >> x >> a >> b;
  if (b-a > x) cout << "dangerous";
  else if (b-a > 0) cout << "safe";
  else cout << "delicious";
  cout << endl;
  return 0;
}
