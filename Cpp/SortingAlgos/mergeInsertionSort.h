#include<vector>
#include<iostream>
using namespace std;
void insertion(vector<int>&array,int left,int right,CppAnalyser &analyser){
	int i;
	int temp;
	int j;
	for(i=left+1;i<=right;i++){
		analyser.iterate();
		temp=array[i];
		j=i-1;
		while(j>=left && analyser.comparegt(array[j],temp)){
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=temp;
	}
}
void merger(vector<int>array,int l,int m,int r,CppAnalyser &analyser){
	int len1=m-l+1;
	int len2=r-m;
	vector<int>left(len1);
	analyser.trackSpace(left);
	vector<int>right(len2);
	analyser.trackSpace(right);
	int i;
	int j;
	int k;
	for(i=0;i<len1;i++){
		analyser.iterate();
		left[i]=array[l+i];
	}
	for(i=0;i<len2;i++){
		analyser.iterate();
		right[i]=array[m+l+i];
	}
	i=0;
	j=0;
	k=l;
	while(analyser.comparelt(i,len1) && analyser.comparelt(j,len2)){
		if(left[i]<=right[j]){
			array[k]=left[i];
			i++;
		}
		else{
			array[k]=right[j];
			j++;
		}
		k++;
	}
	while(analyser.comparelt(i,len1)){
		array[k]=left[i];
		k++;
		i++;
	}
	while(analyser.comparelt(j,len2)){
		array[k]=right[j];
		k++;
		j++;
	}
}
void mergeInsertionSort(int numElements,vector<int>&array,CppAnalyser &analyser){
	analyser.startTimer();
	analyser.trackSpace(array);
	cout<<"Here"<<endl;
	int n=array.size();
	int i;
	int j;
	int left;
	int mid;
	int right;
	for(i=0;i<n;i+=32)
		insertion(array,i,min((i+32-1),(n-1)),analyser);
	for(j=32;j<n;j=2*j){
		analyser.iterate();
		for(left=0;left<n;left+=2*j){
			mid=left+j-1;
			right=min((left + 2*j - 1),(n-1));

			if(analyser.comparelt(mid,right))
				merger(array,left,mid,right,analyser);
		}
	}
	analyser.endTimer();
	return;
}