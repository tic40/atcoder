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
  int n; cin >> n;
  int a,b; cin >> a >> b;
  set<int> s;
  s.insert(a); s.insert(b);
  int k; cin >> k;
  REP(i,k) {
    int p; cin >> p;
    s.insert(p);
  }
  YES( s.size() == k+2 );

  return 0;
  /*
  int n; cin >> n;
  int a,b; cin >> a >> b;
  a--; b--;
  int k; cin >> k;
  int p[k];
  REP(i,k) {
    cin >> p[i];
    p[i]--;
  }

  G g(n);
  REP(i,k-1) {
    g[p[i]].push_back(p[i+1]);
    g[p[i+1]].push_back(p[i]);
  }
  g[a].push_back(p[0]);
  g[p[0]].push_back(a);
  g[b].push_back(p[k-1]);
  g[p[k-1]].push_back(b);

  queue<P> que;
  que.push({a,0});
  vector<int> visited(n,INF);

  int ans = INF;
  while(!que.empty()) {
    P x = que.front(); que.pop();
    if (x.first == b) {
      ans = x.second; break;
    }

    int nextV = x.second+1;
    for(auto v: g[x.first]) {
      if (visited[v] <= nextV) continue;
      visited[x.first] = nextV;
      que.push({v, nextV});
    }
  }
  YES(ans == k+1);

  return 0;
  */
}