# Car Checker
You goal is to create a program that will look for a `Car` object with the lowest price.

In the main function, you will construct an array of `Car` objects with a maximum size of 3 elements. The `main` function will prompt the user for 3 sets of car information. That being: *name*, *price*, and *mileage*. After the cars have been inputted, then the program should find the car with the lowest price on the array, and display its *name*, *price*, and *mileage*.

### The Car object
The `Car` object should have 3 data members, and their corresponding accessors and mutators.
#### Data members
1. The name of the car, represented with `string`
1. The price of the car, represented with a `double`
1. The mileage of the car, represented with an `unsigned int`

#### Member functions
Provide accessors and mutators for each of the three data members.

### Lowest-priced car
Create a `lowest_price` function that accepts two parameters. First is the `Car` array, and second is the size of that `Car` array (as an `unsigned int`)

The goal of this function is to take the `Car` array and search through it to find the `Car` object with the lowest price, then it should return that `Car` object.

Write the `Car` class and the `lowest_price` function prototype in `car.hpp`. Take note that `lowest_price` is not a member function of the `Car` class. Provide the function's implementation in `car.cpp`. The `main` function already contains skeleton code for getting user input. You only need to fill in the missing code.

Please see the sample output below to guide the design of your program.

### Sample Output
<pre>
Car #1
Please enter the name: <b>2010 Nissan Rogue S Sport Utility 4D</b>
Please enter the mileage: <b>114940</b>
Please enter the price: $<b>5842.00</b>
Car #2
Please enter the name: <b>2008 Honda Civic LX Sedan 4D</b>
Please enter the mileage: <b>126041</b>
Please enter the price: $<b>5028.00</b>
Car #3
Please enter the name: <b>2015 Jeep Cherokee Sport SUV 4D</b>
Please enter the mileage: <b>70425</b>
Please enter the price: $<b>11383.00</b>

The car with the lowest price is 2008 Honda Civic LX Sedan 4D with a mileage of 126041 and a price of $5028.00
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `car.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp car.cpp -o main
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
