# Driving management software
You will be creating a base class `Car` and two  derived classes `GasolineCar` and `ElectricCar`. The user interface is mostly implemented for you. The focus of this exercise is to demonstrate polymorphism through virtual functions and pointers to derived classes.

## Car class
This class is almost complete so you only need to implement two functions: `drive` and `is_empty`. However, here is a rundown of the member functions you will have to use/create.

### Data members
Create a class called `Car`. It will have the following data members
1. `name_` which is an `std::string` that will be the name of the car
1. `year_` which is an `int` that will be the manufacturing year for that car
1. `speed_` which is a `double` that will be the current speed of the car

### Member functions
#### Public Methods
##### default constructor
1. `name_` should be initialized to `"Steam automobile"`.
1. `year_` should be initialized to `1769`
1. `speed_` should be initialized to `0`

##### non default constructor
The constructor initializes the following variables

For parameters it needs:
1. `std::string name` for the name of the car.
1. `double year` for year if the car.

and it initializes the member variables `name_` and `year_` with these parameters.
additionally, `speed_` gets initialized to `0`

##### accessors
Create functions that will return each of our data members.
1. `std::string name()` returns the `name_` of the car
1. `int year()` returns the `year_` of the car
1. `double speed()` returns the `speed_` of the car

##### mutators
Create functions that will modify the member variables
1. `void set_name()` sets the `name_` of the car
1. `void set_year()` sets the `year_` of the car

##### drive
Receives a single `double` parameter that sets the `speed_` of the car according to the value provided. *This should be a virtual function* that derived classes can use/override.

##### is_empty
Define this as a *virtual* function that always returns false. It will be overridden in the derived classes.

## ElectricCar class
### Data members
Create a class called `ElectricCar`

It will be a class we create that inherits from the `Car` class.
It will have one additional data member

`battery_percentage_` which is a `double` that represents the battery percentage.
### Member functions
#### Public Methods
##### non default constructor
The constructor initializes the following variables

For parameters it needs:
1. `std::string name` for the name of the car
1. `int year` for the year of the car

and it initializes the appropriate member variables with these parameters.
additionally it sets `speed_` to `0`, and sets `battery_percentage_` to `100.0`

#### default constructor
The default constructor should set `name_` to `"Electric carriage"`, `year_` to `1832`, `speed_` to `0` and `battery_percentage_` to`100.0`.

##### bool is_empty()
Returns true if `battery_percentage_` is 0.

##### drive(double speed)
This override function will perform two steps.

1. IF the battery percentage is above 0, then it should call `drive` from the `Car` object and update `battery_percentage_`. The value subtracted from the battery percentage is equal to `(speed/4)`. Specifically, `battery_percentage_ -=(speed/4)`
1. IF the remaining `battery_percentage_` after Step 1 has fallen to or below 0, then call `Car`'s drive method to set its speed to 0.

## GasolineCar class
### Data members
Create a class called `GasolineCar`
It will be a class derived from the `Car` class and has two additional data members.

1. `tank_` which is a `double` that represents the number of gallons a car's fuel tank can store.
1. `mpg_` which is a `double` that represents the miles per gallon a car can travel.

### Member functions
#### Public Methods
##### non default constructor
The constructor initializes the following variables

For parameters it needs:
1. `std::string name` for the name of the car
1. `int year` for the year of the car
1. `double tank` for the amount of fuel this car can store
1. `double mpg` for the fuel efficiency for this car.

and it initializes the appropriate member variables with these parameters.
additionally it sets `speed_` to 0.

#### default constructor
The default constructor should set `name_` to `"Gasoline car"`, `year_` to `1885`, `tank_` to `12`, `mpg_` to 24, and `speed_` to 0.

##### bool is_empty()
Returns true if `tank_` is 0.

##### void drive(double speed)
This override function will perform two steps.

1. IF the amount of fuel left in the `tank_` is above 0, then it should call `drive` from the `Car` object and update `tank_`. The value subtracted from `tank_` is equal to `(speed/mpg_)`. Specifically, `tank_ -=(speed/mpg_)`
1. IF the remaining amount in `tank_` after Step 1 has fallen to or below 0, then call `Car`'s drive method to set its speed to 0.

## Other instructions
Complete the `main` function as described. Place your classes in `car.hpp`. Member functions that take more than five lines or use complex constructs should have their function prototype in `car.hpp` and implementation in `car.cpp`.

# Sample Output 1
<pre>
Ubiquitous on-board driving management software test: - Gas/battery level sensor -
What type of car is being tested?
1 - Gasoline Car
2 - Electric Car
0 - Exit
<b>1</b>
What is the name of the car? <b>Toyota</b>
What year is the car? <b>1996</b>
How many gallons of gas can this car store? <b>13</b>
How much MPG does this car have? <b>27</b>
How fast do you want to drive this car for an hour? <b>50</b>
It took Toyota about 8 hour(s) of driving to empty the tank
</pre>
# Sample Output2
<pre>
Ubiquitous on-board driving management software test: - Gas/battery level sensor -
What type of car is being tested?
1 - Gasoline Car
2 - Electric Car
0 - Exit
<b>2</b>
What is the name of the car? <b>Tesla</b>
What year is the car? <b>2017</b>
How fast do you want to drive this car for an hour? <b>60</b>
It took Tesla about 7 hour(s) of driving to empty the battery
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `car.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

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
    git add main.cpp car.hpp car.cpp
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
