#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,n) for(int i=0;i<n;i++)
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
template<class T>bool chmax(T &a,const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a,const T &b) {if(b<a){a=b; return 1;} return 0;}
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
int N;
vector<int> a;

void solve1() {
  int l=0,r=0;

  REP(i,N) {
    if (i < N/2) chmax(l,a[i]);
    else chmax(r,a[i]);
  }

  int ans = min(l,r);
  REP(i,N) {
    if (ans == a[i]) { COUT(i+1); return; }
  }
  return;
}

// 愚直にトーナメントをシュミレート
void solve2() {
  map<int,int> m;
  REP(i,N) m[a[i]] = i;

  int ans = 0;
  while(a.size() > 2) {
    vector<int> na;
    for(int i = 0; i < a.size(); i+=2) {
      na.push_back(max(a[i],a[i+1]));
    }
    swap(a,na);
  }
  ans = min(a[0],a[1]);
  COUT(m[ans]+1);

  return;
}



int main() {
  IOS;
  cin >> n;
  N = 1<<n;
  a.resize(N);
  REP(i,N) cin >> a[i];

  solve1();
  // solve2();
  return 0;
}