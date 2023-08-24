# Car Class Composition
Create a class called `Car` that will utilize other objects.

## Car

### Car data members
Create two data members that are: (1) an instance of the `Identifier` class called `identity_` and (2) an instance of the `Date` class called `release_date_`.

*NOTE*: `Identifier` and `Date` are classes that have been provided to you. You **DO NOT** need to create them.

### Default Constructor
The default constructor will be **EMPTY**, so you do not have to initialize anything. `Identifier` and `Date`'s respective constructors will initialize their default values.

### Non-Default Constructors
1. Create a non-default constructor that takes in an `Identifier` object. This will assign the parameter to the `identity_` data member.
2. Create a non-default constructor that takes in a `Date` object. This will assign the parameter to the `release_date_` data member.
3. Create a non-default constructor that takes in an `Identifier` and a `Date` object (in this order). This will assign the parameters to the `identity_` and `release_date_` parameters correspondingly.

### Accessors and Mutators
Create accessors and mutators for `identity_` and `release_date_`.

### Other Member Functions
Create a `void` member function called `print` that takes in no parameters. `print` should print the name, id, license plate, and release date of the car. The release data should follow the format **Month/Day/Year**. See the output below for your reference.

## Other instructions
Complete the `main` function as described. Place your classes in `car_comp.hpp`. Member functions that take more than five lines or use complex constructs should have their function prototype in `car_comp.hpp` and implementation in `car_comp.cpp`.

Your program does not need to account for the correct dates or license plates. For example: 13/41/1 will be acceptable for your program, even though it is not an acceptable date, and "1111111111111111" will be acceptable in your program, even though it is not a valid license plate number.

## Sample output
```
The name of the car is: Ford
The id of the car is: 1
The license plate of the car is: 123456
The release date of the car is: 1/1/1885

The name of the car is: Honda
The id of the car is: 3
The license plate of the car is: 7B319X4
The release date of the car is: 1/1/1885

The name of the car is: Ford
The id of the car is: 1
The license plate of the car is: 123456
The release date of the car is: 11/4/2018

The name of the car is: Honda
The id of the car is: 3
The license plate of the car is: 7B319X4
The release date of the car is: 11/4/2018

The name of the car is: Ford
The id of the car is: 1
The license plate of the car is: 123456
The release date of the car is: 1/1/1885
```

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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `car_comp.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp car_comp.cpp -o main
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
    git add main.cpp car_comp.hpp car_comp.cpp
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
