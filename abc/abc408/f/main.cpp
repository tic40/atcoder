#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int op(int a, int b) { return max(a,b); }
int e() { return -1; }

int main() {
  int n,D,R; cin >> n >> D >> R;
  vector<int> H(n);
  REP(i,n) { cin >> H[i]; H[i]--; }
  vector<int> hi(n);
  REP(i,n) hi[H[i]] = i;

  vector<int> dp(n);
  // range max tree
  segtree<int,op,e> seg(n);
  REP(h,n) {
    if (h >= D) {
      int j = hi[h-D];
      seg.set(j,dp[j]);
    }
    int i = hi[h];
    int l = max(0,i-R), r = min(n,i+R+1);
    dp[i] = seg.prod(l,r)+1;
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;
  return 0;
}