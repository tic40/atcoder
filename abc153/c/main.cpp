#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  ll n,k,ans=0;
  cin >> n >> k;
  vector<ll> h(n);
  REP(i,n) cin >> h[i];
  sort(h.begin(),h.end(),greater<int>());
  for (int i = k; i < n; i++) ans+=h[i];
  cout << ans << endl;
}