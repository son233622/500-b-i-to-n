#include <iostream>
#include <vector>
#include <list>

using namespace std;

class GraphAdjList {
private:
    vector<list<int>> adjList;
    int vertices;

public:
    GraphAdjList(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void inputGraph() {
        int edges, u, v;
        cout << "Nhap so luong canh: ";
        cin >> edges;

        cout << "Nhap cac canh (u, v):\n";
        for(int i = 0; i < edges; ++i) {
            cin >> u >> v;
            addEdge(u, v);
        }
    }

    void displayGraph() {
        cout << "Danh sach lan can:\n";
        for(int i = 0; i < vertices; ++i) {
            cout << "Dinh " << i << ": ";
            for(int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() 
{
    int vertices;
    cout << "Nhap so luong dinh: ";
    cin >> vertices;

    GraphAdjList Graph(vertices);
    Graph.inputGraph();
    Graph.displayGraph();
    return 0;
}