There are multiple ways to sort an array, or multiple, each having its own advantages and disadvantages, a quick example that will be touch upon later in greater detail would be bubble sort, the simplest algorithm to implement and code, yet the slowest algorithm to complete.

**Starting with Sorting algorithms in the book**
# 7.2 - Insertion Sort
Known as one of the simplest algorithms.

## 7.2.1 - Algorithm
It consists of $N-1$ passes. For pass $p=1$ through $N-1$, insert sort makes sure that the elements in positions 0 through *p* are sorted in order. It makes use of the fact that the elements in positions 0 through $p-1$ are already known to be in sorted order.

*Code from book*
```c++
1 /**
2 * Simple insertion sort.
3 */
4 template <typename Comparable>
5 void insertionSort( vector<Comparable> & a )
6 {
7 for( int p = 1; p < a.size( ); ++p )
8 {
9 Comparable tmp = std::move( a[ p ] );
10
11 int j;
12 for( j = p; j > 0 && tmp < a[ j - 1 ]; --j )
13 a[ j ] = std::move( a[ j - 1 ] );
14 a[ j ] = std::move( tmp );
15 }
16 }
Figure 7.2 Insertion sort routine
```

```c++
1 template <typename Iterator, typename Comparator>
2 void insertionSort( const Iterator & begin, const Iterator & end,
3 Comparator lessThan )
4 {
5 if( begin == end )
6 return;
7
8 Iterator j;
9
10 for( Iterator p = begin+1; p != end; ++p )
11 {
12 auto tmp = std::move( *p );
13 for( j = p; j != begin && lessThan( tmp, *( j-1 ) ); --j )
14 *j = std::move( *(j-1) );
15 *j = std::move( tmp );
16 }
17 }
Figure 7.4 Three-parameter sort using iterators
```

## 7.2.3 - Analysis of Insertion Sort
Thanks to the nested loops (each loop can take *N* iterations), insert sort has $O(N^2)$. Not only that, but this bound is tight, since the input in reverse order can achieve this bound. By calculating the number of tests in the inner loop in *Figure 7.2*, is at most $p+1$ for each value of *p*. Giving:
$$\sum^{N}_{i=2}{i=2+3+4+...+O(N^2)}$$
However, if the input is presorted, then the running time is $O(N)$, since the test in the inner **for** loop will always fail immediately. If the input is almost sorted, insert sort will run quickly. Because of this wide variation in running time, it is worth mentioning the average case behaviour of it, $O(N^2)$.

# 7.3 - A Lower Bound for Simple Sorting Algorithms
An **inversion** in an array is any ordered pair ($i,j$) with the property $i<j$ but $a[i]>a[j]$. Swapping two adjacent elements that are out of place, removes exactly one inversion, and a sorted array has no inversions. Since there is a $O(N)$ at work in the algorithm, as an example, the running time of *insert sort* is $O(I+N)$, where $I$ is the number of inversions in the original array. Thus, making insert sort run in a linear time **if** the number of inversions is $O(N)$.

We can compute precise bounds on the average running time of insert sort by computing the average number of inversions in a permutation. There are two theorems that can be use in specific cases.
For the first one we need to assume that there are no duplicate elements, and we need to assume that the input is some permutation of the first N integers and that all are equally likely. Under these assumptions, the following theorem is true:
## **Theorem 1**
The average number of inversions in an array of *N* distinct elements is $N(N-1)/4$
### Proof
For any list $L$ of elements, there is $L_r$, the list in reverse order. In any pair of two elements in the list $(x, y)$ with $y > x$. In one of $L$ and $L_r$, this ordered pair represents an inversion. The total number of these pairs in a list $L$ and its reverse is $N(N−1)/2$. Thus, an average list has half this amount, or $N(N − 1)/4$ inversions.

## **Theorem 2**
Any algorithm that sorts by exchanging adjacent elements requires $O(N^2)$ time on
average.
### Proof
The average number of inversions is initially $N(N−1)/4 = O(N^2)$. Each swap removes
only one inversion, so $O(N2)$ swaps are required.

# 7.4 - Shell Sort
It is one of the first algorithms to break the quadratic time barrier, although it was several years after the discovery of a sub-quadratic time bound. In Layman's terms, it works by comparing elements that are distant, the distance between comparisons decreases as the algorithm runs until the last phase, where the adjacent elements are compared instead. It is because of this that it is also known as *Diminishing Increment Sort*.

**Shell Sort** uses a sequence of $h_1,h_2,...,h_t$, called *Increment Sequence*. Any increment sequence will work as long as $h_1=1$.
After every phase, using an increment $h_k$ for every $i$, we have $a[i]≤ a[i + h_k]$, where all elements spaced $h_k$ apart are sorted. It is then named *$h_k$-sorted*.

