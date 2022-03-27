# Gaussian-Elimination

Find RREF of Matrix through Gaussian Elimination. 

Compile with:

    make
    
Run with:

    ./run_tests
    
    for filename in data/*; do  ./linear $filename; done

Precision can be changed by changing type of ELEMENT in matrix.hpp, e.g.

    typedef float ELEMENT

# References:

<https://en.wikipedia.org/wiki/Gaussian_elimination>

<https://people.math.carleton.ca/~kcheung/math/notes/MATH1107/wk04/04_gaussian_elimination.html>
