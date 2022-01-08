#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl
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
  int n; cin >> n;
  string s[n]; REP(i,n) cin >> s[i];
  map<string, int> m; m[s[0]]++;

  int ok = true;
  for (int i = 1; i < n; i++) {
    if (s[i][0] != s[i-1].back()) ok = false;
    if (m[s[i]] > 0) ok = false;
    m[s[i]]++;
  }

  Yes(ok);
  return 0;
}
