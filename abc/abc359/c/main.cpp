#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;

  if ((sx+sy) % 2 == 1) sx--;
  if ((tx+ty) % 2 == 1) tx--;
  ll x = abs(tx-sx), y = abs(ty-sy);
  ll ans = y;
  if (x >= y) ans += (x-y) / 2;
  cout << ans << endl;
  return 0;
}