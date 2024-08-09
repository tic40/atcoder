#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

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
  auto er = eratosthenes(sqrt(n));
  int sz = er.size();

  int ans = 0;
  REP(i,sz) for(int j = i+1; j < sz; j++) {
    ll a = er[i], b = er[j];
    ll c = sqrt( n / (a*a*b) );
    if (c <= b) break;
    int idx = upper_bound(er.begin(),er.end(),c) - er.begin();
    ans += max(0, idx-j-1);
  }
  cout << ans << endl;
  return 0;
}