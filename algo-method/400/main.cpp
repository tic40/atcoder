#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;

  cout << min( (n+a-1)/a*b, (n+c-1)/c*d ) << endl;
  return 0;
}