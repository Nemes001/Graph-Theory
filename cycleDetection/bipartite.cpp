#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isBipartite(){
        queue<int> q;
        vector<bool> vis(V, false);
        vector<int> color(V, -1);

        q.push(0);
        color[0] = 0;

        while(q.size()>0){
            int curr = q.front();
            q.pop();
            list<int> neighbors = l[curr];

            for(int v : neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                }else{
                    if(color[v] == color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(1,3);

    cout<<graph.isBipartite()<<endl;
    return 0;
}