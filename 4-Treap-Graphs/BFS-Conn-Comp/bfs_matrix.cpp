#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

#define MAX_COST 1000000001

struct vertex{
	int cost;
	vertex(int c){cost = c;}
	vertex(){}
};

class Graph{
	int n; // Number of vertices ≤ 10^5
public: 
	int TC; // total cost;
	vector<vertex> V;
	vector<vector<bool> > E; //T — есть ребро, F — нет ребра
	void add_edge(pair<int, int> p){ E[p.first-1][p.second-1] = true; 
                                     E[p.second-1][p.first-1] = true; }
	Graph(int nn);
	void BFS();
	void printV();
	void printE();
	vector<int> neighbours(int v);
};

vector<int> Graph::neighbours(int v){
    vector<int> neigh;
    for(size_t i = 0; i < n; ++i){
        if(E[v][i]) neigh.push_back(i);
    }
    return neigh;
}

void Graph::BFS(){
	deque<int> q;
    vector<bool> touched(n, false);
    for(size_t i = 0; i < n; ++i){
        int min_cost=0;
        if(!touched[i]){//BFS starts here
            min_cost = V[i].cost;
            q.push_back(i);
            touched[i] = true;
            while(!q.empty()){
                min_cost = min(min_cost, V[q.front()].cost);
                vector<int> neigh = neighbours(q.front());
                for(auto u : neigh){
                    if(!touched[u]){ 
                        q.push_back(u);
                        touched[u] = true;
                    }
                }
                q.pop_front();
            }
        }//BFS ends here
        TC += min_cost;
    }
}

Graph::Graph(int nn){
	n = nn;
	TC = 0;	
	V = vector<vertex>(n, vertex());;
	E = vector<vector<bool> >(n, vector<bool>(n, false) );	
}

void Graph::printV(){
	for(size_t i = 0; i < n; ++i){
		cout << V[i].cost << " ";
	}
	cout << endl << endl;
}

void Graph::printE(){
	for(size_t i = 0; i < n; ++i){
		for(size_t j = 0; j < n; ++j){
			cout << (E[i][j] ? 1 : 0);
			cout << " ";
		}
		cout << "\n";
	}
}

int main (int argc, char const *argv[])
{
	//freopen("t3", "r", stdin); // open file with test data to reed and acces it through stdin
    std::ios::sync_with_stdio(false); std::cin.tie(0);
	int n, m; // n — V, E — 
	
	cin >> n; cin >> m;
	
	Graph G(n);
	
	for(size_t i = 0; i < n; ++i){
		int cost;
		cin >> cost;
		vertex v(cost);
		G.V[i] = v;
	}
	//G.printV();
	
	for(size_t i = 0; i < m; ++i){
		pair<int, int> p;
		cin >> p.first; cin >> p.second;
		G.add_edge(p);
	}
	//G.printE();	
	
	G.BFS();
	
	cout << G.TC << "\n";
	
	return 0;
}