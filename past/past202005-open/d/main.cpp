#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int str_to_int(vector<string> t) {
  vector<vector<string>> ts(10);
  ts[0] = {
    ".###",
    ".#.#",
    ".#.#",
    ".#.#",
    ".###"
  };
  ts[1] = {
    "..#.",
    ".##.",
    "..#.",
    "..#.",
    ".###"
  };
  ts[2] = {
    ".###",
    "...#",
    ".###",
    ".#..",
    ".###"
  };
  ts[3] = {
    ".###",
    "...#",
    ".###",
    "...#",
    ".###"
  };
  ts[4] = {
    ".#.#",
    ".#.#",
    ".###",
    "...#",
    "...#"
  };
  ts[5] = {
    ".###",
    ".#..",
    ".###",
    "...#",
    ".###"
  };
  ts[6] = {
    ".###",
    ".#..",
    ".###",
    ".#.#",
    ".###"
  };
  ts[7] = {
    ".###",
    "...#",
    "...#",
    "...#",
    "...#"
  };
  ts[8] = {
    ".###",
    ".#.#",
    ".###",
    ".#.#",
    ".###"
  };
  ts[9] = {
    ".###",
    ".#.#",
    ".###",
    "...#",
    ".###",
  };

  REP(i,10) if (t == ts[i]) return i;
  return 0;
}

int main() {
  int n; cin >> n;
  vector<string> s(5);
  REP(i,5) cin >> s[i];

  REP(k,n) {
    vector<string> t(5);
    REP(i,5) REP(j,4) t[i] += s[i][4*k+j];
    cout << str_to_int(t);
  }

  cout << endl;
  return 0;
}