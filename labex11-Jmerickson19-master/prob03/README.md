# Super Enemy

## Enemy
Create a class called `Enemy` that will have the following:

### Data members
Create 5 data members called `xpos_`, `ypos_`, `health_`, `strength_`, and `defense_` that are all of type `int`. These will represent the enemy's attributes.

### Default Constructor
Create a default constructor that will initialize the values `0`, `0`, `5`, `3`, and `1` to the data members listed above, respectively.

### Nondefault Constructor
Create a nondefault constructor that takes five parameters to set the  xpos, ypos, health, strength, and defense data members.

### Accessors and Mutators
Create accessors and mutators for `xpos_`, `ypos_`, `health_`, `strength_`, and `defense_`.

### Other member functions
#### move_up
Create a member function called `move_up` that increments the `ypos_` variable by 1.

#### move_down
Create a member function called `move_down` that decrements the `ypos_` variable by 1.

#### move_right
Create a member function called `move_right` that increments the `xpos_` variable by 1.

#### move_left
Create a member function called `move_left` that decrements the `xpos_` variable by 1.

#### level_up
Create a member function called `level_up` that increases the `health_` by a value of `2`, and both the `strength_` and `defense_` by a value of `1`.

#### display
Create a member function called `display` that will display the class name (`"Enemy"`) and its attributes (**see below for the output format**).   

## Super enemy
Create a class called `SuperEnemy`, **which inherits from `Enemy`**, that will have the following:

### Default Constructor
Using the `Enemy` object's non-default constructor to initialize the values of `0`, `0`, `7`, `5`, and `3` to the `xpos_`, `ypos_`, `health_`, `strength_`, and `defense_` data members, respectively.

### Nondefault Constructor
Create a nondefault constructor that takes five parameters to set the  xpos, ypos, health, strength, and defense data members. It should just call the `Enemy` class' nondefault constructor.

### Other member functions

#### move_up
Override the base class's `move_up` method so that this method increases the `ypos_` variable by a value of `2`.

#### move_down
Override the base class's `move_down` method so that this method decreases the `ypos_` variable by a value of `2`.

#### move_right
Override the base class's `move_right` method so that this method increases the `xpos_` variable by a value of `2`.

#### move_left
Override the base class's `move_left` method so that this method decreases the `xpos_` variable by a value of `2`.

#### level_up
Override the base class's `level_up` method so that this method increases the health variable by a value of `5`, the strength variable by a value of `3`, and the defense variable by a value of `2`.

#### display
Override the base class's `display` method so that it displays its class name (`"Super Enemy"`) (**see below for the output format**).

## Other instructions
Complete the `main` function as described. Place your classes in `super_enemy.hpp`. Member functions that take more than five lines or use complex constructs should have their function prototype in `super_enemy.hpp` and implementation in `super_enemy.cpp`.

## Sample Output
```
Enemy
Coordinates: (0, 0)
Health: 5
Strength: 3
Defense: 1

Super Enemy
Coordinates: (0, 0)
Health: 10
Strength: 5
Defense: 2

Enemy
Coordinates: (5, 5)
Health: 7
Strength: 4
Defense: 2

Super Enemy
Coordinates: (10, 10)
Health: 15
Strength: 8
Defense: 4
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `super_enemy.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp super_enemy.cpp -o main
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
    git add main.cpp super_enemy.hpp super_enemy.cpp
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
    ```
    Alternatively, you could add a comment to the `commit` command in order to skip the *nano* editor step described below.

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
