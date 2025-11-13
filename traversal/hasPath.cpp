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

    //bfs approach
    bool hasPath1(int src, int dest){
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(src);
        vis[src] = true;

        while(q.size()>0){
            int u = q.front(); //curr vertex
            q.pop();

            list<int> neighbors = l[u];//u-->v
            for(int v : neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                    if(v == dest){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    //dfs approach
    bool pathHelper(int src, int dest, vector<bool> &vis){
        if(src == dest){
            return true;
        }

        vis[src] = true;
        list<int> neighbors = l[src];
        for(int v : neighbors){
            if(!vis[v]){
                if(pathHelper(v, dest, vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath2(int src, int dest){
        vector<bool> vis(7, false);
        return pathHelper(src, dest, vis);
    }
};

int main() {
    Graph graph(7);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

    cout<<graph.hasPath1(0,6)<<endl;
    cout<<graph.hasPath2(0,6)<<endl;
    return 0;
}