#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
// #define endl '\n'
#define int long long 

class Node{
    public:
    char data;
    unordered_map<char, Node*> m;// this is done to store the children of the node
    bool isTerminal;

    Node(char d){
        data = d;
        isTerminal = false;
    }

};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node('\0');
    }
    void insert(string word){
        Node* temp = root;
        for(char ch: word){
            if(temp->m.count(ch)==0){ // here we check if the temp has a child with the character ch
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];// here we move the temp to the child of the temp with the character ch
        }
        temp->isTerminal = true;// this is done to mark the end of the word
    }
    bool search(string word){
        Node* temp = root;
        for(char ch: word){
            if(temp->m.count(ch)==0){
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
    void deleteWord(string word){
        Node* temp = root;
        for(char ch: word){
            if(temp->m.count(ch)==0){
                return;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = false;
    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string words[] = {"apple", "ape", "no", "news", "not", "never"};
    Trie t;
    for(auto w: words){
        t.insert(w);
    }
    int q;
    cin>>q;

    string search_word;
    while(q--){
        cin>>search_word;
        if(t.search(search_word)){
            cout<<search_word<<" is present"<<endl;
        }
        else{
            cout<<search_word<<" is not present"<<endl;
        }
    }
    
    return 0;
}