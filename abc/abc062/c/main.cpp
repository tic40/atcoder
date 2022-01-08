#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

ll solve(ll h,ll w) {
  ll b1,b2,b3,res=1001001001;
  ll sum=h*w;
  for (int i=1; i<h; i++) {
    b1 = i*w;

    b2 = (h-i)*(w/2);
    b3 = sum-b2-b1;
    if (b2>0 && b3>0) res = min(res, max(b1,max(b2,b3)) - min(b1,min(b2,b3)));

    b2 = ((h-i)/2)*w;
    b3 = sum-b2-b1;
    if (b2>0 && b3>0) res = min(res, max(b1,max(b2,b3)) - min(b1,min(b2,b3)));
  }
  return res;
}

int main() {
  ll h,w; cin >> h >> w;
  ll ans = min(solve(h,w),solve(w,h));
  cout << ans << endl;
  return 0;
}