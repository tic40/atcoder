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

int solve(string s) {
  int size = s.size();
  REP(i,size) {
    if (s[i] != s[size-1-i]) return 0;
  }
  return 1;
}

int main() {
  string s; cin >> s;
  int size = s.size();
  if (!solve(s)) { COUT("No"); return 0; }
  string s2 = s.substr(0,size/2);
  if (!solve(s2)) { COUT("No"); return 0; }
  string s3 = s.substr((size+1)/2);
  if (!solve(s3)) { COUT("No"); return 0; }
  COUT ("Yes");
  return 0;
}