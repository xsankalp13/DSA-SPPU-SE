
#include<iostream>
#define N 20
#include<queue>
using namespace std;
int graph[20][20],visited[20],n;
int visitednew[20];
void dfs(int i)
{
cout<<i<<" ";
visited[i]=1;
for(int j=0;j<n;j++)
{
if(visited[j]==0&&graph[i][j]==1)
{
dfs(j);
}
}
}
void bfs(int start) {
queue<int> q;
q.push(start);
visitednew[start] = 1;
while (!q.empty()) {
int current = q.front();
q.pop();
cout << current << " ";
for (int j = 0; j < n; j++) {
if (visitednew[j] == 0 && graph[current][j] == 1) {
q.push(j);
visitednew[j] = 1;
}
}
}
}
int main()
{
cout<<"Enter the total vertex of the graph :";
cin>>n;
cout<<"Enter the edges of the graph :\n";
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<"Enter the edge : ("<<i<<","<<j<<") :";
cin>>graph[i][j];
}
}
for(int i=0;i<n;i++)
{
cout<<endl;
cout<<"[";
for(int j=0;j<n;j++)
{
cout<<" "<<graph[i][j]<<" ";
}
cout<<"]";
}
cout<<"\nDFS traversal is :";
dfs(0);
cout<<"\nBFS traversal is :";
bfs(0);
}