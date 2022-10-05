// Quick Sorting Algorithm
#include <vector>
#include <iostream>

using namespace std;

int partitionInsertion(vector<int>& array, int start, int end, CppAnalyser& analyser) {

    // Setting the pivot point
    int pivot = array[end];

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

void insertionSortMini( int start, int end, vector<int>& array, CppAnalyser &analyser) {
    int key, j;
    // Traveresing the array for Sorting
    for(int index = start; index < end+1; index++ ) {        
        key = array[index];
        j = index - 1;
        
        // Comparing the array elements with key value
        while ((!analyser.comparelt(j,0)) && analyser.comparegt(array[j],key)) {
            analyser.iterate();
            // Shifting the array elements to one position ahead
            analyser.swap(array[j + 1], array[j]);
        
            j = j - 1;
        }
        
        // Replacing the array element with the key value
        analyser.swap(array[j + 1], key);
    }
} 

void doQuickSortInsertion(vector<int>& array, int start, int end, CppAnalyser& analyser) {
    if(end-start+1 <= 6) {
        int key, j;
        // Traveresing the array for Sorting
        for(int index = start; index < end+1; index++ ) {        
            key = array[index];
            j = index - 1;
            
            // Comparing the array elements with key value
            while ((!analyser.comparelt(j,0)) && analyser.comparegt(array[j],key)) {
                analyser.iterate();
                // Shifting the array elements to one position ahead
                analyser.swap(array[j + 1], array[j]);            
                j = j - 1;
            }
            
            // Replacing the array element with the key value
            analyser.swap(array[j + 1], key);
        }
        return;
    }
    
    // Partitioning The Array
    int partition_val = partitionInsertion(array, start, end, analyser);
    // Quick Sorting the array indexing from start to (partition index value - 1)
    doQuickSortInsertion(array, start, partition_val - 1, analyser);
    // Quick Sorting the array indexing from (partition index value + 1) to end
    doQuickSortInsertion(array, partition_val + 1, end, analyser);
}

void quickSortInsertion(int numElements, vector<int>& array, CppAnalyser& analyser) {
    analyser.startTimer();
    analyser.trackSpace(array);
    doQuickSortInsertion(array, 0, numElements-1, analyser);
    analyser.endTimer();
}