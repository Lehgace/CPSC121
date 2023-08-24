# Class Average
Create a program that dynamically creates an array whose size depends on the user's preference. Pass the array to a `calculate_avg` function that is responsible for computing the average GPA of the given array. **Use pointer arithmetic throughout your program.**

### calculate_avg
Create a function called `calculate_avg` that calculates the average of a `double` array and returns that average.

`calculate_avg()` will have two parameters:
1. a `double*` referring to the array
1. an `int` that contains the size of the given array.

When the array is size is greater than 0, the function should calculate the average GPA from the given array of grades.

However, when the size of the array is 0, then the function should return 0.

### main
The `main` function has mostly been built for you. It is your task to dynamically create a `double` array, store users' grades into the array, and pass the array to `calculate_avg` to compute and then display the students' average GPA. Read the instructions in `main.cpp` for more details.

If the user happens to provide a class size of `0`, then the program should output `"You have no class!"` and then end the execution of the program without attempting to calculate the average.

Do not forget to deallocate memory that your code dynamically created.

Place the `calculate_avg`'s function prototype in `calculate_avg.hpp` and it's implementation in `calculate_avg.cpp`.

# Sample Output
<pre>
How many students are in your class? <b>5</b>
Enter the GPA for the students in your class (0.0 - 4.0)
Enter the GPA for student #1: <b>3.8</b>
Enter the GPA for student #2: <b>2.5</b>
Enter the GPA for student #3: <b>4.0</b>
Enter the GPA for student #4: <b>1.9</b>
Enter the GPA for student #5: <b>3.6</b>
Class average: 3.16
</pre>

<pre>
How many students are in your class? <b>0</b>
You have no class!
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `calculate_avg.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp calculate_avg.cpp -o main
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
    git add main.cpp calculate_avg.cpp calculate_avg.hpp
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