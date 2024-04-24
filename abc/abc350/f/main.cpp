#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

struct Parser {
  string s;
  int si;
  struct Node {
    vector<int> to;
    char c;
    Node(char c = 0): c(c) {}
  };
  vector<Node> nodes;
  int root;
  void parse() {
    si = 0;
    root = expr();
  }
  int charNode() {
    int v = nodes.size();
    nodes.push_back(Node(s[si++]));
    return v;
  }
  int expr() {
    int v = nodes.size();
    nodes.push_back(Node());
    while (si < (int)s.size()) {
      if (s[si] == ')') break;
      if (s[si] == '(') {
        si++;
        int u = expr();
        nodes[v].to.push_back(u);
        si++;
      } else {
        int u = charNode();
        nodes[v].to.push_back(u);
      }
    }
    return v;
  }
  void dfs(int v, bool flip) {
    Node& node = nodes[v];
    if (node.c) {
      char c = node.c;
      if (!flip) c = islower(c) ? toupper(c) : tolower(c);
      cout << c;
    } else {
      if (flip) reverse(node.to.begin(), node.to.end());
      for(int u: node.to) dfs(u, !flip);
    }
  }
  void output() {
    dfs(root, false);
    cout << endl;
  }
};

int main() {
  Parser p;
  cin >> p.s;
  p.parse();
  p.output();

  return 0;
}