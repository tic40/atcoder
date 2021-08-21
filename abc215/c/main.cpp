#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s;
  int k;
  cin >> s >> k;

  vector<string> vs;
  sort(s.begin(),s.end());
  do {
    vs.push_back(s);
  } while (next_permutation(s.begin(),s.end()));

  cout << vs[k-1] << endl;
  return 0;
}