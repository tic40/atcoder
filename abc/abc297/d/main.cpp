#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll a,b; cin >> a >> b;

  ll cnt = 0;
  while(a != b) {
    if (a < b) swap(a,b);
    ll d = a/b;
    if (a%b == 0) d -= 1;
    a = a - b * d;
    cnt += d;
  }
  cout << cnt << endl;
  return 0;
}