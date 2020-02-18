#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  ll total = n*(n-1) / 2;
  ll mid = sqrt(2*k+1);

  cout << total << endl;
  cout << mid << endl;
}