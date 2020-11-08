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

bool ok(vector<int> v) {
  if (v.size() == 0) return false;
  int sum = 0;
  // 3の倍数は各桁を足し合わせた数が3の倍数かどうかで判定可能
  for(auto n: v) sum += n;
  return sum % 3 == 0;
}

int main() {
  IOS;
  string n; cin >> n;
  int k = n.size();
  int ans = INF;

  for (int bit = 0; bit < (1<<k); bit++) {
    vector<int> s;
    REP(i,k) {
      if (bit >> i & 1) s.push_back(n[i]-'0');
    }
    if (ok(s)) chmin(ans, (int)(k - s.size()));
  }

  if (ans == INF) ans = -1;
  COUT(ans);

  return 0;
}