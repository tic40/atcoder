#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int a, b;
  cin >> a >> b;
  if (a % b == 0) cout << 0;
  else cout << b - (a % b);
  cout << endl;
}