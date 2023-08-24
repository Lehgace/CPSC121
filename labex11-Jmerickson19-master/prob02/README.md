# Utensil classes
This program uses three classes: `Utensil`, `Spoon`, and `Food`.

## Utensil class
Create a `Utensil` class with two data members: `double` `size_`, and `std::string` `color_`.

Create accessor and mutator functions for both data members.

Create a default constructor for `Utensil` that sets the size to `8.5` and its color to `"silver"`.

Create a constructor that receives a `double` size and `std::string` color that sets `size_` and `color_` accordingly.

Create a function `use` that receives a reference to a `Food` object, but does nothing to it (i.e., the member function's body is empty).

## Spoon class
`Spoon` inherits from `Utensil` and has an additional data member, a `double` `bite_size_`. Create an accessor and mutator function for the data member.

Create a default constructor for `Spoon` that sets the size to 6, color to silver and `bite_size_` to 25.

Create a nondefault constructor that receives a `double` size, an `std::string` color, and a `double` bite_size then assigns the values to the data member accordingly.

Create a function `use` that receives a reference to a `Food` object and removes *`bite_size_` grams* of mass from the object (i.e., eating the food). You will need to call that object's `eat` member function and provide the appropriate arguments.

## Food class
Create a `Food` class with two data members, an `std::string` `name_` and `double` `mass_` (in grams).

Create accessor and mutator functions for both data members.

Create a default constructor for `Food` that sets the name to ``"Apple Pie"`` and mass to `1000`.

Create a constructor that receives an `std::string` name and `double` mass.

Create a function `eat` that receives a `double` and subtracts it from `mass_` if there is enough left. Otherwise, set the mass to 0 (can't have a negative mass of an object).

Create a function `print` that prints the food's name and mass.

## Other instructions
Complete the `main` function as described. Place your classes in `utensils.hpp`. Member functions that take more than five lines or use complex constructs should have their function prototype in `utensils.hpp` and implementation in `utensils.cpp`.

## Sample Output:
<pre>
Please enter the name of a food item: <b>Pumpkin Pie</b>
Please enter the mass of the food item: <b>1250</b>
Please enter the size of the spoon: <b>5</b>
Please enter the color of the spoon: <b>gold</b>
Please enter your bite size using the spoon: <b>20</b>
Food before being eaten:
Pumpkin Pie 1250g
Food after spoon used:
Pumpkin Pie 1230g
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `utensils.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp utensils.cpp -o main
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
    git add main.cpp utensils.hpp utensils.cpp
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
