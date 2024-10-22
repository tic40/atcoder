#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = 1e9;
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n,q; cin >> n >> q;
  // dp[i][l][r] := i 操作目でそれぞれの手が l,r の位置にいるときの最小手数
  // 片方の手だけを dp すればよい
  // dp[i][j] := i 操作目で h じゃない方の手が j に来るときの最小手数
  vector<int> dp(n,INF);
  dp[1] = 0;
  char lh = 'L'; // 最後に動かした手
  int lt = 0; // 最後に動かした手の位置

  REP(_,q) {
    char h; int t; cin >> h >> t; t--;
    // rotate して lt が 0 にくるようにする
    rotate(dp.begin(),dp.begin()+lt,dp.end());
    t = (t - lt + n) % n;
    vector<int> old(n,INF);
    swap(old,dp);

    // 時計回り, 反時計周りの2通り
    REP(ri,2) {
      REP(i,n) {
        // 最後に動かした手と今動かす手が同じとき
        if (h == lh) {
          // i = 他方の手の位置
          // i(他方の手)が道中にある場合は両手を動かす
          // 今の手を t へ移動 + 他方を i から t+1 へ移動
          if (i <= t) chmin(dp[(t+1)%n], old[i] + (t + (t+1)-i));
          // 今の手を t へ。他方の手は動かない
          else chmin(dp[i],old[i]+t);
        // 最後に動かした手と今動かす手が異なるとき
        } else {
          // i = 今動かす手の位置
          // 最後に動かした手(他方の手) は 0 にいるので衝突しない
          if (i <= t) chmin(dp[0], old[i] + (t-i));
          // 衝突するので他方の手を t+1 へ、今の手を t へ移動させる
          else chmin(dp[(t+1)%n], old[i] + ((n-i+t) + (t+1)));
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