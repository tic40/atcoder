#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = 1e9; // numeric_limits<int>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n,q; cin >> n >> q;
  // dp[i][l][r] := i 操作目で l,r の位置にいるときの最小手数
  vector<int> dp(n,INF);
  char lh = 'L';
  int lt = 0;
  dp[1] = 0;

  REP(_,q) {
    char h; int t; cin >> h >> t; t--;
    rotate(dp.begin(),dp.begin()+lt,dp.end());
    t = (t - lt + n) % n;
    vector<int> old(n,INF);
    swap(old,dp);

    REP(ri,2) {
      REP(i,n) {
        if (h == lh) {
          if (i <= t) {
            chmin(dp[(t+1)%n], old[i] + (t + (t+1)-i));
          } else {
            chmin(dp[i],old[i]+t);
          }
        } else {
          if (i <= t) {
            chmin(dp[0], old[i] + (t-i));
          } else {
            chmin(dp[(t+1)%n],old[i] + ( (n-i+t) + (t+1)));
          }
        }
      }
      reverse(dp.begin()+1,dp.end());
      reverse(old.begin()+1,old.end());
      t = (n-t) % n;
    }
    rotate(dp.begin(),dp.begin()+(n-lt),dp.end());
    lh = h; lt = (lt+t)%n;
  }

  cout << *min_element(dp.begin(),dp.end()) << endl;
  return 0;
}