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
  string s; ll k;
  cin >> s >> k;

  REP(i,s.size()) {
    int x = s[i]-'0';
    if (x==1) continue;

    if (i+1 <= k) {
      COUT(x);
      return 0;
    }
  }
  COUT(1);
  return 0;
}
