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
using mp = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmx(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int H,W,M;
set<P> st;

void input() {
  cin >> H >> W >> M;
  REP(i,M) {
    int a,b; cin >> a >> b;
    a--; b--;
    st.insert({a, b});
  }
}

void solver() {
  mp mh, mw;
  int hmxv = 0, wmxv = 0;
  vector<int> hmx, wmx;

  for (auto tmp: st) {
    mh[tmp.first]++; mw[tmp.second]++;
    chmx(hmxv, mh[tmp.first]);
    chmx(wmxv, mw[tmp.second]);
  }

  // 最大値のみ抽出する
  for (auto tmp: mh) {
    if (hmxv == tmp.second) hmx.push_back(tmp.first);
  }
  for (auto tmp: mw) {
    if (wmxv == tmp.second) wmx.push_back(tmp.first);
  }

  // 爆弾が重複している場合を考慮する
  int ans = hmxv + wmxv - 1;
  for (auto h : hmx) {
    for (auto w: wmx) {
      // findで見つからなかった場合は st.end() を返す
      if (st.find({h, w}) == st.end()) {
        ans++;
        COUT(ans);
        return;
      }
    }
  }

  COUT(ans);
  return;
}

int main() {
  IOS;
  input();
  solver();

  return 0;
}
