# GCD calculator
Create a recursive Greatest Common Divisor (GCD) calculator function called `gcd` that receives two integer inputs. The function should return the GCD of those two numbers.

There are two methods to compute the GCD of two numbers: *Euclidean* and *Dijkstra's* algorithm. You can choose either of the two algorithms to implement your recursive `gcd` function.

## Euclidean Algorithm

The Euclidean algorithm mainly uses division and the remainder of the two numbers to find the GCD. It can be represented as a recursive algorithm such that

```
gcd(num1, num2) = num2                      if num1 == zero // base case
                = gcd(num2 % num1, num1)    if num1 > zero  // recursive case
```
You can learn more about this topic by going through these [slides](https://docs.google.com/presentation/d/11NvpHUof67flvwiDCzcMR4fMhZ2x56EOgDgrTa_dZ9M/edit?usp=sharing).

## Dijkstra's GCD algorithm

Dijkstra's algorithm mainly uses subtraction to find the GCD. It can be represented as a recursive algorithm such that

```
 gcd(num1, num2) = num2                     // if num1 and num2 are equal
                 = gcd(num1 - num2, num2)   // if num1 is greater than num2
                 = gcd(num1, num2 - num1)   // if num2 is greater than num1
```

As an example, let's say we want to find the GCD of the two numbers 72 and 56
```
gcd(72 , 56)
  72-56 , 56  Take the larger number, 72 and subtract 56 from it
  16 , 56     This is our end result, but we need to keep going. Until they are equal
gcd(16 , 56)
  16 , 56-16  Take the larger number,56 and subtract 16 from it
  16 , 40     This is our end result, but this still doesnt give us our gcd, so we keep going until both numbers are equal
gcd(16 , 40)
  16 , 40-16  Take the larger number 40 and subtract 16 from it.
  16 , 24     This is our end result, but this still doesnt give us our gcd, so we keep going until both numbers are equal
gcd(16,24)   
  16 , 24-16  Take the larger number 24 and subtract 16 from it.
  16 , 8      This is our end result, but this still doesnt give us our gcd, so we keep going until both numbers are equal
gcd(16, 8)   
  16-8, 8     Take the larger number 16 and subtract 8 from it.
  8 ,8        this is our end result, and on the next function call we will validate the equality of those two numbers there.
gcd(8,8)
  8 , 8       The two numbers are equal. THIS IS OUR GCD.
```
You can learn more about this topic by going through these [slides](https://docs.google.com/presentation/d/1EulZVpBq6cJmv_VSjzcpLW15FBCfacun6J9PMrxNRwE/edit?usp=sharing)

Place the `gcd`'s function prototype in `gcd.hpp` and its implementation in `gcd.cpp`. The `main` function already contains some code, but you need to complete the requirements that is described inside the file.

## Sample Output
<pre>
Enter the first number: <b>24</b>
Enter the second number: <b>18</b>
The GCD of the numbers 24 and 18 is 6
</pre>

# Submission checklist
1. Created function prototype and stored in `.hpp` file.
1. Created function implementation and stored in `.cpp` file (see [reference](https://github.com/ILXL-guides/function-file-organization)).
1. Call function in the driver
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readbility (`make formatcheck`).

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex02-tuffy
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `gcd.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp gcd.cpp -o main
./main
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission
1. When everything runs correctly,  let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files.

    ```
    git add main.cpp
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
    ```
    Alternatively, you could add a comment to the `commit` command in order to skip the *nano* editor step described below.

    ```
    git commit -m "Finished prob01"
    ```
1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```
    When you're done, make sure you type `git commit` again.    
1. Git will ask you to describe what you have added to the staging area. By default, you will use a command-line based editor called *nano*. Go ahead and provide a description then press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.
1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and password when you are asked.

    ```
    git push
    ```
1. When you finish the exercise, go back to Titanium and click on the `Add submission` button in the lab exercise page. Provide a short message in the text area such as "finished lab exercise" and click on `Save changes`. Finally click on `Submit assignment` to inform your instructor that you are done.
