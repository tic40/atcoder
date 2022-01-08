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
  int n,t;
  int a;
  cin >> n >> t >> a;
  int h[n]; REP(i,n) cin >> h[i];
  t*=1000; a*=1000;

  P ans = {0, INF};
  REP(i,n) {
    int temp = t - h[i] * 6;
    int d = abs(temp - a);
    if (d < ans.second) ans = {i,d};
  }
  COUT(ans.first+1);
  return 0;
}
