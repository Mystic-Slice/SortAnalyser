#include <iostream>
#include <fstream>
#include <map>
#include <functional>
#include <assert.h>

#include "cppAnalyser.cpp"
#include "SortingAlgos/mergeSort.h"

using namespace std;

// To add new algorithms, add a new entry in this map
// Key - Algorithm name, will be recognised from commandline
// Value - Function name
// Don't forget to import the sorting function
map<string, function<void(vector<int> array, CppAnalyser& analyser)>> FUNCTIONS_DICT = {
    { "mergeSort", mergeSort }
};

vector<int> readArray() {
    ifstream fin;
    fin.open("../array.txt");

    int numElements;
    fin>>numElements;

    vector<int> array(numElements);
    for(int i = 0; i < numElements; i++) fin>>array[i];

    return array;
}

void runAnalysis(string sortingFunction) {

    // Check if the sorting function is avaiable
    if(!FUNCTIONS_DICT[sortingFunction]) {
        cout<<"Error: Sorting function not available"<<endl;
        exit(EXIT_FAILURE);
    }

    // Read array from file
    vector<int> array = readArray();
    int numElements = array.size();

    // Create analyser object
    CppAnalyser analyser;

    // Call the sorting function
    FUNCTIONS_DICT[sortingFunction](array, analyser);

    // Check if the array is sorted
    assert(is_sorted(array.begin(), array.end()));

    // Write data to file
    // filesystem::path filePath ("SortingAlgos");
    // filePath /= "data";
    // filePath /= sortingFunction + ".txt";
    // cout<<filePath.filename()<<endl;
    analyser.dump("SortingAlgos/data/" + sortingFunction + ".txt");
}

int main(int argc, char *argv[]) {

    if(argc != 2) {
        cout<<"Invalid number of arguments";
        exit(EXIT_FAILURE);
    }

    runAnalysis(argv[1]);

    return 0;
}