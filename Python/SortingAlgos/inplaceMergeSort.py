import math
def mS(array,start,nu,analyser):
	if start==(nu):
		return 
	middle=(start+nu)//2
	mS(array,start,middle,analyser)
	mS(array,middle+1,nu,analyser)
	merging(array,start,nu,analyser)

def merging(array,start,nu,analyser):
	q=nu-start+1
	if q<=1:
		q=0
	else:
		q=int(math.ceil(q/2))

	while analyser.comparegt(q,0):
		#analyser.iterate()
		i=start
		while(i+q)<=nu:
			j=i+q
			if(analyser.comparegt(array[i],array[j])):
				array[i],array[j]=analyser.swap(array[i],array[j])
			i+=1
		if q<=1:
			q=0
		else:
			q=int(math.ceil(q/2))



def inplaceMergeSort(numElements,array,analyser):
	analyser.startTimer()
	analyser.trackSpace(array)
	mS(array,0,len(array)-1,analyser)
	analyser.endTimer()
