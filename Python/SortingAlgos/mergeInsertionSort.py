def minlen(n):
	r=0
	while n>=32:
		r|=n&1
		n>>=1
	return n+r

def merge(array,l,mid,r,analyser):
	len1=mid-l+1
	len2=r-mid
	left=[]
	analyser.trackSpace(left)
	right=[]
	analyser.trackSpace(right)
	for i in range(0,len1):
		analyser.iterate()
		left.append(array[l+i])
	for i in range(0,len2):
		analyser.iterate()
		right.append(array[mid+i+1])
	i=0
	j=0
	k=l
	while analyser.comparelt(i,len1)and analyser.comparelt(j,len2):
		if left[i]<=right[j]:
			array[k]=left[i]
			i+=1
		else:
			array[k]=right[j]
			j+=1
		k+=1
	while analyser.comparelt(i,len1):
		array[k]=left[i]
		k+=1
		i+=1
	while analyser.comparelt(j,len2):
		array[k]=right[j]
		k+=1
		j+=1

def insertion(array,begin,end,analyser):
	for i in range(begin+1,end+1):
		analyser.iterate()
		j=i
		while analyser.comparegt(j,begin) and analyser.comparelt(array[j],array[j-1]):
			array[j],array[j-1]=analyser.swap(array[j],array[j-1])
			j-=1

def mergeInsertionSort(numElements,array,analyser):
	analyser.startTimer()
	n=len(array)
	m=minlen(n)
	analyser.trackSpace(array)
	for i in range(0,n,m):
		end=min(i+m-1,n-1)
		insertion(array,i,end,analyser)
	length=m
	while length<n:
		for l in range(0,n,2*length):
			mid=min(n-1,l+length-1)
			r=min((l+2*length-1),(n-1))
			if mid<r:
				merge(array,l,mid,r,analyser)
		length=length*2

	analyser.endTimer()