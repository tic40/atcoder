#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<n;i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
using G = vector<vector<int>>;
using M = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  IOS;
  int h,w; cin >> h >> w;
  int k; cin >> k;
  char c[h][w];
  int bsum = 0;
  REP(i,h) REP(j,w) {
    cin >> c[i][j];
    if (c[i][j] == '#') bsum++;
  }

  int ans = 0;
  for (int bit = 0; bit < (1<<h); bit++) {
    vector<int> sh;

    REP(i,h) { if (bit >> i & 1) sh.push_back(i); }
    int tmp_b = 0;

    for(auto vh: sh)  {
      REP(j,w) { if (c[vh][j] == '#') tmp_b++; }
    }

    for (int bit = 0; bit < (1<<w); bit++) {
      vector<int> sw;
      REP(i,w) { if (bit >> i & 1) sw.push_back(i); }
      int tmp_b2 = 0;
      for(auto vw: sw) {
        REP(i,h) { if (c[i][vw] == '#') tmp_b2++; }
      }

      for(auto vh: sh) for(auto vw: sw) {
        if (c[vh][vw] == '#') tmp_b2--;
      }
      if ( bsum - (tmp_b + tmp_b2) == k ) ans++;
    }
  }

  COUT(ans);
  return 0;
}
