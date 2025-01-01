#include <iostream>
#include <vector>
using namespace std;

class GraphAdjMatrix {
private:
    vector<vector<int>> adjMatrix;
    int vertices;

public:
    GraphAdjMatrix(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // Vì đây là đồ thị vô hướng
    }

    void inputGraph() {
        int edges, u, v;
        cout << "Nhap so luong canh: ";
        cin >> edges;

        cout << "Nhap cac canh (u, v):\n";
        for (int i = 0; i < edges; ++i) {
            cin >> u >> v;
            addEdge(u, v);
        }
    }

    void displayGraph() {
        cout << "Ma tran lan can:\n";
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices;
    cout << "Nhap so luong dinh: ";
    cin >> vertices;

    GraphAdjMatrix graph(vertices);
    graph.inputGraph();
    graph.displayGraph();

    return 0;
}
