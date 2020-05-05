#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
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
  int n; string s;
  cin >> n >> s;
  vector<P> v(n+1); // first: E, second: W
  v[0] = {0,0};
  REP(i,n) {
    int e = v[i].first, w = v[i].second;
    if (s[i] == 'E') e++;
    else w++;
    v[i+1] = {e,w};
  }

  int ans = INF;
  REP(i,n) {
    int l = v[i].second-v[0].second;
    int r = v[n].first-v[i+1].first;
    ans = min(ans, l+r);
  }
  COUT(ans);
  return 0;
}
