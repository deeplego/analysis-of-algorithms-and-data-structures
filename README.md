# analysis-of-algorithms-and-data-structures
## About the project
In this project we compare actual and expected complexity of the main operations required by two well-known sorting algorithms:
* mergesort
* quicksort

For mergesort the main operation is comparison, while for quicksort we have to distinguish between partitions, comparisons and swaps. The implementation of both algorithms is done in C++ and Python is used only for showing the results.

## Usage
Compile and run the main source code that generate all the necessary data:
```powershell
$compile.ps1 -Source
```
In *./src/main.py* there is the code for generate two graphs in which the results are showed.
```powershell
python ./src/main.py
```
If you want to compile and run all tests there is the following command that you can use:
```powershell
$compile.ps1 -Test
```

## Dependencies
C++ tested version: 17  
Python tested version: 3.7

Python packages:
* matplotlib==3.2.1
* pandas==1.1.5
* numpy==1.18.3

## Contact
Lorenzo Palloni - [https://lorenzopalloni.com](https://lorenzopalloni.com)  
Linkedin: [https://www.linkedin.com/in/lorenzo-palloni-758b76145/](https://www.linkedin.com/in/lorenzo-palloni-758b76145/)
