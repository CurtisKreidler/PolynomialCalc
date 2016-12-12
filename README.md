# PolynomialCalc
----
This is a bit of an abstract project. This bit of code add or multiply two txt files that have polynomials together
that are passed in through commandline arguements.

If you want to add or multipy your own polynomials the format in the txt files is:
'degree' 'coefficient'(corresponding to degree - 1) 'coefficient'(corresponding to degree - n) ... 
'coefficient'(corresponding to degree 0)

This is easier to see as an example:

(X^2) - (X) + 3 -> `3 1 -1 3` or (X^6) - (5X^3) + 4 -> `7 1 0 0 0 -5 0 0 4`


## Installation

1. Clone the repository
2. Compile with `g++ -std=c++11 -o poly poly.cc` or `g++ -std=c++11 -o mult mult.cc`
3. Run with `./poly test0.txt test1.txt` or `./mult test0.txt test1.txt`


## Future Plans

* Convert all math to `long` from `int` to do harder polynomial math
* Handle Over and underflows easier
* Expand to do more polynomial math


## Credits

Collaborators: Adam Karpowich and Mike Mizikar
