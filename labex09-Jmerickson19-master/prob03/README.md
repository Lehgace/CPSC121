# Player
Create a `Player` class with the following data members to represent a game character: `xpos_` that is an `int` representing their x position, `ypos_` that is an `int` representing their y position, `name_` that is a `std::string` representing the player's name, and `health_`, `strength_`, and `defense_` which are all of type `int` representing the character's attributes.

### Default Constructor
Create a default constructor that initializes the following values to your data members:
`0` for the x position, `0` for the y position, `Ash` for the name, `10` for the health, `5` for the strength and `2` for the defense.

### Non-Default Constructor
Create a non-default constructor that takes in 6 values: the name, the health, the strength, the defense, the x position, and the y position respectively. These should be used to initialize the corresponding data members.

### Accessors & Mutators
Create accessors and mutators for all data members

### Member functions

#### display_stat
Create a member function called `display_stat` that takes in no parameters and does not return anything. This member function should display the name of the player, the player's health, the player's strength, the player's defense, and the player's coordinates (x and y position). Look at the output provided below for an example.

#### player_move
Create a member function called `player_move` that takes in no parameters and does not return anything. This member function should increment the x position and the y position by a value of 1.

#### is_player_dead
Create a member function called `is_player_dead` that takes in no parameters and returns a `bool` value. This member function should check the player's health. If the player's health is equal to 0, then return `true`, otherwise return `false`.

#### take_damage
Create a member function called `take_damage` that takes in an `int` value for the damage taken and returns nothing. This member function should display a statement saying that the player took damage, and decrease the player's health based on the damage taken.

If the damage taken is greater than the player's current health, set the player's health to 0 (the player cannot have negative health). This member function should  call the `is_player_dead` function to check whether the player survives the attack. If the player is dead, display a statement saying that the player is dead. Look at the output provided below for an example.

## Other instructions
Place the `Player` class inside `player.hpp`. Member functions that take more than five lines or use complex constructs should have their function prototype in `list.hpp` and implementatiion in `list.cpp`.

The `main` function is already provided for you. Do not edit the `main.cpp` file.

## Sample output
```
Player: Ash
Health: 10
Strength: 5
Defense: 2
At position: (10, 10)

Player: Les
Health: 20
Strength: 10
Defense: 6
At position: (0, 0)

Ash took 25 damage
Ash is dead

Player: Ash
Health: 0
Strength: 5
Defense: 2
At position: (10, 10)
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `player.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp player.cpp -o main
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
    git add main.cpp player.hpp player.cpp
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
