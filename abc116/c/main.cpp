#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
#define YES(x) cout<<(x?"YES":"NO")<<endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n; cin >> n;
  int h[n];
  REP(i,n) cin >> h[i];
  int ans = 0;

  while(1) {
    int left = -1,right = n-1,m = INF;
    REP(i,n) {
      if (h[i] > 0) {
        if (left == -1) left = i;
        m = min(m, h[i]);
      } else {
        if (left != -1) {
          right = i;
          break;
        }
      }
    }
    if (left == -1) break; // 終了

    for(int i = left; i <= right; i++) h[i]-=m;
    ans+=m;
  }

  COUT(ans);
  return 0;
}
