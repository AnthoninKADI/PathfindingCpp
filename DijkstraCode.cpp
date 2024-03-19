#include <algorithm>
#include <iostream>
#include <climits>
#include <stdbool.h>
#include <stdbool.h>
#include <vector>
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

void result(int distance[], int prev[])
{
    cout << "Vertex \t\t Distance\t\t Path" << '\n';
    for (int x = 0; x < Y; x++)
    {
        cout << x << " \t\t" << distance[x] << " \t\t";
        int p = prev[x];
        while(p != -1)
        {
            cout<<" "<<static_cast<char>('A' + p)<<",";
            p = prev[p];
        }
        cout<<endl;
    }
}

bool hasOpenNode(bool Q[])
{
    for(int i =0; i < Y; i++)
    {
        if(Q[i] == false)
            return true;
        
    }
    return false;
}

void dijkstra(int graph[Y][Y], int src)
{
    int distance[Y];
    int prev[Y];
    for(int y = 0; y < Y ; y++)
    {
        prev[y] = -1;
    }
    bool Q[Y];
	
    for (int i = 0; i < Y; i++)
    {
        distance[i] = INT_MAX, Q[i] = false;
    }

    distance[src] = 0;
    
    while (hasOpenNode(Q))
    {
        int u = minDistance(distance, Q);
        Q[u] = true;
        //int prev;
        for (int v = 0; v < Y; v++)
        {
            if (u!=v && !Q[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
    result(distance, prev);
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
    dijkstra(graph, 2);
    return 0;
}
