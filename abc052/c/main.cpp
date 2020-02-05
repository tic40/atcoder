#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const int MOD = 1e9+7;

int main() {
  int n,ans=1; cin>>n;
  vector<ll> cnt(n+1, 0);
  for(int i=1; i<=n; i++){
    int b=i;
    for(int j=2; j<=n; j++) {
      while(b%j==0) {
        b/=j;
        cnt[j]++;
      }
    }
  }
  REP(i,n+1) ans = ans*(cnt[i]+1)%MOD;
  cout<<ans<<endl;
}