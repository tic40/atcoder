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
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n);
  REP(i,n) a[i] = s[i] == 'o'; // 0: x, 1: o

  auto get_cur = [&](char animal, char c){
    return animal == 'S' ? c : c^1;
  };

  // 4パターンを固定して考える: SS, SW, WW, WS
  for (string ans: {"SS", "SW", "WW", "WS"}) {
    for (int i = 1; i < n; i++) {
      if (get_cur(ans[i], a[i])) ans += ans[i-1];
      else ans += ans[i-1] == 'S' ? 'W' : 'S';
    }

    int cur = get_cur(ans[0], a[0]);
    int ok = cur ? ans[1] == ans[n-1] : ans[1] != ans[n-1];
    if (ok && ans[0] == ans[n]) { COUT(ans.substr(0,n)); return 0; }
  }

  COUT(-1); // 存在しない
  return 0;
}