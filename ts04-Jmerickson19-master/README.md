# TuffyScheduler Milestone 4

This is milestone 4 of the [TuffyScheduler Project](https://docs.google.com/document/d/1439ruL-xNEz58-ND_3Li7nthr1om_dwXJ3zQlB42oPI/edit?usp=sharing).

# Requirements
In this milestone we will update our code so that it dynamically allocates course objects in the heap. Storing our `Course` objects in the heap gives us access to more space. Storing data in the heap also reduces the space used by our program thereby getting rid of stack overflow errors. Now that we use the heap, it is our responsibility to free up the space once we are done using it.

For this Milestone, We will reuse the `scheduler.hpp` and `scheduler.cpp` files from Milestone 3. However, we will use the `main.cpp` file from Milestone 2.

## Global functions (`scheduler.cpp` and `scheduler.cpp`)
- *display_courses*: Replace the first parameter so that it accepts an array of `Course` pointers. Update your code so that it uses the array of `Course` pointers.
- *load_schedule*: Replace the second parameter so that it accepts an array of `Course` pointers. Update your code so that it dynamically allocates a `Course` object in the heap for each course in the file. Store the pointer to the `Course` object in the heap into the array of `Course` pointers that was passed as a parameter.

## Classess
We will reuse all classes created in Milestone 3 namely `Course` and `TimeSpan`.

## main function (Driver)
Modify your *main* function from Milestone 2 to use dynamically allocated `Course` objects in the heap.

1. Replace your array of `Course` objects, with an array of pointers to `Course` objects.
1. Deallocate all `Course` objects you created in the heap right before your program exits.

Your program should behave the exact same way as it did in Milestone 2.

# Sample output
Below are samples of the program's output given different cases.

## Valid file
<pre>
Welcome to Tuffy Scheduler!
Please enter the file name containing the list of classes: <b>sched.txt</b>
Schedule file loaded. Displaying contents ...

Course name: CPSC 131
Location: EC 109
Weekly schedule: MW
Start time: 16:00
End time: 17:15

Course name: CPSC 481
Location: CS 408
Weekly schedule: MW
Start time: 16:00
End time: 17:15

Course name: CPSC 362
Location: CS 101
Weekly schedule: MW
Start time: 8:00
End time: 9:50

Thank you for using Tuffy Scheduler.
</pre>

## Start time happens after end time
<pre>
Welcome to Tuffy Scheduler!
Please enter the file name containing the list of classes: <b>sched.txt</b>
Error: The start time 17:15 should happen before the end time 16:00.
Invalid file.
Thank you for using Tuffy Scheduler.
</pre>

## Invalid weekly schedule
<pre>
Welcome to Tuffy Scheduler!
Please enter the file name containing the list of classes: <b>sched.txt</b>
Error: Invalid weekly schedule symbol MX.
Invalid file.
Thank you for using Tuffy Scheduler.
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
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/ts04-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd ts04-tuffy
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

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
