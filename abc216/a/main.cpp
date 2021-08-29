#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  double x;
  cin >> x;
  int y = (int)(x * 10) % 10;
  cout << floor(x);
  if (y <= 2) cout << "-";
  else if (y <= 6) ;// do nothing
  else cout << "+";

  cout << endl;
  return 0;
}