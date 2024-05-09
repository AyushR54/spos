#include<iostream>
using namespace std;

int main()
{
    string process[10];
    int at[10],bt[10],wt[10],tt[10],a,b,c;
    int sum=0,tta=0,wta=0;
    float wtav, ttav;

    cout<<"Enter the number of process :";
    cin>>a;
    for(int i=0; i<a; i++)
    {
        cout<<"Enter process "<<i+1<<":";
        cin>>process[i];
    }
    for(int i=0; i<a; i++)
    {
        cout<<"Enter arrival time of "<<i+1<<":";
        cin>>at[i];
    }
    for(int i=0; i<a; i++)
    {
        cout<<"Enter burst time of "<<i+1<<":";
        cin>>bt[i];
    }

    cout<<"Process"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<endl;
    for(int i=0; i<a; i++)
    {
       cout<<process[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<endl;
    }

    cout<<"Gant Chart"<<endl;

    for(int i=0; i<a; i++)
    {
        cout<<"\t|"<<process[i]<<"|\t";
    }
    cout<<endl;
    for(int i=0; i<a; i++)
    {
       
        cout<<sum<<"\t\t";
         sum+=bt[i];
          tt[i]=sum-at[i];
        
    }
    cout<<sum<<"\t\t";
     cout<<endl;
    for(int i=0 ; i<a; i++)
    {
        tta+=tt[i];
    }
    ttav=(float(tta)/4);
   cout<<ttav<<endl;
    for(int i=0 ; i<a; i++)
    {
       wt[i]=tt[i]-bt[i];
    }
     for(int i=0 ; i<a; i++)
    {
        wta+=wt[i];
    }
    wtav=(float(wta)/4);
    cout<<wtav<<endl;
    
   

   
}

