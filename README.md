# analysis-of-algorithms-and-data-structures
 
## About the project
In this project we compare actual and expected complexity of the main operations required by two well-known sorting algorithms:
* mergesort
* quicksort

Actual complexities are obtained using counters located within the implemented algorithms in which the main operations are involved and then looking at the final status of counters.  
Expected complexities are computed using formulas analytically retrieved from literature about these algorithms.  

The main operation of mergesort algorithm is comparison while for quicksort we have to distinguish between partitions, comparisons and swaps (number of partitions are always equal to the number of elments in the input so we will focus on comparisons and swaps operations only).  
We implemented both algorithms and all the utilities functions including one that creates random integer vector and another that creates all the possible permutations given an integer vector. Python programming language is used only for plotting purpose in order to show the results.

## Mergesort
We computed *actual number of comparisons* that our mergesort implementation does in function of random integer vectors of different lengths (from 1 to 100).
In order to compute *expected number of comparisons* we used the following formula that depends on the vector length *n*:
```cpp
double formulaMergesortComparisons(int n) {
    double log2n = std::log2(n);
    return 2. * n + n * floor(log2n) - pow(2, floor(log2n) + 1);
}
```
The following graph shows that the actual and the expected number of comparisons in the mergesort algorithm in function of the vector length *n* are equal for every given *n*.
<img src="/plots/mergesort.png"  width="950" height="525" title="mergesort">

## Quicksort
### Average number of comparisons
We computed *actual average number of comparisons* that our quicksort implementation does in function of all possible permutations of a random integer vector of different lengths (from 1 to 100). From vector length equals to 10 onwards we extracted uniformly random sample of permutations because all permutations are impossible to handle due to the factorial grows of permutations in function of *n*.
In order to compute *expected average number of comparisons* we used the following formula that depends on the vector length *n*:
```cpp
double formulaQuicksortComparisons(int n) {
    return 2. * (harmonic(n + 1) - 1) * (n + 1);
}
```
The following graph shows that the actual and the expected average number of comparisons in the quicksort algorithm in function of the vector length *n* are very close for every given *n*. Here the values are not identical due to the approximation of the distribution of the permutations given in input to the algorithm.
<img src="/plots/quicksort_comparisons.png"  width="950" height="525" title="quicksort-comparisons">

### Average number of swaps
We did the same procedure as we did for quicksort actual expected comparisons to swap operations.
In order to compute *expected average number of swaps* we used the following formula that depends on the vector length *n*:
```cpp
double formulaQuicksortSwaps(int n) {
    return 1/3. * harmonic(n + 1) * (n + 1) - 7/9. * (n + 1) + 1/2.;
}
```
The following graph shows that the actual and the expected average number of swaps in the quicksort algorithm in function of the vector length *n* are very close for every given *n*. Here we have the same reason as before for the approximation of the permutations extracting few of them at random uniformly.
<img src="/plots/quicksort_swaps.png"  width="950" height="525" title="quicksort-swaps">

### Quicksort vs Mergesort
<img src="/plots/quicksort_vs_mergesort.png"  width="950" height="525" title="quicksort-vs-mergesort">  
The graph above shows the *average number of comparisons* of the implemented quicksort algorithm (purple bars) against the *number of comparisons* of the implemented mergesort algorithm (green bars) in function of the vector length. For quicksort all the possible permutations are generated whenever it was possible, while for mergesort only one random vector for each vector length.

## Usage
Compile and run the main source code that generate all the necessary data:
```powershell
$ compile.ps1 -Source
```
There is the possibility to change the maximum length vector used in the experiments using two switches, *-q* and *-m* respectively for quicksort and mergesort:
```powershell
$ ./build/main.exe -q <maximum-length-vector> -m <maximum-length-vector>
```
The script *./src/main.py* produces all the graphs showed here in which there are the results:
```powershell
$ python ./src/main.py
```
Moreover it can be used as a notebook in [Visual Studio Code](https://code.visualstudio.com/).
In order to compile and run all the tests there is the following command:
```powershell
$ compile.ps1 -Test
```

## Dependencies
C++ version: 17  
Python version: 3.7

Python packages:
* matplotlib (3.2.1)
* pandas (1.1.5)
* numpy (1.18.3)

## Contact
Lorenzo Palloni - [https://lorenzopalloni.com](https://lorenzopalloni.com)  
Linkedin: [https://www.linkedin.com/in/lorenzo-palloni-758b76145/](https://www.linkedin.com/in/lorenzo-palloni-758b76145/)

