#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n;
  cin >> n;
  map<int,int> m;
  REP(i,n) {
    int a; cin >> a;
    m[a]++;
  }

  ll ans = 0;
  for(int i = -200; i <= 200; i++) {
    for(int j = i+1; j <= 200; j++) {
      ll add = (i-j)*(i-j);
      ans += add*m[i]*m[j];
    }
  }

  cout << ans << endl;
  return 0;
}