An important property of Shell Sort is that a $h_k$-sorted file, that is then $h_{k-1}$-sorted remains as $h_k$sorted. If this is not the case, the algorithm would likely be of little value, since work done by early phases would be undone by later phases.

*Code from book*
```c++
1 /**
2 * Shellsort, using Shell’s (poor) increments.
3 */
4 template <typename Comparable>
5 void shellsort( vector<Comparable> & a )
6 {
7 for( int gap = a.size( ) / 2; gap > 0; gap /= 2 )
8 for( int i = gap; i < a.size( ); ++i )
9 {
10 Comparable tmp = std::move( a[ i ] );
11 int j = i;
12
13 for( ; j >= gap && tmp < a[ j - gap ]; j -= gap )
14 a[ j ] = std::move( a[ j - gap ] );
15 a[ j ] = std::move( tmp );
16 }
17 }
Figure 7.6 Shellsort routine using Shell’s increments (better increments are possible)
```

## 7.4.1 - Worst-Case Analysis of Shell Sort
Although shell sort is simple to code, it is not the same case with its running time. The running time of shell sort depends on the choice of increment sequence. The average case analysis of shell sort is rather complicated, except for the most trivial increment sequences.

A popular, but rather poor, choice of increment sequence was made by Shell: $h_t=[N/2]$, and $h_k=[h_{k+1}/2]$
### **Theorem 3**
The worst case of running time for Shell Sort using Shell's increments is $O(N^2)$.
#### Proof
we choose *N* to be a power of 2. This makes all the increments even, except for the last increment, which is 1. Now, we will give as input an array with the $N/2$ largest numbers in the even positions and the $N/2$ smallest numbers in the odd positions.
As all the increments except the last are even, when we come to the last pass, the $N/2$ largest numbers are still all in even positions and the $N/2$ smallest numbers are still all in odd positions.

The *ith* smallest number $(i ≤ N/2)$ is thus in position $2i − 1$ before the beginning of the last pass. Restoring the *ith* element to its correct place requires moving it $i−1$ spaces in the array. Thus, to merely place the $N/2$ smallest elements in the correct place requires at least $\sum^{N/2}_{i=1}{i − 1 = O(N^2)}$ in order to work.

To finish the proof, we show the upper bound of $O(N^2)$. As we have observed before, a pass with increment $h_k$ consists of $h_k$ insertion sorts of about $N/h_k$ elements. Since insertion sort is quadratic, the total cost of a pass is $O[h_k(N/h_k)^2] = O(N^2/h_k)$. Summing over all passes gives a total bound of $O(\sum ^t _{i=1} N^2/h_i) = O(N^2 \sum ^t _{i=1} 1/h_i)$.

Because the increments form a geometric series with common ratio 2, and the largest term in the series is $h_1 = 1, \sum ^t _{i=1} 1/h_i < 2$. Thus we obtain a total bound of $O(N^2)$.


The problem with Shell's increments is that pairs of increments are not necessarily relatively prime, and, as such the smaller increment can have little effect. Hibbard suggested a slightly different increment sequence, which gives better results in practice. His increments are of the form $1,3,7,...,2^k-1$. Although they are almost identical, the key difference is that consecutive increments have no common factors. The following theorem will explain the worst-case running time of Shell Sort using this increment sequence.

### **Theorem 4**
The worst-case running time of Shell sort using Hibbard's increments is $O(N^{3/2})$
#### Proof
![[Pasted image 20231123161042.png]]
![[Pasted image 20231123161101.png]]
![[Pasted image 20231123161118.png]]
![[Pasted image 20231123161142.png]]

# 7.5 - Heap Sort
Priority queues can be used to sort in $O(NlogN)$ time. This is where the algorithm of *Heap Sort*.

The basic strategy is to build a binary heap of *N* elements, making this stage take $O(N)$ time. It is then performed *N* `deleteMin` operations. The elements leave the heap's smallest first, in sorted order. By recording these elements in a second array and then copying the array back, we sort *N* elements. Since each `deleteMin` takes $O(logN)$ time, the total running time is $O(NlogN)$.

Its main problem is that it uses an extra array, doubling the memory requirement. It is important to note that the extra time spent copying the second array back to the first is only $O(N)$, it is not likely to affect the running time significantly. The problem is space.

A way to avoid using a second array is by shrinking the array by 1 after every `deleteMin`. Thus, the cell that was last in the heap can be used to store the element that was deleted. With this, after the last `deleteMin` the array will contain the elements in *decreasing sorted order*. If we want the elements in a more standard *increasing sorted order*, we can change the ordering property so that the parent has a larger element than the child, obtaining a *(max)heap*.

