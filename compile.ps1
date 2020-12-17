param(
  [switch]$Source=$false,
  [switch]$Test=$false,
  [switch]$RunSource=$true,
  [switch]$RunTest=$true
)

if ($Source) {
  if ((Test-Path ./build) -eq $false) {
    mkdir ./build
    write-host
  }
  write-host "Compiling ./src/main.cpp..."

  g++.exe -std=c++17 ./src/main.cpp `
    ./src/utils.cpp `
    ./src/mergesort.cpp `
    ./src/quicksort.cpp `
    ./src/Timer.cpp `
    ./src/Data.cpp `
    -o ./build/main.exe

  write-host "Compiling ./src/main.cpp... ...done."
  if ($RunSource) {
    write-host "Running ./build/main.exe..."

    ./build/main.exe -f "hola"

    write-host "Running ./build/main.exe... ...done."
  }
  write-host
}

if ($Test) {
  if ((Test-Path ./build) -eq $false) {
    mkdir ./build
    write-host
  }

  write-host "Compiling ./tests/utilsTest.cpp..."
  g++.exe -std=c++11 ./tests/utilsTest.cpp `
    ./src/utils.cpp `
    ./src/quicksort.cpp `
    -o ./build/utilsTest.exe
  write-host "Compiling ./tests/utilsTest.cpp... ...done."
  if ($RunTest) {
    write-host "Running ./build/utilsTest.exe..."
    ./build/utilsTest.exe
    write-host "Running ./build/utilsTest.exe... ...done." 
  }
  write-host
  
  write-host "Compiling ./tests/mergesortTest.cpp..."
  g++.exe -std=c++11 ./tests/mergesortTest.cpp `
    ./src/utils.cpp `
    ./src/quicksort.cpp `
    ./src/mergesort.cpp `
    -o ./build/mergesortTest.exe
  write-host "Compiling ./tests/mergesortTest.cpp... ...done."
  if ($RunTest) {
    write-host "Running ./build/mergesortTest.exe..."
    ./build/mergesortTest.exe
    write-host "Running ./build/mergesortTest.exe... ...done."
  }
  write-host

  write-host "Compiling ./tests/quicksortTest.cpp..."
  g++.exe -std=c++11 -Wall ./tests/quicksortTest.cpp `
    ./src/utils.cpp `
    ./src/quicksort.cpp `
    -o ./build/quicksortTest.exe
  write-host "Compiling ./tests/quicksortTest.cpp... ...done."
  if ($RunTest) {
    write-host "Running ./build/quicksortTest.exe..."
    ./build/quicksortTest.exe
    write-host "Running ./build/quicksortTest.exe... ...done."
  }
  write-host
}

