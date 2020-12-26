# analysis-of-algorithms-and-data-structures
 
<img src="/plots/quicksort_vs_mergesort.png"  width="800" height="425" title="quicksort-vs-mergesort">

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
<img src="/plots/mergesort.png"  width="800" height="425" title="mergesort">

## Quicksort
### Average number of comparisons
We computed *actual average number of comparisons* that our mergesort implementation does in function of all possible permutations of a random integer vector of different lengths (from 1 to 100). From vector length equals to 10 onwards we extracted uniformly random sample of permutations because all permutations are impossible to handle due to the factorial grows of permutations in function of *n*.
In order to compute *expected average number of comparisons* we used the following formula that depends on the vector length *n*:
```cpp
double formulaQuicksortComparisons(int n) {
    return 2. * (harmonic(n + 1) - 1) * (n + 1);
}
```
<img src="/plots/quicksort_comparisons.png"  width="800" height="425" title="quicksort-comparisons">

### Average number of swaps
We did the same procedure as we did for quicksort actual expected comparisons to swap operations.
In order to compute *expected average number of swaps* we used the following formula that depends on the vector length *n*:
```cpp
double formulaQuicksortSwaps(int n) {
    return 1/3. * harmonic(n + 1) * (n + 1) - 7/9. * (n + 1) + 1/2.;
}
```
<img src="/plots/quicksort_swaps.png"  width="800" height="425" title="quicksort-swaps">

## Usage
Compile and run the main source code that generate all the necessary data:
```powershell
$ compile.ps1 -Source
```
In *./src/main.py* there is the code for generate two graphs in which the results are showed.
```powershell
$ python ./src/main.py
```
If you want to compile and run all tests there is the following command that you can use:
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
