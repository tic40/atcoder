#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
typedef pair<int,int> P;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

P f(int x) {
  int a = x%10, b = 0;
  while(x) {
    b = x%10;
    x/=10;
  }
  return P(a, b);
}

int main() {
  int n, ans = 0;
  cin >> n;
  map<P, int> freq;

  for(int i = 1; i <= n; i++) freq[f(i)]++;
  for(int i = 1; i <= n; i++) {
    P p = f(i);
    P rp = P(p.second, p.first);
    ans += freq[rp];
  }

  cout << ans << endl;
  return 0;
}