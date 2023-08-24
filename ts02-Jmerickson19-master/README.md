# TuffyScheduler Milestone 2

This is milestone 2 of the [TuffyScheduler Project](https://docs.google.com/document/d/1439ruL-xNEz58-ND_3Li7nthr1om_dwXJ3zQlB42oPI/edit?usp=sharing).

# Requirements
In this milestone we will create a **Course** class to represent a course and display its information on the screen. We will create two global functions that will *validate* the courses in a schedule file and store it in an array of **Course** objects, and *display* information from an array of **Course** objects.

## Course class
Create a course class using the following specifications.

### Data members
- std::string course_name_;
- std::string location_;
- std::string weekly_schedule_;
- int start_time_;
- int end_time_;

Take note that the start and end time will be stored as single integer values. For example, 11:30 is represented as the `int`, `1130`.

### Member functions
- *Accessors and mutators*: Take note that the unit test is strict, so kindly follow the format we use in class to create the corresponding accessors and mutators for the data members listed above. The mutators for `start_time_` and `end_time_` will take in `int` values. This means that data loaded from the schedule file should be converted to single integer values and assigned accordingly.
- *display*: Does not return values nor take any parameters. It outputs information about the **Course** class. See example below:
```
Course name: CPSC 131
Location: EC 109
Weekly schedule: MW
Start time: 16:00
End time: 17:15
```

## Global functions
- *load_schedule*: Returns a boolean value and takes three parameters - a file name (std::string), the list of courses (array of **Course** objects), and the current number of courses in the array (integer that is passed by reference).
  - The function will open the file using the provided filename parameter and validate its format. Feel free to reuse the code you constructed in Milestone 1.
  - The function should be able to detect whether the current course is valid or invalid as it loads the file. Whenever it successfully loads data for one course, it should create a **Course** object and set its values to what was loaded from the file (i.e., course name, location, weekly schedule, start time, and end time).
  - Store each **Course** object loaded successfully, in order, inside the **Course** array that was passed as a parameter. Specifically, the first **Course** object should be stored in index 0, the second object in index 1, the third in index 2, and so forth.
  - Update the value of the *size* parameter to the total number of **Courses** successfully loaded from the file.
  - If the entire file was loaded without any errors, the function should return **true**. Otherwise, the function should return **false**.
- *display_courses*: Does not return values, but takes two parameters: the list of courses (array of **Course** objects), and the current number of courses in the array (integer). This function should access each element of the **Course** array and display its information on the screen. Make use of each **Course** object's *display* function. See example below:
```
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

```

## main function (Driver)
- The function should still ask the user to provide the filename of the schedule file.
- Modify your main function to create an array of 100 **Course** objects and an integer variable to store the number of **Course** objects contained by the array.
- Call the *load_schedule* function to load the schedule file provided by the user. Use the **Course** object array and the variable to store the number of elements as arguments so that the function can store necessary information.
- Use the result of the *load_schedule* function to check whether the file was loaded successfully or not. If the file is valid, it should call the *dispaly_courses* function to display the contents of the **Course** object array. Use the corresponding variables as parameters.
- Display `"Invalid file."` whenever the schedule file provided is invalid.

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
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/ts02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd ts02-tuffy
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
