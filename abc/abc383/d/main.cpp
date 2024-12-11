#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;
  int n2 = sqrt(n);
  vector<int> is_prime(n2+1,1);
  for(int i = 2; i <= n2; i++) {
    for(int j=i*2; j <= n2; j+=i) is_prime[j] = 0;
  }
  vector<int> p;
  for(int i = 2; i <= n2; i++) if (is_prime[i]) p.push_back(i);

  int ans = 0;
  for(auto v: p) {
    int cnt = 1; ll now = v;
    while(cnt < 8 && now*v <= n) { now *= v; cnt++; }
    if (cnt < 8) break;
    ans++;
  }

  REP(i,(int)p.size()) for(int j = i+1; j < (int)p.size(); j++) {
    ll a = (ll)p[i]*p[i];
    ll b = (ll)p[j]*p[j];
    if (a > n/b) break;
    ans++;
  }
  cout << ans << endl;
  return 0;
}