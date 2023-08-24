# TuffyScheduler Milestone 3

This is milestone 3 of the [TuffyScheduler Project](https://docs.google.com/document/d/1439ruL-xNEz58-ND_3Li7nthr1om_dwXJ3zQlB42oPI/edit?usp=sharing).

# Requirements
In this milestone we will create a **TimeSpan** object that we will use for our future milestones. Overload the `<` and `>` relational operators to compare **TimeSpan** objects and find possible intersections. A completed *main* function is provided for you to help test your program.

Copy your `scheduler.hpp` and `scheduler.cpp` files from Milestone 2 into this milestone. You will update them with the code you create for this milestone. The unit tests will fail if it does not see the classes and functions from Milestone 2.

However, DO NOT copy your `main.cpp` as this milestone already provides one for you.

## TimeSpan class
Create a class called **TimeSpan** that has two integer data members, *start_time_* and *end_time_*. Use military time for both such as `800` or `1830`. Create the corresponding accessors and mutators for both data members.

### <
Overload the `<` operator so that it returns a `bool` and takes in a **TimeSpan** object as a parameter. The member function returns `true` when the **TimeSpan** object's end time is less than the start time of the other **TimeSpan** object passed as a parameter.

### >
Overload the `>` operator so that it returns a `bool` and takes in a **TimeSpan** object as a parameter. The member function returns `true` when the **TimeSpan** object's start time is greater than the end time of the other **TimeSpan** object passed as a parameter.

## Global function
- *has_conflict*: Returns a boolean value and takes three parameters: a **TimeSpan** object to check for intersection, an array of **TimeSpan** objects to check against, and the size of the array. The function will return `true` when a **TimeSpan** object (first parameter) conflicts with any of the **TimeSpan** object inside the **TimeSpan** array (second parameter). There is a conflict when start and end times intersect or more specifically when a **TimeSpan** object is neither less than nor greater than another **TimeSpan** object.
  
  For example, a **TimeSpan** object whose start time is `1120` and end time is `1250` conflicts with another **TimeSpan** whose start time is `1200` and end time is `1350`. If you notice the first **TimeSpan** is not less than the second **TimeSpan** by the definition of our overloaded *<* operator. The first **TimeSpan** is not greater than the second **TimeSpan** either based on the definition of our overloaded *>* operator.

## main function (Driver)
The *main* function was created for you to test your **TimeSpan** class. Do not change code in `main.cpp` that relates to how it uses the **TimeSpan** class and calls the *has_conflict* function. For example, do not rename functions or change its arguments. The program should only compile if you design your **TimeSpan** class and *has_conflict* function correctly. 

# Sample output
<pre>Welcome to Appointment Scheduler!
Let's create your schedule. Please provide all times you are busy.
Start time (0000 - 2359): <b>830</b>
End time (0000 - 2359): <b>920</b>
Do you want to add another schedule? (Y/N): <b>y</b>
Start time (0000 - 2359): <b>930</b>
End time (0000 - 2359): <b>1120</b>
Do you want to add another schedule? (Y/N): <b>n</b>

Now let's schedule an appointment! When do you want to meet?
Start time (0000 - 2359): <b>800</b>
End time (0000 - 2359): <b>845</b>
Unfortunately, that time conflicts with an appointment. Please select another time.
Start time (0000 - 2359): <b>1110</b>
End time (0000 - 2359): <b>1300</b>
Unfortunately, that time conflicts with an appointment. Please select another time.
Start time (0000 - 2359): <b>1300</b>
End time (0000 - 2359): <b>1345</b>
That schedule works! Your appointment is set to 1300 - 1345
</pre>

# Submission checklist
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Designed and tested your own test cases.
1. Ensured no errors on the unit test (`make test`).
1. Ensured no errors on the style check (`make stylecheck`).
1. Ensured no errors on the format check (`make formatcheck`).
1. Completed reflection file ([reflection.md](reflection.md))

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/ts03-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd ts03-tuffy
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `tuffyaid.cpp` and into the executable file `tuffyaid`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp scheduler.cpp -o main
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
    
    Alternatively, you could add a comment to the `commit` command in order to s
kip the *nano* editor step described below.

    ```
    git commit -m "Finished milestone"
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
