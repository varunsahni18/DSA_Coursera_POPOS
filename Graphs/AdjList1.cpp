#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
#define endl '\n'
#define int long long 

class Graph{
    int V;//number of vertices
    list<int> *l;//array of linked lists
    public: 
        Graph(int v){
            V = v;
            l = new list<int>[V];
        }
        void addEdge(int u, int v, bool bidir = true){
            l[u].push_back(v);
            if(bidir){
                l[v].push_back(u);
            }
        }
        void printAdjList(){
            for(int i = 0; i < V; i++){
                cout << i << "->";
                for(int vertex : l[i]){
                    cout << vertex << ",";
                }
                cout << endl;
            }
        }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.printAdjList();
    return 0;
}