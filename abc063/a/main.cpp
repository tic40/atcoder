#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int a,b; cin >> a >> b;
  int sum = a+b;
  if (sum >= 10) cout << "error" << endl;
  else cout << sum << endl;
  return 0;
}
