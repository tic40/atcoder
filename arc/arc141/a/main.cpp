#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
  vector<ll> ten(18);
  ten[0] = 1;
  REP(i,17) ten[i+1] = ten[i]*10;

  int t; cin >> t;
  REP(_,t) {
    ll n; cin >> n;
    int len = to_string(n).size();
    ll ans = ten[len-1] - 1; // 少なくとも1桁下の9... は周期的な数になる

    // n を len/j組に分けることを考える
    for (int j = 1; j <= len/2; j++){
      if (len % j) continue; // 割り切れなければskip

      ll q = 0;
      // j=2のときは1010... j=3のときは 100100...という数を作る
      REP(k,len/j) q += ten[k*j];
      ll p = n/q*q;
      ans = max(ans, p);
    }
    cout << ans << endl;
  }
  return 0;
}