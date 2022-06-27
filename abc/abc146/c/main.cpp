#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  ll a,b,x;
  cin >> a >> b >> x;

  ll ok = 0, ng = 1e9+1;
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    ll d = to_string(mid).size();

    if (a * mid <= x-b*d) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}
