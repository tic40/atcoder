#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
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
  int N,M,maxx,miny;
  cin>>N>>M>>maxx>>miny;
  int x,y;
  REP(i,N) { cin >> x; maxx = max(maxx,x); }
  REP(i,M) { cin >> y; miny = min(miny,y); }
  if (miny > maxx) COUT("No War");
  else COUT("War");
  return 0;
}
