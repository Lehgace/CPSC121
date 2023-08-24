# Add Array
Create a program that adds the contents of one array into another array using their corresponding indices. **Use pointer arithmetic throughout your program.**

### add_array
Create a function called `add_array` that takes two arrays of the same size and adds their contents then stores the result in the first array.

`add_array` will have three parameters in total:
1. an `int*` pointing to the first array
1. an `int*` pointing to the second array
1. the `size` of the arrays (we assume that the two arrays always have the same size)

The goal of the function is to add all the values from the second array into the first array according to their position in the array. For example, the value in index 0 of the second array will be added to the current value in index 0 of the first array. The sum of both values will replace the old value in index 0 of the first array.

We expect that modifying the first array inside `add_array` will also change the source array that was passed into this function as an argument because arrays point to the address of the array. Take a look at how the values in the array declared in `main` change after you call `add_array`.

### Output
All screen output (`std::cout`) should be placed in the `main` function while the array manipulation will be in the `add_array` function.

Use the 2 integer arrays of size 10 in `main` as parameters to call your `add_array` function. The function will add the values in both arrays and store the result in the first array.

Most of the code has already been created for you in `main.cpp`. You only need to fill in the missing parts. Read the instructions inside the file for more details.

Place the `add_array`'s function prototype in `add_array.hpp` and it's implementation in `add_array.cpp`.


# Sample Output
<pre>
Inputs for the first array:
Enter the integer for index 0: <b>5</b>
Enter the integer for index 1: <b>8</b>
Enter the integer for index 2: <b>2</b>
Enter the integer for index 3: <b>7</b>
Enter the integer for index 4: <b>21</b>
Enter the integer for index 5: <b>67</b>
Enter the integer for index 6: <b>12</b>
Enter the integer for index 7: <b>0</b>
Enter the integer for index 8: <b>1</b>
Enter the integer for index 9: <b>6</b>

Inputs for the second array:
Enter the integer for index 0: <b>5</b>
Enter the integer for index 1: <b>2</b>
Enter the integer for index 2: <b>7</b>
Enter the integer for index 3: <b>2</b>
Enter the integer for index 4: <b>3</b>
Enter the integer for index 5: <b>12</b>
Enter the integer for index 6: <b>7</b>
Enter the integer for index 7: <b>15</b>
Enter the integer for index 8: <b>16</b>
Enter the integer for index 9: <b>100</b>

The first array contains:
5 8 2 7 21 67 12 0 1 6

The second array contains:
5 2 7 2 3 12 7 15 16 100

Calling add_array using the first and second array ...

After calling add_array, the first array now contains:
10 10 9 9 24 79 19 15 17 106
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `add_array.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp add_array.cpp -o main
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
    git add main.cpp add_array.cpp add_array.hpp
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