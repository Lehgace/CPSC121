# Soda Tracker
A soda dispenser dispenses 8 ounce cups of soda. However, the soda dispenser is not perfect, and there are times when it dispenses more than necessary.

The start of a program has been created to calculate how much extra soda the machine is dispensing. However, the programmer who built the code suddenly had to leave, and it is up to you to complete the program. The current program asks the user to provide the amount of soda dispensed, and stores the amounts in an array of *double* values.

Your job is to create a function named `excess_dispensed` that will calculate how much extra soda the machine is dispensing. 

The function `excess_dispensed` should take 2 parameters - the array of soda amounts, and the number of elements in the array. This function adds up all of the excess soda values (values in excess of 8 oz), and returns the sum of those *excess* values to the caller.

For example, given two soda amounts 9.0 and 8.3, the sum of the *excess* soda will be 1.3 (excess of 1 from 9.0 + excess of 0.3 from 8.3).

Place your function’s prototype in `soda.hpp` and its implementation in `soda.cpp`. Also take note that the constant values are placed in `soda.hpp`.

*Note: Even though the main function uses an array of five elements, your excess_dispensed function must be able to handle any number of elements in the array.*

Complete the `main()` function by passing the array of soda amounts input by the user to your function, and storing the result of your function call in a local variable. The code to display the excess amount to the screen has already been provided. The technical details are provided as comments in the main function.

**Assumptions:**
- The amount dispensed will always be at least 8 oz (no need to handle negative excess amounts)

Please see the sample below. Note that <b>bold</b> values in the sample represent input by the user.

### Sample input/output
<pre>
Please enter the soda amounts dispensed, in ounces.
Soda 1: <b>8.4</b>
Soda 2: <b>8.1</b>
Soda 3: <b>9.2</b>
Soda 4: <b>8.7</b>
Soda 5: <b>8.0</b>

Total excess soda dispensed: 2.40 ounces
</pre>

# Code evaluation
Open the terminal and navigate to the folder that contains this problem. Assuming you have pulled the code inside of `/home/student/midterm` and you are currently in `/home/student` you can issue the following commands

```
cd midterm
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 2, for example, you need to issue the following command.

```
cd prob02
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob02`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob03` for example.

```
cd ..
cd prob03
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `main.cpp` and `soda.cpp` to create the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp soda.cpp -o main

./main
```

# Submission
1. When everything runs correctly, let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. 

    ```
    git add main.cpp soda.cpp soda.hpp
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
    ```
    Alternatively, you could add a comment to the `commit` command in order to skip the *nano* editor step described below.

    ```
    git commit -m "Finished prob02"
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

