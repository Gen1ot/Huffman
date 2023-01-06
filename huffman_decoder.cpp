#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <queue>
#include <unordered_map>


class Node{  // A tree node
 public:
  std::string key;
  unsigned long long size;
  Node *R;  // Right node
  Node *L;  // Left node

  // Comparison function to be used to order the heap
  bool operator() (const Node& x, const Node& y) {
    return x.size >= y.size;
  }

// Node constructor
  Node(const std::string& value = "", unsigned long long amount = 0,
        Node * left = NULL, Node * right = NULL) {
    key = value;
    size = amount;
    L = left;
    R = right;
  }

  Node * join(Node x) {  // Node pooling function
    return new Node( x.key + key , x.size + size, new Node(x), this);
  }
};

// Builds Huffman tree
Node * builder(std::priority_queue<Node, std::vector<Node>, Node> tree) {
    while (tree.size() > 1) {
            Node *n = new Node(tree.top());

            tree.pop();
            std::cout << "Build: " << n->key << " "
                        << tree.top().key << std::endl;
            tree.push(*n->join(*new Node(tree.top())));
            tree.pop();
        }
        return new Node(tree.top());
}

int main() 
{}