In the next example, a (max)heap will be used, and everything will be done in an array. The first step builds the heap in linear time, then we perform $N-1$ `deleteMaxes` by swapping the last element with the first, decrementing the heap size. When the algorithm ends, the array contains the elements in sorted order
![[Pasted image 20231123164239.png]]
## 7.5.1 - Analysis of Heap Sort
The first phase of Heap sort, which constitutes the building of the heap, uses less than $2N$ comparisons. In the second phase, the *ith* `deleteMax` uses less than $2[log (N − i + 1)]$ comparisons, for a total of $2NlogN-O(N)$ comparisons (assuming $N≥2$). Likewise, in the worst case, at most $2N logN − O(N)$ comparisons are used by Heap sort.
*Code from book*
```c++
1 /**
2 * Standard heapsort.
3 */
4 template <typename Comparable>
5 void heapsort( vector<Comparable> & a )
6 {
7 for( int i = a.size( ) / 2 - 1; i >= 0; --i ) /* buildHeap */
8 percDown( a, i, a.size( ) );
9 for( int j = a.size( ) - 1; j > 0; --j )
10 {
11 std::swap( a[ 0 ], a[ j ] ); /* deleteMax */
12 percDown( a, 0, j );
13 }
14 }
15
16 /**
17 * Internal method for heapsort.
18 * i is the index of an item in the heap.
19 * Returns the index of the left child.
20 */
21 inline int leftChild( int i )
22 {
23 return 2 * i + 1;
24 }
25
26 /**
27 * Internal method for heapsort that is used in deleteMax and buildHeap.
28 * i is the position from which to percolate down.
29 * n is the logical size of the binary heap.
30 */
31 template <typename Comparable>
32 void percDown( vector<Comparable> & a, int i, int n )
33 {
34 int child;
35 Comparable tmp;
36
37 for( tmp = std::move( a[ i ] ); leftChild( i ) < n; i = child )
38 {
39 child = leftChild( i );
40 if( child != n - 1 && a[ child ] < a[ child +1])
41 ++child;
42 if( tmp < a[ child ] )
43 a[ i ] = std::move( a[ child ] );
44 else
45 break;
46 }
47 a[ i ] = std::move( tmp );
48 }
Figure 7.10 Heapsort
```

The problem with Heap sort is that successive `deleteMax` operations destroy the heap's randomness, making the probability arguments very complex.
### **Theorem 5**
The average number of comparisons used to heapsort a random permutation of *N*
distinct items is $2N logN − O(N log logN)$.
#### Proof
![[Pasted image 20231123170245.png]]
![[Pasted image 20231123170257.png]]
![[Pasted image 20231123170319.png]]

# 7.6 - Merge Sort
Merge Sort runs in $O(NlogN)$ in the worst case, and the number of comparisons used is nearly optimal.
The fundamental operation in this algorithm is merging two sorted lists. Since the lists are sorted, this can be done in one pass through the input, if the output is put in a third list. The basic merging algorithm takes two input arrays A and B, an output array C and three counters ($Actr,Bctr,Cctr$), initially set to the beginning of their respective array. Then, the smaller value of $A[Actr]$ and $B[Bctr]$ is copied to the next entry in C, and the appropriate counters are advanced. Whenever one of the input lists is completed, the remainder of the other list is copied to C.
*Example of how merge sort works*
![[Pasted image 20231123190804.png]]
![[Pasted image 20231123190853.png]]
![[Pasted image 20231123190912.png]]

*Code from book*
```c++
1 /**
2 * Mergesort algorithm (driver).
3 */
4 template <typename Comparable>
5 void mergeSort( vector<Comparable> & a )
6 {
7 vector<Comparable> tmpArray( a.size( ) );
8
9 mergeSort( a, tmpArray, 0, a.size( ) - 1 );
10 }
11
12 /**
13 * Internal method that makes recursive calls.
14 * a is an array of Comparable items.
15 * tmpArray is an array to place the merged result.
16 * left is the left-most index of the subarray.
17 * right is the right-most index of the subarray.
18 */
19 template <typename Comparable>
20 void mergeSort( vector<Comparable> & a,
21 vector<Comparable> & tmpArray, int left, int right )
22 {
23 if( left < right )
24 {
25 int center = ( left + right ) / 2;
26 mergeSort( a, tmpArray, left, center );
27 mergeSort( a, tmpArray, center + 1, right );
28 merge( a, tmpArray, left, center + 1, right );
29 }
30 }
Figure 7.11 Mergesort routines
```

