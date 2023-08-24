# Double Bubble Operator Overloading
For this exercise you need to create a `Bubble` class and construct two instances of the `Bubble` object. You will then take the two `Bubble` objects and combine them to create a new, larger combined `Bubble` object. This will be done using operator overloading.

The `Bubble` class contains one data member, `radius_`, and the corresponding accessor and mutator methods for `radius_`. Create a member function called `volume` that computes the [volume of a bubble (sphere)](https://en.wikipedia.org/wiki/Sphere#Enclosed_volume). Use the value 3.1415 for `PI`.

Create two overloaded operators in the `Bubble` class that will overload the `+` and `==` operations. The operators will combine and check the equality of two bubbles, respectively. Combining two bubbles simply means creating a new `Bubble` object whose radius is the sum of the other two `Bubble` objects' radii. Two bubbles are considered equal if the values of their radii are the same.

Your `main` function has some skeleton code that asks the user for the radius of two bubbles. You will use this to create the two `Bubble` objects as well as the third combined `Bubble` object.

Place the `Bubble` class declaration in `bubble.hpp` and the class implementation in `bubble.cpp`. The `main` function already contains some code, but you need to complete the requirements that are described inside the file.

Please see the sample output below to guide the design of your program. Note that <b>bold</b> values in the samples represent input by the user.

## Sample Input/Output
<pre>
Please enter the radius of the first bubble: <b>4.5</b>
Please enter the radius of the second bubble: <b>2.3</b>
The bubbles have now combined and created a bubble with the volume of: 1317.05
</pre>
## Sample with equally sized bubbles
<pre>
Please enter the radius of the first bubble: <b>4.3</b>
Please enter the radius of the second bubble: <b>4.3</b>
Your bubbles are the same size.
The bubbles have now combined and created a bubble with the volume of: 2664.23
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `bubble.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp bubble.cpp -o main
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
