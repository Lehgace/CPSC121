# Digicup
This program simulates interactions with a `Cup` object for getting a drink, refilling a drink, emptying a drink, and drinking from it.

## Output
All of the output statements (`std::cout`) should be in `main` and are mostly provided for you. You will only need to complete the menu functionality by calling the appropriate member functions from the `Cup` object. Your member functions are designed to only perform calculations and return values.

The `Cup` object will be used to ask the user for the type of drink they prefer and the amount they want to drink. 

The menu options are shown below for your reference:

```
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
```

## The `Cup` class
### Data members
Create a class called `Cup` with the following member variables:

1. `drink_type_` which is an `std::string` that will be the name of the drink.
1. `fluid_oz_` which is a `double` that will be the amount of fluid in the cup.

### Constructors
#### Default constructor
The default constructor should initialize `drink_type_` to `"Water"` and initialize `fluid_oz_` to `16.0`

#### Non-default constructor
The non-default constructor should take in an `std::string` parameter that will be the name of the drink type and a `double` parameter that will be the amount of drink in the cup. It should set the passed parameter values to the corresponding data members.

### Member functions
#### drink
Drinking reduces the amount of liquid in the `Cup` based on a given `amount` that is passed as a parameter. Take note that `fluid_oz_` should never be negative such that if you drink an `amount` that is greater that `fluid_oz_`, then `fluid_oz_` should be set to `0`.

##### refill
Refilling the cup increases the amount of liquid in the `Cup` based on the given parameter, `amount`. Assume the cup is bottomless.

##### new_drink
Throw out your current drink and replace it with a new drink. The function accepts two parameters. The first is the name of the new drink type and the second is the amount of the new drink type.

##### empty
*Empties out* the contents of the cup in its entirety. `fluid_oz_` should be set to 0, and `_drink_type` should be set to `"nothing"`.

##### Accessors
Create the accessors for `fluid_oz_` and `drink_type_`.

## Other information
Place the `Cup` class in `cup.hpp` and complete the code in `main.cpp`.

## Sample Output
<pre>
What kind of drink can I get you?: <b>Kool Aid</b>
How much do you want?: <b>32</b>
Your cup currently has 32 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>D</b>
How much do you want to drink from the cup?: <b>16</b>
Your cup currently has 16 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>D</b>
How much do you want to drink from the cup?: <b>6</b>
Your cup currently has 10 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>R</b>
How much do you want to refill your cup?: <b>2</b>
Your cup currently has 12 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>E</b>
Emptying your cup
Your cup currently has 0 oz. of nothing
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>N</b>
What is the new drink you want?: <b>Coke</b>
What is the amount you want?: <b>16</b>
Your cup currently has 16 oz. of Coke
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>D</b>
How much do you want to drink from the cup?: <b>8</b>
Your cup currently has 8 oz. of Coke
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>X</b>
Thank you for using Digicup!
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp -o main
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
    git add main.cpp cup.hpp
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
