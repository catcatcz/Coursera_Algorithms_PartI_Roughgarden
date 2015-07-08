#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class Solution
{
public:
vector<int> IntArray(string Filename)
{}

void quickSort(vector<int> &input, int begin, int end)
{
if(begin+1==end)
{
if(input[begin]>input[end]) {int temp; temp=input[begin]; input[begin]=input[end]; input[end]=temp;}
}
else if(begin==end)
{}
else
{
int mid=(begin+end)/2;
quickSort(input, begin, mid);
quickSort(input, mid+1,end);
vector<int> temp;
int i=begin;
int j=mid+1;
while(i<=mid && j<=end)
{
if(input[i]<=input[j])  {temp.push_back(input[i]); i++; }
else if(input[i]>input[j]){temp.push_back(input[j]); j++;}
}
if(i==mid+1)
{for(int p=j; p<end+1; p++){temp.push_back(input[p]);}}
else if(j==end+1)
{for(int p=i; p<mid+1; p++){temp.push_back(input[p]);}}


for(int n=begin; n< end+1; n++)
{input[n]=temp[n-begin];}

}

}
int findInversion(vector<int> &input,int begin, int end)
{
if(begin==end) {return 0;}
else if(begin+1==end) 
{if(input[begin]>input[end]) {return 1;} 
else{return 0;}}
else
{
int mid=(begin+end)/2;
int leftinversion=findInversion(input, begin, mid);
int rightinversion=findInversion(input, mid+1, end);

quickSort(input, begin, mid);
quickSort(input, mid+1, end);
int interinversion=0;
int i=begin;
int j=mid+1;
while(i<=mid)
{
//	cout<<"i="<<i<<endl;
	while(input[j]<input[i] && j<=end)
	{j++;}
	if(j==end+1) {
	interinversion+=(end-mid);
	if(end-mid<0)
	{cout<<"end="<<end<<" mid="<<mid<<endl;}}
	else if(j<=end)
	{interinversion+=(j-mid-1);
	if(j-mid-1<0)
	{cout<<"j="<<j<<" mid="<<mid<<endl;}
	}
	i++;	
	j=mid+1;
//	cout<<endl;
}
if(interinversion<0) {cout<<"begin="<<begin<<" end="<<end<<" tot="<<interinversion<<endl;}
if(leftinversion<0)  {cout<<"begin="<<begin<<" end="<<end<<" tot="<<leftinversion<<endl;}
if(rightinversion<0) {cout<<"begin="<<begin<<" end="<<end<<" tot="<<rightinversion<<endl;}
//cout<<"begin="<<begin<<" end="<<end<<" tot="<<interinversion+leftinversion+rightinversion<<endl;
cout<<"left="<<leftinversion<<"  right="<<rightinversion<<"  inter="<<interinversion<<endl;
int a;
cin>>a;
return interinversion+leftinversion+rightinversion;
}

}
vector<int> readFromFile(string myfile)
{
ifstream ifs(myfile, ios::in);
vector<int> array;
int temp;
if(ifs)
{
while(ifs>>temp)
{
array.push_back(temp);
}
}
return array;
}

};

int main()
{
int a[]={4,1,2,3,6,5};
Solution op;
vector<int> a_vector(a,a+sizeof(a)/sizeof(int));
vector<int> b_vector;
b_vector=op.readFromFile("Case.txt");
//for(int i=0; i< b_vector.size(); i++)
//{cout<<b_vector[i]<<endl;}
//op.quickSort(a_vector,0,sizeof(a)/sizeof(int)-1);
//for(int i=0; i< sizeof(a)/sizeof(int); i++)
//{cout<<a_vector[i]<<endl;}

int tot=op.findInversion(b_vector,0,b_vector.size()-1);
//int tot=op.findInversion(a_vector,0,a_vector.size()-1);
cout<<"tot inversion="<<tot<<endl;
}
