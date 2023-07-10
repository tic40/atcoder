#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  auto f = [&](ll x) -> vector<int> {
    vector<int> b;
    while(x) { b.push_back(x%3); x /= 3LL; }
    return b;
  };

  int t; cin >> t;
  REP(_,t) {
    ll n,k; cin >> n >> k;
    auto b = f(n);
    int l = accumulate(b.begin(),b.end(),0);
    bool ok = l <= k && k <= n && (k%2 == l%2);
    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}