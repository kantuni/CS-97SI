#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct Node {
  char label;
  pair<char, char> children;
};

int main() {
  int T;
  cin >> T;
  
  for (int t = 0; t < T; t++) {
    string postfix;
    cin >> postfix;
    
    map<char, Node> tree;
    stack<char> s;
    
    for (int i = 0; i < postfix.size(); i++) {
      char letter = postfix[i];
      
      if (islower(letter)) {
        s.push(letter);
      } else {
        Node rchild;
        if (tree.count(s.top()) == 0) {
          rchild.label = s.top();
        } else {
          rchild = tree[s.top()];
        }
        s.pop();
        
        Node lchild;
        if (tree.count(s.top()) == 0) {
          lchild.label = s.top();
        } else {
          lchild = tree[s.top()];
        }
        s.pop();
        
        Node parent;
        parent.label = letter;
        parent.children = make_pair(lchild.label, rchild.label);
        tree[letter] = parent;
        s.push(letter);
      }
    }
    
    queue<char> q;
    char root = s.top();
    q.push(root);
    
    string answer;
    while (!q.empty()) {
      answer += q.front();
      if (tree.count(q.front()) > 0) {
        Node front = tree[q.front()];
        pair<char, char> children = front.children;
        q.push(children.first);
        q.push(children.second);
      }
      q.pop();
    }
    
    reverse(answer.begin(), answer.end());
    cout << answer << "\n";
  }
  
  return 0;
}
