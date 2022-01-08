#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  ll n,a,b;
  cin >> n >> a >> b;

  if (b < a) cout << 0 << endl;
  else if (a == b) cout << 1 << endl;
  else if (n==1) cout << 0 << endl;
  else cout << b * (n-2) - a * (n-2) + 1 << endl;

  return 0;
}