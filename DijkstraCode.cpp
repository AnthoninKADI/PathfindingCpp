#include <cstdlib>
#include <iostream>
#include <limits>
int inf = std::numeric_limits<int>::max();
using namespace std;

int miniDist(int distance[], bool Tset[]) 
{
    int minimum=INT_MAX,ind;
              
    for(int k=0;k<7;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void Dijkstra(int graph[7][7],int src) 
{
    int distance[7];                             
    bool Tset[7];
    
     
    for(int k = 0; k<7; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;                 
    
    for(int k = 0; k<7; k++)                           
    {
        int m=miniDist(distance,Tset); 
        Tset[m]=true;
        for(int k = 0; k<7; k++)                  
        {
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<7; k++)                      
    { 
        char str=65+k; 
        cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
}

int main()
{
    int graph[7][7]={
        {0, 10, 15, NULL, 30, NULL, NULL},
        {NULL, 0, NULL, NULL, NULL, 57, NULL},
        {15, NULL, 0, 16, NULL, NULL, 52},
        {NULL, NULL, 13, 0, NULL, NULL, NULL},
        {30, NULL, NULL, NULL, 0, 11, 34},
        {NULL, 49, NULL, NULL, 12, 0, NULL},
        {NULL, NULL, 63, NULL, 35, NULL, 0}};

    Dijkstra(graph,0); //6 -> G // 2 -> C //
    return 0;                           
}
