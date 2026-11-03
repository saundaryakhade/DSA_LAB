#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Graph
{
    vector<string> loc;
    vector<vector<int>> adj;
    int V;

public:

    Graph(vector<string> names)
    {
        loc = names;
        V = names.size();

        adj.assign(V, vector<int>());
    }

    void addRoad(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void showGraph()
    {
        cout << "\nRoad Network (Adjacency List):\n";

        for (int i = 0; i < V; i++)
        {
            cout << loc[i] << " : ";

            for (int v : adj[i])
                cout << loc[v] << " ";

            cout << endl;
        }
    }

    void shortestRouteBFS(int src, int dest)
    {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        vector<int> dist(V, 0);

        queue<int> q;

        visited[src] = true;
        q.push(src);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    parent[v] = u;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        if (!visited[dest])
        {
            cout << "No route found!\n";
            return;
        }

        vector<int> path;

        for (int x = dest; x != -1; x = parent[x])
            path.push_back(x);

        cout << "Shortest route ("
             << dist[dest] << " roads): ";

        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << loc[path[i]];

            if (i > 0)
                cout << " -> ";
        }

        cout << endl;
    }

    void dfsUtil(int src, int dest,
                 vector<bool>& visited,
                 vector<int>& path,
                 int& count)
    {
        visited[src] = true;
        path.push_back(src);

        if (src == dest)
        {
            count++;

            cout << "Route " << count << ": ";

            for (int i = 0; i < path.size(); i++)
            {
                cout << loc[path[i]];

                if (i < path.size() - 1)
                    cout << " -> ";
            }

            cout << endl;
        }
        else
        {
            for (int v : adj[src])
            {
                if (!visited[v])
                    dfsUtil(v, dest, visited, path, count);
            }
        }

        visited[src] = false;
        path.pop_back();
    }

    void allRoutesDFS(int src, int dest)
    {
        vector<bool> visited(V, false);
        vector<int> path;

        int count = 0;

        dfsUtil(src, dest, visited, path, count);

        cout << "Total routes found: " << count << endl;
    }

    void dfsRec(int src, vector<bool>& visited)
    {
        visited[src] = true;

        cout << loc[src] << " ";

        for (int v : adj[src])
        {
            if (!visited[v])
                dfsRec(v, visited);
        }
    }

    void dfsTraversal(int src)
    {
        vector<bool> visited(V, false);

        cout << "DFS Traversal: ";
        dfsRec(src, visited);

        cout << endl;
    }
};

int main()
{
    // 0 = Warehouse, 1 = A, 2 = B,
    // 3 = C, 4 = D, 5 = Customer

    vector<string> names = {
        "Warehouse", "Station", "Market",
        "Mall", "School", "Customer"
    };

    Graph g(names);

    g.addRoad(0, 1);
    g.addRoad(0, 2);
    g.addRoad(1, 3);
    g.addRoad(2, 3);
    g.addRoad(2, 4);
    g.addRoad(3, 4);
    g.addRoad(4, 5);

    cout << "===== DELIVERY ROUTE SYSTEM =====\n";

    g.showGraph();

    cout << "\n[1] Shortest route using BFS "
         << "(Warehouse -> Customer)\n";

    g.shortestRouteBFS(0, 5);

    cout << "\n[2] All possible routes using DFS "
         << "(Warehouse -> Customer)\n";

    g.allRoutesDFS(0, 5);

    cout << "\n[Extra] Full DFS traversal\n";

    g.dfsTraversal(0);

    return 0;
}
