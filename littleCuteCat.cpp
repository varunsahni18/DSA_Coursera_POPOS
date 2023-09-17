//little Cute Cat
// little cute kitten loves to write stories in a github readme
// One day she is given a list of words, you want to help her to check if each of these words are present in the readme file

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

void SeachHelper(Trie t, string document, int i, unordered_map<string, bool> &m){
    Node* temp = t.root;
    for(int j = i; j<document.length(); j++){
        char ch = document[j];
        if(temp->m.count(ch)==0){
            return;
        }
        temp = temp->m[ch];
        if(temp->isTerminal){
            string out = document.substr(i, j-i+1);
            if(m.count(out)==0){
                cout<<out<<endl;
                m[out] = true;
            }
        }
    }
}


void documentSearch(vector<string> words, string document){
    Trie t;
    for(auto word: words){
        t.insert(word);
    }
    unordered_map<string, bool> m;
    for(int i =0; i< document.length(); i++){
        SeachHelper(t, document, i, m);
    }
    for(auto w: words){
        if(m[w]){
            cout<<w<<" : True"<<endl;
        }
        else{
            cout<<w<<" : False"<<endl;
        }
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string document = "little cute cat loves to code in c++, java & python";
    vector<string> words = {"cute cat", "ttle", "cat", "quick", "big"};
    documentSearch(words, document);
    return 0;
}