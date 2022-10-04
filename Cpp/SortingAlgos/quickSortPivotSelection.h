// Quick Sorting Algorithm
#include <vector>
#include <iostream>

using namespace std;

int partitionPivotSelection(vector<int>& array, int start, int end, CppAnalyser& analyser) {

    // Setting the pivot point
    int pivot = array[end];
    if(end-start+1 >= 3) {
        int pivotIndex;
        if ((array[start + 0] > array[start + 1]) ^ (array[start + 0] > array[start + 2]))
            pivotIndex = start + 0;
        else if ((array[start + 1] > array[start + 0]) ^ (array[start + 1] > array[start + 2]))
            pivotIndex = start + 1;
        else
            pivotIndex = start + 2;
        pivot = array[pivotIndex];
        analyser.swap(array[pivotIndex], array[end]);
    }

    int i = start - 1;
    // Iterating the loop for Sorting
    for(int j = start; j < end; j++) {
        analyser.iterate();
        if(!analyser.comparegt(array[j], pivot)) {
            i++;
            // Swaping the array elements
            analyser.swap(array[i], array[j]);
        }
    }

    // Swaping the array element and the pivot value
    analyser.swap(array[i+1], array[end]);
    // Returning the partition index value
    return i+1;
}

void doQuickSortPivotSelection(vector<int>& array, int start, int end, CppAnalyser& analyser) {
    if(analyser.comparelt(start, end)) {
        // Partitioning The Array
        int partition_val = partitionPivotSelection(array, start, end, analyser);
        // Quick Sorting the array indexing from start to (partition index value - 1)
        doQuickSortPivotSelection(array, start, partition_val - 1, analyser);
        // Quick Sorting the array indexing from (partition index value + 1) to end
        doQuickSortPivotSelection(array, partition_val + 1, end, analyser);
    }
}

void quickSortPivotSelection(int numElements, vector<int>& array, CppAnalyser& analyser) {
    analyser.startTimer();
    analyser.trackSpace(array);
    doQuickSortPivotSelection(array, 0, numElements-1, analyser);
    analyser.endTimer();
}