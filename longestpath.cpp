#include <bits/stdc++.h>
using namespace std;
# define R 3
# define C 10
struct Pair{
  bool found;
  int value;
};
Pair path(int mat[R][C],int x,int y,int a,int b,bool visited[R][C])
{
    Pair p;
    if(x==a && y==b){
     p={true,0};
        return p;
    }
    if(x<0 || x>=R || y<0 || y>=C || visited[x][y])
    {
        p={false,INT_MAX};
        return p;
    }
    visited[x][y]=true;
    int res=INT_MIN;
    Pair sol=path(mat,x,y-1,a,b,visited);
    if(sol.found){
    res=max(res,sol.value);}
    sol=path(mat,x,y+1,a,b,visited);
    if(sol.found){
    res=max(res,sol.value);}
    sol=path(mat,x-1,y,a,b,visited);
    if(sol.found){
    res=max(res,sol.value);}
    sol=path(mat,x+1,y,a,b,visited);
    if(sol.found){
    res=max(res,sol.value);}
    visited[x][y]=false; //backtrack
    if(res!=INT_MIN)
    {
        p={true,1+res};
        return p;
    }
    else
    {
        p={false,INT_MAX};
        return p;
    }
    
}
void longestpath(int mat[R][C],int x,int y,int a,int b)
{
    bool visited[R][C];
    memset(visited,false,sizeof visited);
    Pair solution=path(mat,x,y,a,b,visited);
    if(solution.found)
    {
        cout<<"Longest path is:"<<solution.value<<endl;
    }
    else
    {
        cout<<"No path found"<<endl;
    }
}
int main() {
	
	int mat[R][C]={ { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
    longestpath(mat,0,0,1,7);
	return 0;
}