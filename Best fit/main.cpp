#include <iostream>

using namespace std;

int main()
{


int frag[25],b[25],f[25],i,j,nb,nf,temp=0,lowest=10000;
static int bf[25],ff[25];

cout<<"Enter the number of blocks:"<<endl;
cin>>nb;
cout<<"Enter the number of files:"<<endl;
cin>>nf;
cout<<"Enter the size of the blocks:"<<endl;

for(i=1;i<=nb;i++){
cout<<"Block"<<i<<":";
cin>>b[i];
}

cout<<"Enter the size of the files :"<<endl;
for(i=1;i<=nf;i++)
{
cout<<"File"<<i<<":";
cin>>f[i];
}

for(i=1;i<=nf;i++)
{
 for(j=1;j<=nb;j++)
{
if(bf[j]!=1)
{
temp=b[j]-f[i];
if(temp>=0){

if(lowest>temp)
{
ff[i]=j;
lowest=temp;
}
}
}
}

 frag[i]=lowest;
 bf[ff[i]]=1;
 lowest=10000;
}

cout<<"\nFile No\tFile Size \tBlock No\tBlock Size\tFragment"<<endl;
for(i=1;i<=nf && ff[i]!=0;i++){
cout<<"\n"<<i<<"\t\t"<<f[i]<<"\t\t"<<ff[i]<<"\t\t"<<b[ff[i]]<<"\t\t"<<frag[i];
}
}


