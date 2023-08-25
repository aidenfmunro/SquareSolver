# Quadratic equation solver
# Installation
Open Git Bash. Change the current directory to the location where you want the cloned directory, then type:
```
git clone https://github.com/aidenfmunro/SquareSolver
cd SquareSolver && make
```
# Usage
Now you have 2 options:
1. Run through tests. 
2. Solve a quadratic equation.
If you want to run tests then type -t:
```
a.exe -t
```
Another thing. You can change the tests.txt file. The tests file looks like this:
```
1. <number_of_tests> // 3
2. <a_b_c_numberOfRoots_x1_x2> // 1 5 6 2 -2 -3 // (x1 > x2) // 2 roots
3. <a_b_c_numberOfRoots_x1_0> // 0 1 2 1 -2 0 // 1 root
4. <a_b_c_numberOfRoots_0_0> // 1 4 9 0 0 0 // 0 roots
5. ... 
```
If you want to solve a quadratic equation type -s:
```
a.exe -s
```