*Merge routine*
```c++
1 /**
2 * Internal method that merges two sorted halves of a subarray.
3 * a is an array of Comparable items.
4 * tmpArray is an array to place the merged result.
5 * leftPos is the left-most index of the subarray.
6 * rightPos is the index of the start of the second half.
7 * rightEnd is the right-most index of the subarray.
8 */
9 template <typename Comparable>
10 void merge( vector<Comparable> & a, vector<Comparable> & tmpArray,
11 int leftPos, int rightPos, int rightEnd )
12 {
13 int leftEnd = rightPos - 1;
14 int tmpPos = leftPos;
15 int numElements = rightEnd - leftPos + 1;
16
17 // Main loop
18 while( leftPos <= leftEnd && rightPos <= rightEnd )
19 if( a[ leftPos ] <= a[ rightPos ] )
20 tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
21 else
22 tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
23
24 while( leftPos <= leftEnd ) // Copy rest of first half
25 tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
26
27 while( rightPos <= rightEnd ) // Copy rest of right half
28 tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
29
30 // Copy tmpArray back
31 for( int i = 0; i < numElements; ++i, --rightEnd )
32 a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );
33 }
Figure 7.12 merge routine
```
## 7.6.1 - Analysis of Merge Sort
Merge sort is an example of the techniques used to analyze recursive routines. We have to write a recurrence relation for the running time. When assuming that *N* is a power of *2* so that it can always be split into halves.
- For $N=1$, the time for merge sort is **constant**  -->  $T(1)=1$ 
- Otherwise, the time for merge sort *N* numbers is equal to the time to do two recursive merge sorts of size $N/2$, making it **linear**  -->  $T(N)=2T(N/2)+N$

This is a standard recurrence relation, which can be solved in multiple ways. The first way is to divide the recurrence relation through by *N*, yielding
![[Pasted image 20231123192408.png]]

An alternative method is to substitute the recurrence relation continually on the right-hand side:
![[Pasted image 20231123192543.png]]
![[Pasted image 20231123192555.png]]

Choosing between each method depends on the person, the first method tends to produce less mathematical errors, but it requires a certain amount of experience to apply. Meanwhile, the second method is more of a brute-force approach.

Although merge sort's running time is $O(NlogN)$, it has the significant problem that merging two sorted lists uses linear extra memory. Adding work by copying to the temporary array and back throughout the algorithm, slows the sorting considerably. This copying can be avoided by meticulously switching the roles of `a` and `tmpArray` at alternate levels of the recursion.

The running time of Merge sort, specially when comparing it with others with $O(NlogN)$, depends heavily on the relative costs of comparing elements and moving elements in the array (as well as in the temporary array). The costs are language dependent.
*Examples of laguage dependent costs*
![[Pasted image 20231123194042.png]]

# 7.7 - Quick Sort
*Quick Sort* has been the fastest known generic sorting algorithm in practice. Its average running time is $O(NlogN)$. Its speed comes from a very tight and highly optimized inner loop. In the worst case, quick sort has a speed of $O(N^2)$, although this is highly unlikely with a little effort. By combining *Quick Sort* with *Heap Sort*, we can obtain quick sort's fast running time on almost all inputs, with heapsort's worst case running time of $O(NlogN)$.

Quick sort's algorithm is simple and easy to understand and, like merge sort, is a divide-and-conquer recursive algorithm.

The classic quick sort algorithm to sort an array *S* consists of the following four steps:
1. If the number of elements in *S* is *0* or *1*, then return.
2. Pick any element *v* in *S*. This is called the pivot.
3. Partition *S − {v}* (the remaining elements in *S*) into two disjoint groups: $S_1 =$ {x ∈
S − {v} | x ≤ v}, and $S_2 =$ {x ∈ S − {v} | x ≥ v}.
4. Return  {quicksort($S_1$) followed by *v* followed by quicksort($S_2$)}.

Since the partition step describes ambiguously what to do with elements equal to the pivot, this becomes a design choice, becoming part of a good implementation by by handling this case as efficiently as possible. It is desired that half the elements that are equal to the pivot go into $S_1$ and the other half into $S_2$.

The reason why *quick sort* is faster than *merge sort* is that the partitioning step can actually be performed in place and efficiently. Its this efficiency that makes up for the lack of recursive calls. However, even the slightest deviations from the following method can cause surprisingly bad results.

## 7.7.1 - Picking the Pivot
Although the algorithm works, no matter which element is chosen as the pivot, some choices are better than others.
![[Pasted image 20231123202111.png]]

### A Wrong Way
The popular, uninformed choice is to use the first element as the pivot. This is acceptable if the input is random, but if the input is presorted or in reverse order, then the pivot provides a poor partition, because either all the elements go into $S_1$ or they go into $S_2$. Worse, this happens consistently throughout the recursive calls. The practical effect is that if the first element is used as the pivot and the input is presorted, then quicksort will take quadratic time to do essentially nothing at all, which is quite embarrassing. Moreover, presorted input (or input with a large presorted section) is quite frequent, so using the first element as pivot is an absolutely horrible idea and should be discarded immediately. An alternative is choosing the larger of the first two distinct elements as pivot, but this has the same bad properties as merely choosing the first element. Do not use that pivoting strategy, either.

