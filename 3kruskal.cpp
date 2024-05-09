#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int v, int e) {
        V = v;
        E = e;
    }

    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    // Find set of an element i
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    // Union of two sets of x and y
    void Union(vector<int>& parent, int x, int y) {
        parent[x] = y;
    }

    void kruskalMST() {
        vector<Edge> result;
        // Sort all edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V, -1);

        int i = 0, e = 0;

        while (e < V - 1 && i < E) {
            Edge next_edge = edges[i++];
            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            if (x != y) {
                result.push_back(next_edge);
                Union(parent, x, y);
                e++;
            }
        }

        // Print the constructed MST
        cout << "Edges in the MST:" << endl;
        for (const auto& edge : result) {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        }
    }
};

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    Graph g(V, E);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
