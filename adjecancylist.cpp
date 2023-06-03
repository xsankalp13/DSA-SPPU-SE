#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> map;
    void addNode(int u, int v){
        map[u].push_back(v);
        map[v].push_back(u);
    }

    void displayGraph(){
        for(auto i:map){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }


};



int main(){
    
    Graph g;
    int u,v;
    cin>>u>>v;
    while(u != -1 || v != -1){
        g.addNode(u,v);
        cin>>u>>v;
    }
    g.displayGraph();



}