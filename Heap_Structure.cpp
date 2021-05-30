#include <iostream>
using namespace std;
const int n=7;
int t[n];
int i;
void Heap_Sort(int t[],int n);
void shift(int parent , int last);


int main(){

for (int i=0;i<n;i++)
    cin>>t[i];
Heap_Sort(t, n);
for(int i=n-1;i>=0;i--)
cout<<t[i]<<" ";

}

void Heap_Sort(int t[],int n){
int parent= n/2;
int last=n-1;
int h;
while (parent>0)
    {
        parent--;
        shift(parent,last);
    }
while(last>0)
    {
        h=t[0];t[0]=t[last];t[last]=h;
        last--;
        shift(0,last);
    }
}

void shift(int parent, int last){
int child ,h;
child=2*parent+1;
while(child <= last){
    if(child<last)
        if(t[child]<t[last])
            child++;
    if(t[child]>=t[parent])
        child=last+1;// to exit we can use break
    else
    {
        h=t[parent]; t[parent]=t[child]; t[child]=h;
        parent=child;
        child=2*parent+1;

    }
    }
}
