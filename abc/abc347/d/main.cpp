#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll a,b,c; cin >> a >> b >> c;

  ll x = c;
  vector<int> cbit(60);
  int i = 0;
  while(x) {
    cbit[i]=(x % 2LL);
    x /= 2;
    i++;
  }
  reverse(cbit.begin(),cbit.end());

  ll ansa = 0, ansb = 0;
  REP(i,60) if (cbit[i] == 1) {
    if (a > b) {
      ansa += 1LL << (59-i);
      a--;
    } else {
      ansb += 1LL << (59-i);
      b--;
    }
  }
  REP(i,60) if (cbit[i] == 0) {
    if (a > 0 && b > 0) {
      ansa += 1LL << (59-i);
      ansb += 1LL << (59-i);
      a--; b--;
    }
  }

  if (a != 0 || b != 0) {
    cout << -1 << endl;
  } else {
    cout << ansa << " " << ansb << endl;
  }
  return 0;
}