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
  string s,t,ans = "~";
  cin >> s >> t;

  auto f = [&](int x) {
    string ss = "";
    REP(i,s.size()) {
      if (i >= x && i-x < t.size()) {
        if (s[i] != '?' && s[i] != t[i-x]) return;
        ss.push_back(t[i-x]);
      } else {
        ss.push_back(s[i] == '?' ? 'a' : s[i]);
      }
    }
    ans = min(ans,ss);
  };

  REP(i,s.size() - (t.size()-1)) f(i);
  ans != "~" ? COUT(ans) : COUT("UNRESTORABLE");
  return 0;
}