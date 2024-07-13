#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  vector<int> x(3),y(3);
  REP(i,3) cin >> x[i] >> y[i];

  int a = pow(x[0]-x[1],2) + pow(y[0]-y[1],2);
  int b = pow(x[1]-x[2],2) + pow(y[1]-y[2],2);
  int c = pow(x[2]-x[0],2) + pow(y[2]-y[0],2);

  bool yes = a + b == c || b + c == a || c + a == b;
  cout << (yes ? "Yes" : "No") << endl;
  return 0;
}