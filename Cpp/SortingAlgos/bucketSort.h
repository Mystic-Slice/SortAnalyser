// Bucket Sort Algorithm
#include <vector>
#include <iostream>

using namespace std;

void bucketSort(int numElements, vector<int>& array, CppAnalyser &analyser) {
    analyser.startTimer();
    analyser.trackSpace(array);

    int NUM_BUCKETS = numElements/10;
    vector<vector<int>> buckets(NUM_BUCKETS, vector<int>());

    int max = *max_element(array.begin(), array.end());
    for(auto num: array) {
        analyser.iterate();
        int index = (NUM_BUCKETS * num) /(double) (max + 1);
        buckets[index].push_back(num);
    }

    int ptr = 0;
    for(auto bucket: buckets) {
        insertionSort(bucket.size(), bucket, analyser);
        for(auto num: bucket) {
            array[ptr] = num;
            ptr++;
        }
    }

    analyser.endTimer();
}