### A Safe Maneuver
A safe course is merely to choose the pivot randomly. This strategy is generally perfectly safe, unless the random number generator has a flaw, since it is very unlikely that a random pivot would consistently provide a poor partition. On the other hand, random number generation is generally an expensive commodity and does not reduce the average running time of the rest of the algorithm at all.

### Median-of-Three Partitioning
The median of a group of *N* numbers is the $N/2th$ largest number. The best choice of pivot would be the median of the array. Unfortunately, this is hard to calculate and would slow down quick sort considerably. A good estimate can be obtained by picking three elements randomly and using the median of these three as pivot. The randomness turns out not to help much, so the common course is to use as pivot the median of the left, right, and center elements. For instance, with input $8, 1, 4, 9, 6, 3, 5, 2, 7, 0$, the left element is 8, the right element is 0, and the center (in position ($[left + right)/2]$) element is 6. Thus, the pivot would be $v = 6$. Using *median-of-three* partitioning eliminates the bad case for sorted input (the partitions become equal in this case) and actually reduces the number of comparisons by 14%.

## 7.7.2 - Partitioning Strategy
The first step is to get the pivot element out of the way by swapping it with the last element. Then, *i* starts at the first element and *j* starts at the next-to-last element.
![[Pasted image 20231123203150.png]]
![[Pasted image 20231123203223.png]]
![[Pasted image 20231123203250.png]]
![[Pasted image 20231123203309.png]]
![[Pasted image 20231123203325.png]]

An important detail to consider is how to handle elements that are equal to the pivot. The question is whether or not *i* and *j* should stop when they see an element equal to the pivot. Normally, both *i* and *j* should do the same thing, since otherwise the partitioning step becomes biased. An example of this, if *i* stops but *j* does not, then all elements that are equal to the pivot will end up in $S_2$.

To understand what might be good, lets consider the case where all the elements in the array are identical. If both *i* and *j* stop, there will be many swaps between identical elements. Although this seems useless, the positive effect is that *i* and *j* will cross in the middle, so when the pivot is replaced, the partition creates two nearly equal subarrays. The merge sort analysis tells us that the total running time would then be $O(N logN)$.

On the other hand, if neither of them stops and a code that prevents them from leaving the array is set, no swaps will be performed. Although this seems good, a correct implementation would then swap the pivot into the last spot that *i* touched, which would be the *next-to-last* position (or last, depending on the exact implementation). This would create uneven subarrays. If all the elements are identical, the running time is $O(N^2)$. The effect is the same as using the first element as a pivot for presorted input.

With this in mind, it is better to do unnecessary swaps and create even subarrays than to risk uneven subarrays.

## 7.7.3 - Small Arrays
For very small arrays $(N≤ 20)$, quick sort does not perform as well as *insert sort*. Not only that, but because quick sort is recursive, it is best to not use *quick sort* for small arrays but instead use a sorting algorithm that's efficient for small arrays, like *insert sort*. 

## 7.7.4 - Actual Quick Sort Routines
*Driver for Quick Sort*
```c++
1 /**
2 * Quicksort algorithm (driver).
3 */
4 template <typename Comparable>
5 void quicksort( vector<Comparable> & a )
6 {
7 quicksort( a, 0, a.size( ) - 1 );
8 }
Figure 7.15 Driver for quicksort
```

![[Pasted image 20231123205311.png]]
![[Pasted image 20231123205336.png]]
![[Pasted image 20231123205447.png]]
![[Pasted image 20231123205350.png]]
![[Pasted image 20231123205406.png]]

## 7.7.5 - Analysis of Quick Sort
Similar to *merge sort*, quick sort is recursive. This means that its analysis requires solving a recurrence formula. The analysis of quick sort will assume a random pivot (no median-of-three partitioning) and no cutoff for small arrays. It will also use $T(0)=T(1)=1$, like merge sort.

The running time of quicksort is equal to the running time of the two recursive calls plus the linear time spent in the partition (the pivot selection takes only constant time). This gives the basic quick sort relation
$$T(N) = T(i) + T(N − i − 1) + cN$$
where $i = |S_1|$ is the number of elements in $S_1$.

### Worst-Case Analysis
The pivot is the smallest element all the time. Then $i = 0$, and if we ignore $T(0) = 1$, the recurrence is
$$T(N) = T(N − 1) + cN, N > 1$$
	$T(N − 1) = T(N − 2) + c(N − 1)$
	$T(N − 2) = T(N − 3) + c(N − 2)$
	.
	.
	.
	$T(2) = T(1) + c(2)$

