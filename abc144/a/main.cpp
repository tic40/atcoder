#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main() {
  int a, b;
  cin >> a >> b;
  if (a < 10 && b < 10) cout << a*b;
  else cout << -1;
  cout << endl;
}