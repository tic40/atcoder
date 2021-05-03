#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  ll a,b,c;
  cin >> a >> b >> c;

  ll r = 1;
  REP(i,b) r *= c;
  a < r ? cout << "Yes" : cout << "No";
  return 0;
}