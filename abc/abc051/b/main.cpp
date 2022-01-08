#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int k,s,ans=0; cin>>k>>s;
  REP(x,k+1) { REP(y,k+1) { int z = s-(x+y); if (0<=z && z<=k) ans++; } }
  cout << ans << endl;
}