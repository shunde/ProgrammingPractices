#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct ArcNode {
    int v;
    ArcNode* next;
    ArcNode(int _v): v(_v), next(NULL) {} 
};

struct Vertex{
    string name;
    ArcNode *arc;    
    Vertex():name(""), arc(NULL) {}
};



class DGraph{
public:
    DGraph(int _n) {
        n = _n;
        v = new Vertex[n];
    }
    ~DGraph() {
        for (int i = 0; i < n; i++) {
            ArcNode* pArc = v[i].arc;
            while (pArc) {
                ArcNode* tmp = pArc->next;
                delete pArc;
                pArc = tmp;
            }
        }
        delete []v;
    }
    void setName(int idx, string& name) {
        v[idx].name = name;        
    }


    void addArc(int from, int to) {
        ArcNode* pArc = new ArcNode(to);
        pArc->next = v[from].arc;
        v[from].arc = pArc;
    }    

    int size() {
        return n;
    }    

    string getName(int idx) {
        return v[idx].name;
    }

    void neighbors(int idx, vector<int> &neighbor) {        
        ArcNode* pArc = v[idx].arc;
        while (pArc) {
            neighbor.push_back(pArc->v);
            pArc = pArc->next;
        }       
    }

    vector<int> indegrees() {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            ArcNode* pArc = v[i].arc;
            while (pArc) {
                indegree[pArc->v]++;
                pArc = pArc->next;
            }
        }
        return indegree;
    }

private:
    int n;
    Vertex *v;    
};

struct CompareDist {
    bool operator() (pair<string, int> &n1, pair<string,int> &n2) {
        return n1.first > n2.first;
    }
};

bool topSort(DGraph& G, vector<string>& order) {
    int n = G.size();
    vector<int> indegree = G.indegrees();    
    priority_queue<pair<string, int>, vector<pair<string,int> >, CompareDist > Q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            Q.push(make_pair(G.getName(i), i));
    }

    while (!Q.empty()) {
        pair<string, int> pairs = Q.top();
        string name = pairs.first;
        order.push_back(name);
        Q.pop();
        int idx = pairs.second;        

        vector<int> neighbor;
        G.neighbors(idx, neighbor);
        for (int i = 0; i < neighbor.size(); i++) {
            int v = neighbor[i];
            indegree[v] -= 1;

            if (indegree[v] == 0)
                Q.push(make_pair(G.getName(v), v));
        }        
    }
    if (order.size() == n) return true;
    else return false;
}



int main(int argc, char* argv[]) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N ;        
        DGraph G(N);
        for (int j = 0; j < N; j++) {
            string name;
            int m;
            cin >> name >> m;              
            G.setName(j, name);
            while (m-->0) {
                int v;
                cin >> v;
                G.addArc(v, j);                
            }            
        }

        vector<string> order;
        bool isTop = topSort(G, order);
        if (isTop) {
            for (int k = 0; k < order.size(); k++) {
                cout << order[k] << endl;
            }
        } else {
            cout << "ERROR" << endl;
        }
        cout << endl;

    }

    return 0;
}