Adding all these equations yields
$$T(N) = T(1) + c \sum ^N _{i=2} i = O(N^2)$$

### Best-Case Analysis
In the best case, the pivot is in the middle. For simplicity's sake, lets assume that both subarrays are exactly half the size of the original, and, although this gives a slight overestimate, this is acceptable because we are only interested in a $O(N)$ answer.
$$T(N) = 2T(N/2) + cN$$
	$\frac{T(N)}{N}=\frac{T(N/2)}{N/2}+c$
	$\frac{T(N/2)}{N/2}=\frac{T(N/4)}{N/4}+c$
	$\frac{T(N/4)}{N/4}=\frac{T(N/8)}{N/8}+c$
	.
	.
	.
	$\frac{T(2)}{2}=\frac{T(1)}{1}+c$

We add all the equations
$$\frac{T(N)}{N}=\frac{T(1)}{1}+clogN$$
yielding
$$T(N) = cN logN + N = O(N logN)$$

### Average-Case Analysis
For the average case, we assume that each of the sizes of $S_1$ is equally likely, and hence has a probability of $1/N$. This assumption is actually valid for our pivoting and partitioning strategy, but it is not valid for some others. Partitioning strategies that do not preserve the randomness of the subarrays cannot use this analysis.

With this assumption, the average value of $T(i)$, and hence $T(N − i − 1)$, is $(1/N) \sum^{N−1} _{j=0} T(j)$, becoming
$$T(N)=\frac{2}{N}[\sum^{N-1}_{j=0}T(j)] + cN$$
	$NT(N)=2[\sum^{N-1}_{j=0}T(j)] + cN^2$
	$(N − 1)T(N − 1) = 2[\sum^{N-2}_{j=0}T(j)] + c(N-1)^2$
	$NT(N) − (N − 1)T(N − 1) = 2T(N − 1) + 2cN − c$
	$NT(N) = (N + 1)T(N − 1) + 2cN$
	$\frac{T(N)}{N+1}=\frac{T(N-1)}{N}+\frac{2c}{N+1}$
	$\frac{T(N-1)}{N}=\frac{T(N-2)}{N-1}+\frac{2c}{N}$
	$\frac{T(N-2)}{N-1}=\frac{T(N-3)}{N-2}+\frac{2c}{N-1}$
	.
	.
	.
	$\frac{T(2)}{3}=\frac{T(1)}{2}+\frac{2c}{3}$
	$\frac{T(N)}{N+1}=\frac{T(1)}{2}+2c \sum^{N+1}_{i=3}\frac{1}{i}$
	$\frac{T(N)}{N+1}=O(logN)$

yielding
$$T(N) = O(N logN)$$
*Proof  because I'm too lazy to write*
![[Pasted image 20231123213658.png]]
![[Pasted image 20231123213712.png]]

## 7.7.6 - A Linear-Expected-Time Algorithm for Selection
Quick sort can be modified to solve the *selection problem*. By using a priority queue, we can find the *kth* largest (or smallest) element in $O(N+klogN)$.

Since we can sort the array in $O(N logN)$ time, one might expect to obtain a better time bound for selection. The algorithm we present to find the *kth* smallest element in a set *S* is almost identical to quick sort. In fact, the first three steps are the same. This algorithm will be called *Quick Select*. Let $|S_i|$ denote the number of elements in $S_i$. The steps of quick select are
	1. If $|S| = 1$, then $k = 1$ and return the element in *S* as the answer. If a cutoff for small
	arrays is being used and $|S| ≤ CUTOFF$, then sort *S* and return the *kth* smallest element.
	2. Pick a pivot element, *v ∈ S*.
	3. Partition *S − {v}* into $S_1$ and $S_2$, as was done with quick sort.
	4. If $k ≤ |S_1|$, then the *kth* smallest element must be in $S_1$. In this case, return $quickSelect(S_1, k)$. If $k = 1 + |S_1|$, then the pivot is the *kth* smallest element and we can return it as the answer. Otherwise, the *kth* smallest element lies in $S_2$, and it is the $(k − |S_1| − 1)$*st* smallest element in $S_2$. We make a recursive call and return $quickSelect(S_2, k − |S_1| − 1)$.

In contrast to *quick sort*, quick select makes only one recursive call instead of two. The worst case of *quick select* is identical to that of quick sort and is $O(N^2)$. This is because quick sort’s worst case is when one of $S_1$ and $S_2$ is empty. Thus, quick select is not really saving a recursive call. Nevertheless, the average running time is $O(N)$.

