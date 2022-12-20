#include <bits/stdc++.h>
using namespace std;

// Implementation of greedy-based Huffman Prefix Code
#define pcint pair<char,int>
#define mypq 

struct compare{
    constexpr bool operator()(pcint const& a,pcint const& b){
        return a.second > b.second;
    }
};

typedef struct MinHeapTree{
    // min-heap tree made for huffman codes
    char c;
    int freq;
    struct MinHeapTree *left,*right;
}node;


// building huffman tree using priority queue-STL
int huffman_tree_pq(vector<pcint>& c){
    int n = c.size();
    priority_queue<pcint,vector<pcint>, compare> pq;
    
    for(auto x : c){
        pq.push(x);
    }
    for(int i=0;i < n-1;i++){
        int x = pq.top().second; pq.pop();
        int y = pq.top().second; pq.pop();
        pcint tmp = {'.',x+y};
        pq.push(tmp);
    }

    // result after final merging
    auto ans = pq.top();
    return ans.second;
}

// building custom huffman tree
node* build_huffman_tree(vector<pcint>& c){
    
    // using min-heap priority queue to always get a small freq number
    priority_queue<pcint,vector<pcint>, compare> pq;
    for(auto x : c){
        pq.push(x);
    }

    while(pq.size() >1){
        pcint x = pq.top(); pq.pop();
        pcint y = pq.top(); pq.pop();
        // node* new_node_x = malloc()
    }
    return NULL;
}


// Decode a binary string using custom-made min-heap huffman tree 
string huffman_decoding(node* root, string encoded_string){
    int n = encoded_string.size();
    
    string decoded_string="";
    node* curr = root;

    for(int i =0; i< n; i++){
        if(encoded_string[i] == '0') curr=curr->left;
        else curr = curr->right;

        if(!curr->left && !curr->right){
            decoded_string += curr->c;
            curr=root;
        }
    }
    return decoded_string;
}

int main(){
    vector<pcint> c = {{'a',45},{'b',13},{'c',12},{'d',16},{'e',9},{'f',5}};
    
    cout << "Huffman code ...";
    cout << huffman_tree_pq(c);

    cout << "Huffman Decoding a encoded string.." <<endl;

    string encoded_string ="000101101011010";
    cout << "String : " << encoded_string << endl;

    node* root = build_huffman_tree(c);
    cout << "Decoded string" << huffman_decoding(root ,encoded_string) << endl;
    return 0;
}