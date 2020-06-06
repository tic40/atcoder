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
template<class T>bool CHMAX(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool CHMIN(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  IOS;
  string s; cin >> s;

  int ans = 0, tot = 0;
  REP(i,s.size()) {
    if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') tot++;
    } else { CHMAX(ans, tot); tot = 0; }
  }
  CHMAX(ans, tot);
  COUT(ans);
  return 0;
}