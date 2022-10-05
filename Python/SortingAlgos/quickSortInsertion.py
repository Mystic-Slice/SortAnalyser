# Quick Sorting Algorithm
def partitionInsertion(array: list, start: int, end: int,analyser):

    # Setting the pivot point
    pivot = array[end]

    i = start-1    
    # Iterating the loop for Sorting
    for j in range(start,end):
        analyser.iterate()
        if(not analyser.comparegt(array[j],pivot)):
            i+=1
            # Swaping the array elements
            array[i],array[j] = analyser.swap(array[i],array[j])
    # Swaping the array element and the pivot value
    array[i+1],array[end] = analyser.swap(array[i+1],array[end])
    # Returning the partition index value
    return i+1

def doQuickSortInsertion(array: list, start: int, end: int,analyser):
    if(end-start+1 <= 6):
        # Traversing the array for Sorting
        for index in range(start, end+1):
            key = array[index]
            j = index - 1

            # Comparing the array elements with key value
            while ((not analyser.comparelt(j,0)) and analyser.comparegt(array[j],key)):
                analyser.iterate()
                # Shifting the array elements to one position ahead
                array[j+1],array[j] = analyser.swap(array[j+1],array[j])
                j = j - 1
        
            # Replacing the array element with the key value
            array[j+1], key = analyser.swap(array[j + 1], key)
        return

    # Partitioning The Array
    partition_val = partitionInsertion(array,start,end,analyser)
    # Quick Sorting the array indexing from start to (partition index value - 1)
    doQuickSortInsertion(array,start,partition_val-1,analyser)
    # Quick Sorting the array indexing from (partition index value + 1) to end
    doQuickSortInsertion(array, partition_val+1, end,analyser)

def quickSortInsertion(numElements: int, array: list, analyser):
    analyser.startTimer()
    analyser.trackSpace(array)
    doQuickSortInsertion(array, 0, numElements-1, analyser)
    analyser.endTimer()