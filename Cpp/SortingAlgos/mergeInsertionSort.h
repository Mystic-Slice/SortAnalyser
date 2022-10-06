#include<vector>
#include<iostream>
using namespace std;

void mergeRuns(vector<int>& array,int l,int m,int r,CppAnalyser &analyser){
	int len1=m-l+1;
	int len2=r-m;
	vector<int>left(len1);
	vector<int>right(len2);
	int i, j, k;
	for(i=0;i<len1;i++){
		analyser.iterate();
		left[i]=array[l+i];
	}
	for(i=0;i<len2;i++){
		analyser.iterate();
		right[i]=array[m+i+1];
	}
	analyser.trackSpace(left);
	analyser.trackSpace(right);
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

void insertionSortRun(vector<int>&array,int begin,int end,CppAnalyser &analyser){
	for(int i = begin+1; i<=end; i++) {
		analyser.iterate();
		int j = i;
		while (analyser.comparegt(j, begin) && analyser.comparelt(array[j], array[j-1])) {
			analyser.swap(array[j], array[j-1]);
			j--;
		}
	}
}

int minlen(int n) {
	int r=0;
	while (n>=32) {
		r|=n&1;
		n>>=1;
	}
	return n+r;
}

void mergeInsertionSort(int numElements,vector<int>&array,CppAnalyser &analyser){
	analyser.startTimer();
	analyser.trackSpace(array);

	int n=array.size();
	int m = minlen(n);

	int end;
	for(int i = 0; i<n; i+=m) {
		end = min(i+m-1, n-1);
		insertionSortRun(array, i, end, analyser);
	}

	int length = m;
	while (length < n) {
		for(int l = 0; l < n; l += 2*length) {
			int mid = min(n-1, l + length - 1);
			int r = min((l + 2*length - 1), (n-1));
			if (mid < r) 
				mergeRuns(array, l, mid, r, analyser);
		}
		length = length * 2;
	}
	analyser.endTimer();
	return;
}