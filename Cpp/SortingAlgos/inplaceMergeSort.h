#include<vector>
#include<cmath>
using namespace std;
int spacer(int g){
	if(g<=1)
		return 0;
	return (int)ceil(g / 2.0);

}
// void swap(vector<int>&array,int i,int j){
// 	int temp=array[i];
// 	array[i]=array[j];
// 	array[j]=temp;
// }
void merging(vector<int>&array,int start,int nu,CppAnalyser&analyser){
	int g=nu - start +1;
	for(g=spacer(g);g>0;g=spacer(g)){
		analyser.iterate();
		for(int i=start;i+g <=nu;i++){
			int j=i+g;
			if(analyser.comparegt(array[i],array[j]))
				analyser.swap(array[i],array[j]);
		}
	}
}
void func(vector<int>&array,int start,int nu,CppAnalyser&analyser){
	if(start==nu){
		return;
	}
	int mid;
	mid=(start+nu)/2;
	func(array,start,mid,analyser);
	func(array,mid+1,nu,analyser);
	merging(array,start,nu,analyser);
}
void inplaceMergeSort(int numElements,vector<int>&array,CppAnalyser &analyser){
	analyser.startTimer();
	analyser.trackSpace(array);
	int length=array.size();
	func(array,0,length-1,analyser);
	for(int i=0;i<length;i++){
		cout<<array[i]<<" ";
	}
	analyser.endTimer();
}