#include<bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left;
    Node *right;
};

Node* createNode(char character, int frequency) {
    Node* newNode = new Node();
    newNode->ch = character;
    newNode->freq = frequency;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Comparator for the priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, map<char, string>& huffmanCodes) {
    if (!root) return;

    if(!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

Node* buildHuffmanTree(map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for(auto entry : freqMap) {
        pq.push(createNode(entry.first, entry.second));
    }

    while(pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* internal = createNode('$', left->freq + right->freq);
        internal->left = left;
        internal->right = right;
        pq.push(internal);
    }

    return pq.top();
}

int main() {
    string text;
    cout << "Enter the text : ";
    cin >> text;

    map<char, int> freqMap;
    for(char ch : text) {
        freqMap[ch]++;
    }

    Node* root = buildHuffmanTree(freqMap);

    map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    cout << "\nHuffman Codes:\n";
    for(auto entry : huffmanCodes) {
        cout << entry.first << ": " << entry.second << "\n";
    }
    // Encode the input text
    string encodedText = "";
    for (char ch : text) {
        encodedText += huffmanCodes[ch];
    }
    cout << "Encoded Text: " << encodedText << "\n";

    // Decode the encoded text
    string decodedText = "";
    Node* current = root;
    for (char bit : encodedText) {
        if (bit == '0') current = current->left;
        else current = current->right;

        if (!current->left && !current->right) {
            decodedText += current->ch;
            current = root;
        }
    }
    cout << "Decoded Text: " << decodedText << "\n";
    return 0;
}

