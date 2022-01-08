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

bool s(ll a, ll b, ll c, ll d) {
  bool x1 = a+b == c+d;
  bool x2 = a-b == c-d;
  bool x3 = abs(a-c) + abs(b-d) <= 3;
  return x1 || x2 || x3;
}

int main() {
  IOS;
  ll a,b,c,d;
  cin >> a >> b >> c >> d;

  if (a == c && b == d) {
    COUT(0);
    return 0;
  }
  if (s(a,b,c,d)) {
    COUT(1);
    return 0;
  }
  if (abs(a-c) + abs(b-d) <= 6) {
    COUT(2);
    return 0;
  }

  int diffx = abs(a-c);
  int diffy = abs(b-d);
  if (abs(b + diffx - d) <= 3 || abs(b - diffx - d) <= 3) {
    COUT(2);
    return 0;
  }

  if ( (diffx + diffy) % 2 == 0) {
    COUT(2);
    return 0;
  }

  COUT(3);
  return 0;
}