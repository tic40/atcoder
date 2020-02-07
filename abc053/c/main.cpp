#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  ll x,ans; cin >> x;
  ans = x/11*2;
  if (x%11>0) ans++;
  if (x%11>6) ans++;
  cout << ans << endl;
}