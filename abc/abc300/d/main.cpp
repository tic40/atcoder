#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = unsigned long long;

vector<int> eratosthenes(int n) {
  vector<int> res;
  vector<bool> is_prime(n+1,true);
  for(int i = 2; i <= n; i++) {
    if (!is_prime[i]) continue;
    for(int j = 2*i; j <= n; j+=i) is_prime[j] = false;
    res.push_back(i);
  }
  return res;
}

int main() {
  ll n; cin >> n;
  auto p = eratosthenes(sqrt(n));
  sort(p.begin(),p.end());
  int sz = p.size();

  ll ans = 0;
  REP(i,sz) {
    ll a = p[i];
    ll a2 = a*a;
    for(int j = i+1; j < sz; j++) {
      ll b = p[j];
      ll a2b = a2 * b;
      if (a2 > n || a2b > n) break;
      ll c = sqrt(n / a2b);
      if (c < b) break;
      auto it = upper_bound(p.begin(),p.end(),c);
      int id = it - p.begin();
      ans += max(0, id-1-j);
    }
  }

  cout << ans << endl;
  return 0;
}