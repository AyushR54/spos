#include<iostream>
using namespace std;

void first_fit(int blocksize[],int m, int processsize[],int n)
{
    int allocation[n];
    for(int i ; i<n ; i++){
        allocation[i] = -1;
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0; j<m ;j++){
            if(processsize[i]<= blocksize[j])
            {
                allocation[i]=j;
                blocksize[j]= blocksize[j]-processsize[i];
                break;

            }
        }
    }
    cout<<"Process"<<"\t"<<"block no"<<endl;
    for (int i=0 ; i<n ; i++){
        if(allocation[i]!=-1)
        {
            cout<<"p"<<i<<"\t"<<allocation[i]+1<<endl;
        }
        else
        {
            cout<<"p"<<"not allocated"<<endl;
        }
    }
}
int main(){
    int blocksize[]={100,500,200,300,600};
    int processsize[]={212,417,112,426};
    int m = sizeof(blocksize)/sizeof(blocksize[0]);
    int n = sizeof(processsize)/sizeof(processsize[0]);
    first_fit(blocksize,m,processsize,n);
}