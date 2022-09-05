#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  vector<int> x(2),y(2),r(2);
  REP(i,2) cin >> x[i] >> y[i] >> r[i];

  // 中心間距離
  double d = sqrt(pow(x[0]-x[1],2) + pow(y[0]-y[1],2));

  if (d < abs(r[0]-r[1])) cout << 1;
  else if (d == abs(r[0]-r[1])) cout << 2;
  else if (d < r[0]+r[1]) cout << 3;
  else if (d == r[0]+r[1]) cout << 4;
  else cout << 5;

  cout << endl;
  return 0;
}