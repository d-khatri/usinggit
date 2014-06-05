#include <iostream>
using namespace std;

void siftDown( int *a, int k, int N);

void swap(int *m, int *n)
{
	int tmp;
	tmp = *m;
	*m = *n;
	*n = tmp;
}

void heapsort( int a[], int N){
	for (int k = N/2; k >= 0; k--) 	siftDown( a, k, N);	/* heapify */

	cout<<"heapified array is "<<endl;
	for(int i=0;i<N;i++) cout<<a[i]<<" "; cout<<endl;
	
	while (N-1 > 0) {
		swap(a[N-1], a[0]);		/* swap the root(maximum value) of the heap	with the last element of the heap */
		siftDown(a, 0, N-1);	/* put the heap back in max-heap order */
		N--;	/* N-- : decrease the size of the heap by one so that the previous max value will stay in its proper placement */
	}
}

void siftDown( int *a, int k, int N){
	while ( k*2 + 1 < N ) {
 		int child = 2*k + 1;
		
		if ((child + 1 < N) && (a[child] < a[child+1])) child++;
		
		if (a[k] < a[child]) {
			swap( a[child], a[k] );
			k = child;
		}
		else
			return;
	}
}

int main()
{
	int i;
	int a[] = {19, 17,-32,0,234, 15, 1, 2, 11, 7, 3, 10, 14};
	int sz = sizeof(a)/sizeof(a[0]);
	heapsort(a, sz);
	cout<<"sorted array is\n";
	for (i = 0; i < sz; i++)	cout << a[i] << " ";	cout << endl;
	return 0;
}
