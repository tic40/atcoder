#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int s,a,b,x; cin >> s >> a >> b >> x;
  int r = x % (a+b);
  cout << (x/(a+b) * a * s) + (min(r,a) * s) << endl;
  return 0;
}