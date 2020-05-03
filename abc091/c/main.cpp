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
  int n; cin >> n;
  vector<P> red(n), blue(n);
  int a,b,ans=0;
  REP(i,n) { cin >> a >> b; red[i] = {a, b}; }
  REP(i,n) { cin >> a >> b; blue[i] = {a, b}; }
  sort(blue.begin(), blue.end());

  REP(i,n) {
    int res = -1;
    REP(j,n) {
      if (red[j].first < blue[i].first && red[j].second < blue[i].second) {
        if (res == -1 || red[res].second < red[j].second) res = j;
      }
    }
    if (res != -1) {
      ans++;
      red[res] = { INF, INF };
    }
  }

  COUT(ans);
  return 0;
}
