#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int n;
int a[100000];

ll solve(ll t){
  ll res = 0, sum = 0;
  for (ll i = 0; i < n; i++, t = -t){
    sum += a[i];
    if (sum * t > 0) continue;
    res += abs(sum - t);
    sum += t * abs(sum - t);
  }
  return res;
}

int main(){
  cin >> n;
  REP(i,n) cin >> a[i];
  ll res = solve(1);
  res = min(res, solve(-1));
  cout << res << endl;
  return 0;
}