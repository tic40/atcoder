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
  int c[n],s[n],f[n];
  REP(i,n-1) cin >> c[i] >> s[i] >> f[i];
  REP(i,n) {
    int t=0;
    for (int j = i; j < n-1; j++) {
      if (t<s[j]){
        t=s[j];
      } else if (t%f[j] != 0) {
        t=t+f[j]-t%f[j];
      }
      t+=c[j];
    }
    COUT(t);
  }
  return 0;
}
