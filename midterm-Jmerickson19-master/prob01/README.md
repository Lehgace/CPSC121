# Quarterly Sales
Create a program that reads in a quarterly sales report that contains the quarterly sales for multiple companies. Your program will sum up the quarterly sales per company, and display each company’s annual sales total.

Consider the sample input file shown below. This file contains only 2 companies, but your program needs to handle as many companies as are listed in the input file.
```
McTitan
60234.00
59823.45
78892.33
77999.93
BurgerTitan
66783.24
58999.15
79992.45
74222.34
```

The expected output for the program reading this file will be:
```
Annual Sales
McTitan: $276949.71
BurgerTitan: $279997.18
```

### Program assumptions
- The input file will always be named report.txt and will always exist
- The file’s format will always be correct. There is no need to perform error checking
- Company names will not contain any whitespace (tabs, spaces, or end lines)
- The report file will have quarterly sales information for one or more companies

# Code evaluation
Open the terminal and navigate to the folder that contains this problem. Assuming you have pulled the code inside of `/home/student/midterm` and you are currently in `/home/student` you can issue the following commands

```
cd midterm
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `main.cpp` to create the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp -o main

./main
```

# Submission
1. When everything runs correctly, let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. 

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

