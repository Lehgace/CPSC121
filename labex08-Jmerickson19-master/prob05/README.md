# Print Array Reverse
Create a program that displays the contents of an array in reverse.

### print_array_reverse
Create a function called `print_array_reverse` that prints out the contents of an integer array in reverse.

Within this function you are only allowed to use pointer arithmetic to access elements of the array.

You are not allowed to use the `[]` operator to complete this question.

`print_array_reverse` will have two parameters in total:
1. an `int*` pointer that refers to an array
1. an `int` that stores the number of elements in the array

Your function has two main scenarios it could encounter.

When you have an array with a size that is greater than 0, then it should behave normally and output the array's contents in reverse.

But, if your function encounters an array with size of 0 or negative, then it should output `There are no contents in this array!` and go to the next line.

Refer to the sample output to see instances of both.

Complete the code in `main.cpp`, provide the headers in `print_array_reverse.hpp` and the implementation in `print_array_reverse.cpp`.

# Sample Output
<pre>
Enter an integer for the size of the array(Must be less than or equal to 10): <b>10</b>
Inputs for the array:
Enter the integer for index 0: <b>4</b>
Enter the integer for index 1: <b>3</b>
Enter the integer for index 2: <b>2</b>
Enter the integer for index 3: <b>1</b>
Enter the integer for index 4: <b>89</b>
Enter the integer for index 5: <b>15</b>
Enter the integer for index 6: <b>100</b>
Enter the integer for index 7: <b>24</b>
Enter the integer for index 8: <b>254</b>
Enter the integer for index 9: <b>2</b>
The contents of the array in reverse are:
2 254 24 100 15 89 1 2 3 4
</pre>

<pre>
Enter an integer for the size of the array(Must be less than or equal to 10): <b>0</b>
Inputs for the array:
There are no contents in this array!
</pre>

Submission checklist
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `print_array_reverse.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp print_array_reverse.cpp -o main
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
    git add main.cpp print_array_reverse.cpp print_array_reverse.hpp
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
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