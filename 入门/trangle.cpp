#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int edge[3];
    cin>>edge[0]>>edge[1]>>edge[2];
    sort(edge,edge+3);
    if(edge[0]+edge[1]<=edge[2]){
        cout<<"Not triangle\n";
        return 0;
    } 
    if(edge[0]*edge[0]+edge[1]*edge[1]==edge[2]*edge[2]){
        cout<<"Right triangle\n";
    }
    else{
        if(edge[0]*edge[0]+edge[1]*edge[1]>edge[2]*edge[2])
            cout<<"Acute triangle\n";
        else
            cout<<"Obtuse triangle\n";
    }
    if(edge[0]==edge[1]||edge[1]==edge[2]||edge[0]==edge[2]){
        cout<<"Isosceles triangle\n";
    }
    if(edge[0]==edge[1]&&edge[1]==edge[2]){
        cout<<"Equilateral triangle\n";
    }
}