*Code from book*
```c++
1 /**
2 * Internal selection method that makes recursive calls.
3 * Uses median-of-three partitioning and a cutoff of 10.
4 * Places the kth smallest item in a[k-1].
5 * a is an array of Comparable items.
6 * left is the left-most index of the subarray.
7 * right is the right-most index of the subarray.
8 * k is the desired rank (1 is minimum) in the entire array.
9 */
10 template <typename Comparable>
11 void quickSelect( vector<Comparable> & a, int left, int right, int k )
12 {
13 if( left + 10 <= right )
14 {
15 const Comparable & pivot = median3( a, left, right );
16
17 // Begin partitioning
18 int i = left, j = right - 1;
19 for( ; ; )
20 {
21 while( a[ ++i ] < pivot ) { }
22 while( pivot < a[ --j ] ) { }
23 if( i < j )
24 std::swap( a[ i ], a[ j ] );
25 else
26 break;
27 }
28
29 std::swap( a[ i ], a[ right - 1 ] ); // Restore pivot
30
31 // Recurse; only this part changes
32 if( k <= i )
33 quickSelect( a, left, i - 1, k );
34 else if( k>i+1)
35 quickSelect( a, i + 1, right, k );
36 }
37 else // Do an insertion sort on the subarray
38 insertionSort( a, left, right );
39 }
Figure 7.19 Main quickselect routine
```

# Conclusions & Investigation
## Investigation
### **Bubble Sort**
One of, if not the most, simplest sorting algorithms. It repeatedly steps through the list, comparing adjacent elements, from left to right, swapping their positions if they are not in order. The pass through the list is repeated until it finds two elements that need to be swapped or the list is sorted.
*Code from Chat GPT*
```c++
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				// swap elements
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
```

#### **Space & Time Complexity**
Space Complexity = $O(1)$

##### Time Complexity
**Worst Case =** $O(N^2)$
**Average Case =** $O(N^2)$
**Best Case =** $O(N)$

*Graphic Example of Bubble*
![[Pasted image 20231123220741.png]]

#### **Why use it?**
- It is the simplest type of sorting algorithms.
- It helps as an introduction for sorting algorithms for new programmers
- It works well with small arrays (or as a final check for datasets in nearly sorted order)

#### **Why not to use it?** 
- It is extremely slow
- Since it has to cycle through the entire array repeatedly, comparing only two adjacent elements at a time, it is not optimal for big arrays


### **Selection Sort**
Selection Sort works by repeatedly selecting the smallest (or largest) element from the unsorted part of the array and moving it to the sorted part of the array (beginning of array).
*Code from Chat GPT*
```c++
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // swap elements
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
```

#### **Space & Time Complexity**
Space Complexity = $O(1)$

##### Time Complexity
**Worst Case =** $O(N^2)$
**Average Case =** $O(N^2)$
**Best Case =** $O(N^2)$

*Graphic Example of Selection*
![[Pasted image 20231123223551.png]]

#### **Why use it?**
- It is simple and easy to understand
- Works with small arrays

#### **Why not to use it?** 
- Has a time complexity of $O(N^2)$ in the worst and average case
- Does not work well with large arrays


### **Insert Sort**
*Code from ChatGPT*
```c++
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

```

#### **Space & Time Complexity**
Space Complexity = $O(1)$

##### Time Complexity
**Worst Case =** $O(N^2)$
**Average Case =** $O(N^2)$
**Best Case =** $O(N)$


### **Merge Sort**
*Code from ChatGPT*
```c++
void merge(int arr[], int l, int m, int r) {
    // merge two subarrays
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
```

#### **Space & Time Complexity**
Space Complexity = $O(N)$

##### Time Complexity
**Worst Case =** $O(N\log N)$
**Average Case =** $O(N\log N)$
**Best Case =** $O(N \log N)$

### **Quick Sort**
*Code from ChatGPT*
```c++
int partition(int arr[], int low, int high) {
    // partition array and return pivot index
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
```

#### **Space & Time Complexity**
Space Complexity = $O(N \log N)$

##### Time Complexity
**Worst Case =** $O(N^2)$
**Average Case =** $O(N\log N)$
**Best Case =** $O(N \log N)$

### **Heap Sort**
*Code from ChatGPT*
```c++
void heapify(int arr[], int n, int i) {
    // heapify subtree rooted at index i
}

void heapSort(int arr[], int n) {
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
```

#### **Space & Time Complexity**
Space Complexity = $O(N)$

##### Time Complexity
**Worst Case =** $O(N \log N)$
**Average Case =** $O(N\log N)$
**Best Case =** $O(N \log N)$
### Big-O Cheat Sheet
![[Pasted image 20231123224514.png]]

