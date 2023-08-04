# LeetCode #139: Word Break (Daily Challenge 08/04/2023)
This repository contains a C++ solution to the LeetCode daily challenge #139 for 08/04/2023. https://leetcode.com/problems/word-break/

This solution beats 100.00% of users in runtime (0 ms) and 71.62% of users in memory usage (8.73 MB). 

## Running
Navigate to the directory containing the extracted implementation, then simply run `make` with the included Makefile.
```
cd LeetCode-139-Word-Break-CPP
make
```

The exact commands run by `make` are as follows:

```
g++ -Wall -O0 -pipe -fno-plt -fPIC word_break.cpp -o word_break
```

There are no arguments; the test cases are hard-coded into the C++ file.

## Cleaning up
Navigate to the directory containing the extracted implementation, then simply run `make clean` with the included Makefile.

```
cd LeetCode-139-Word-Break-CPP
make clean
```

The exact commands run by make clean are as follows:

```
rm -f word_break
```