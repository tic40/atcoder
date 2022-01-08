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
const double pi = 3.141592653589793;

int main() {
  int a,b,h,m;
  cin>>a>>b>>h>>m;
  h %= 12;
  double minites = h*60+m;
  double spdh = 360.0 / (12 * 60);
  double spdm = 360.0 / 60;
  double hw = spdh * minites;
  double mw = spdm * m;
  double diff = abs(hw-mw);
  double w = min(diff, 360-diff);

  double ans;
  if (w == 0) {
    ans = abs(a-b);
  } else {
    ans = sqrt(a*a + b*b - 2*a*b*cos(w*pi/180.0));
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
