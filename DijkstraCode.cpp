#include <iostream>
#include <climits>
using namespace std;

enum
{
    Y = 7
};

int minDistance(int distance[], bool Q[])
{
    int minimum = INT_MAX;
    int min_index = 0;

    for (int x = 0; x < Y; x++)
    {
        if (Q[x] == false && distance[x] <= minimum)
        {
            minimum = distance[x];
            min_index = x;
        }
    }
    return min_index;
}

void result(int distance[])
{
    cout << "Vertex \t\t Distance from Source" << '\n';
    for (int x = 0; x < Y; x++)
    {
        cout << x << " \t\t" << distance[x] << '\n';
    }
}

void dijkstra(int graph[Y][Y], int src)
{
    int distance[Y];
	
    bool Q[Y];
	
    for (int i = 0; i < Y; i++)
    {
        distance[i] = INT_MAX, Q[i] = false;
    }

    distance[src] = 0;

    for (int number = 0; number < Y - 1; number++)
    {
        int u = minDistance(distance, Q);

        Q[u] = true;

        for (int v = 0; v < Y; v++)
        {
            if (!Q[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
    result(distance);
}


int main()
{
    int graph[Y][Y] =
    {
        0, 10, 15, NULL, 30, NULL, NULL,
        NULL, 0, NULL, NULL, NULL, 57, NULL,
        15, NULL, 0, 16, NULL, NULL, 52,
        NULL, NULL, 13, 0, NULL, NULL, NULL,
        30, NULL, NULL, NULL, 0, 11, 34,
        NULL, 49, NULL, NULL, 12, 0, NULL,
        NULL, NULL, 63, NULL, 35, NULL, 0
    };
    dijkstra(graph, 0);
    return 0;
}


