#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node
{
    int weight;
    string code;
    Node *left;
    Node *right;
    Node(int weight) : weight(weight), left(nullptr), right(nullptr) {}
};

void shannon_fano(vector<Node *> &nodes, int left, int right, int total)
{
    if (left == right)
    {
        return;
    }

    int half = 0;
    int i = left;

    while (i <= right)
    {
        half += nodes[i++]->weight;

        if (half * 2 >= total)
        {
            break;
        }
    }

    int midpoint = i - 1;
    int sum_left = 0, sum_right = 0;

    for (i = left; i <= midpoint; i++)
    {
        nodes[i]->code += '0';
        sum_left += nodes[i]->weight;
    }

    for (i = midpoint + 1; i <= right; i++)
    {
        nodes[i]->code += '1';
        sum_right += nodes[i]->weight;
    }

    shannon_fano(nodes, left, midpoint, sum_left);
    shannon_fano(nodes, midpoint + 1, right, sum_right);
}

map<char, int> count_frequencies(string str)
{
    map<char, int> freq;
    for (char c : str)
    {
        freq[c]++;
    }
    return freq;
}

void print_codes(vector<Node *> &nodes)
{
    for (auto node : nodes)
    {
        cout << node->code << " ";
    }
    cout << endl;
}

int main()
{
    string str = "hello world";
    auto freq = count_frequencies(str);

    vector<Node *> nodes;
    for (auto p : freq)
    {
        nodes.push_back(new Node(p.second));
    }

    shannon_fano(nodes, 0, nodes.size() - 1, str.size());

    for (int i = 0; i < nodes.size(); i++)
    {
        cout << nodes[i]->code << " : " << freq[str[i]] << endl;
    }

    // Cleanup
    for (auto node : nodes)
    {
        delete node;
    }
    return 0;
}
