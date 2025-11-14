#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    bool isUndir;
public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        this->isUndir = isUndir;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }

    void calcIndegree(vector<int> &indeg){
        for(int u = 0; u<V; u++){
            list<int> neighbors = l[u];
            for(int v : neighbors){
                indeg[v]++;
            }
        }
    }

    //kahn's Algorithm(bfs approach)
    void topoSort(){
        vector<int> indeg(V, 0);
        calcIndegree(indeg);
        queue<int> q;

        //0 indegree nodes -> starting  point
        for(int i = 0; i<V; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            list<int> neighbors = l[curr];
            for(int v : neighbors){
                indeg[v]--;
                if(indeg[v] == 0){//no pending dependencies
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
};

int main() {
    Graph graph(6, false);

    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topoSort();
    return 0;
}