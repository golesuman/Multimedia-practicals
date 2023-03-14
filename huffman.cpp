#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left;
    Node *right;
    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

struct CompareNodes
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void encode(Node *node, string code, map<char, string> &codes)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        codes[node->ch] = code;
        return;
    }
    encode(node->left, code + "0", codes);
    encode(node->right, code + "1", codes);
}

void print_codes(map<char, string> &codes)
{
    for (auto p : codes)
    {
        cout << p.first << " : " << p.second << endl;
    }
}

int main()
{
    string str = "hello world";
    map<char, int> freq;

    for (char c : str)
    {
        freq[c]++;
    }

    priority_queue<Node *, vector<Node *>, CompareNodes> pq;

    for (auto p : freq)
    {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    map<char, string> codes;
    encode(pq.top(), "", codes);
    print_codes(codes);

    // Cleanup
    Node *root = pq.top();
    pq.pop();
    delete root;
    return 0;
}
