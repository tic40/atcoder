#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  ll a; string b;
  cin >> a >> b;
  ll x = (b[0]-'0')*100 + (b[2]-'0')*10 + b[3]-'0';

  cout << a*x / 100 << endl;
  return 0;
}