## Conclusion
Sorting is a fundamental part of programming, since it will always be necessary to sort arrays, lists, etc. There are multiple ways to sort them, each having its ups and downs. *Bubble Sort*, as an example, is the simplest and easiest to understand and implement. However, it is very slow and inefficient. Or like *Merge Sort*, an extremely efficient method that does not take a lot of time, yet it is very heavy in terms of space (taking twice of space than other sorting methods).

Whether one is better than the other, it really depends on *where* you're using it, *why* you're using it and *how* much both *space* and *number* of elements you're sorting. If the list is small ($< 20$ elements) *Bubble Sort* works perfectly, and *Merge Sort* is an extremely bad idea. However, if the array is of 1'000,000 elements, *Bubble Sort* or *Selection Sort* would not work, they will take a lot of time, if they even manage to complete it, and, unless you have the space for *Merge Sort*, it is not viable. 

# References
- Weiss and W. M. Allen, _Data Structures and algorithm analysis in C++_. Pearson Education India, 2007. - Información general
- U. Sahu, “Time and space complexities of sorting algorithms explained,” _Interviewkickstart.com_. [Online]. Available: https://www.interviewkickstart.com/learn/time-complexities-of-all-sorting-algorithms. [Accessed: 24-Nov-2023].
- “Bubble sort,” _Productplan.com_. [Online]. Available: https://www.productplan.com/glossary/bubble-sort/. [Accessed: 24-Nov-2023].
- S. Upadhyay, “What is Bubble Sort Algorithm? Time complexity & pseudocode,” _Simplilearn.com_, 25-Oct-2021. [Online]. Available: https://www.simplilearn.com/tutorials/data-structure-tutorial/bubble-sort-algorithm. [Accessed: 24-Nov-2023].
- “Selection sort – data structure and algorithm tutorials,” _GeeksforGeeks_, 31-Jan-2014. [Online]. Available: https://www.geeksforgeeks.org/selection-sort/. [Accessed: 24-Nov-2023].
- A. S. Ravikiran, “What is selection sort algorithm in data structures?,” _Simplilearn.com_, 19-Oct-2021. [Online]. Available: https://www.simplilearn.com/tutorials/data-structure-tutorial/selection-sort-algorithm. [Accessed: 24-Nov-2023].

## AIs
- Chat GPT
	**Input:** create an essay on the topic of "Sorting" in the programming language C++
	**Custom Instructions**
		*What would you like ChatGPT to know about you to provide better responses?*
			Knowledge in C++, specifically in Sorting. Understand the basics of an efficient code as well as the time complexity of each sorting algorithm and why one is better than another.
		*How would you like ChatGPT to respond?*
			Explain in detail each sorting algorithm, writing code in C++ of each sorting algorithm, explain the time complexity of each sorting algorithm, give examples where it is explained when to use which algorithm.
	
	*Proof of what Chat GPT said*
	![[Pasted image 20231123225140.png]]
	![[Pasted image 20231123225154.png]]
	![[Pasted image 20231123225219.png]]
	![[Pasted image 20231123225250.png]]
	![[Pasted image 20231123225303.png]]
	![[Pasted image 20231123225327.png]]
	![[Pasted image 20231123225340.png]]
	
	**New Input:** Add to the previous essay the sorting algorithms HeapSort and ShellSort
	![[Pasted image 20231123225428.png]]
	![[Pasted image 20231123225512.png]]
	![[Pasted image 20231123225548.png]]
	![[Pasted image 20231123225604.png]]

- Aria
	**Input:** create an essay on the topic of "Sorting" in the programming language C++, provide a code written in C++ for each method, explain the time complexity of each method as well as commenting each line of code
	
	*Proof of what Aria said*
	![[Pasted image 20231123230024.png]]
	![[Pasted image 20231123230106.png]]
	![[Pasted image 20231123230135.png]]
	![[Pasted image 20231123230153.png]]
	![[Pasted image 20231123230208.png]]
	
	**New Input:** add to the previous essay the time complexity, code written in C++ and comment on every line for the ordering methods Merge Sort, Quick Sort and Heap Sort
	![[Pasted image 20231123230255.png]]
	![[Pasted image 20231123230338.png]]
	![[Pasted image 20231123230400.png]]
	![[Pasted image 20231123230536.png]]
	![[Pasted image 20231123230559.png]]
	![[Pasted image 20231123230616.png]]
	![[Pasted image 20231123230630.png]]
	![[Pasted image 20231123230647.png]]
	![[Pasted image 20231123230715.png]]
	
	**New Input:** add to the previous essay the time complexity, code written in C++ and comment on every line for the ordering method Heap Sort
	![[Pasted image 20231123230752.png]]
	![[Pasted image 20231123230812.png]]
	![[Pasted image 20231123230828.png]]
	![[Pasted image 20231123230837.png]]