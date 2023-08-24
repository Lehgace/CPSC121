# Cash/Debit Card
In this program, you will be implementing classes using inheritance.

## Cash Card Class
Create a `CashCard` class. This type of card has a finite balance, and overdrawing from the card will cause the transaction to fail. This class will have the following:

### Data members
1. `balance_` which is a `double` that stores the amount of money on the card.
1. `name_` which is a `std::string` that will be the owner of the card.

### Default Constructor
Create a default constructor that will set `name_` to `"Alex Amarnani"` and `balance_` to `100.00`.

### Non-Default Constructor
Create a non-default constructor that receives 2 parameters, a `double` for the balance and a `std::string` for the name respectively.

### Accessors and Mutators
Create accessors and mutators for `name_` and `balance_`.

### Member functions

#### charge_balance (Protected)
Create a **protected** member function called `charge_balance` that will pass in a `double` for the amount of money being charged to the card. This function should subtract the amount of money passed in from
the balance.

### charge
Create a **public** member function for `CashCard` called `charge` that will pass in a `double` for the amount of money being charged to the card. This function should check whether the amount is **less than
or equal to** the current balance. If there is enough balance, it should call the `charge_balance` function and pass in the amount to update the balance.
Otherwise, it should print on screen `"Insufficient funds"`.

## Debit Card Class
Create a `DebitCard` class that inherits from `CashCard`. This type of card has an infinite balance, but overdrawing from the card will result in a $30.00 overdraft fee.

This class has no additional data members.

### Default Constructor
Create a default constructor that calls its non-default constructor and pass in the values `100.00` and `"Sidney Lee"`.

### Non-Default Constructor
Create a non-default constructor that receives 2 parameters, a `double` for the balance and a `std::string` for a name respectively. Call `CashCard`'s non-default constructor and pass the 2 parameters.

### charge
Create a the `charge` member function that will pass in a `double` for the amount of  money being charged to the card. This member function will override the base class' implementation.

The function should check whether the amount is **greater** than the current balance. If it is greater than the balance, it should call the `charge_balance` function and pass in a value of `30.00` then,
display on the screen `"Overdraft Fee of $30.00 Incurred"`. It should call the `charge_balance` function again and pass in the actual amount the user spends and updates the balance accordingly.

## Other instructions
Complete the `main` function as described. Place your classes in `cash_debit_card.hpp`. Member functions that take more than five lines or use complex constructs should have their function prototype in `cash_debit_card.hpp` and implementation in `cash_debit_card.cpp`.

# Sample Output
Normal Cash Card behavior
<pre>
Enter the total price: <b>$35.00</b>
Enter your name: <b>Alex Amarnani</b>
Choose the card you will be paying with:
1 - Cash Card
2 - Debit Card
Choice: <b>1</b>
Enter the balance on your card: <b>$40.00</b>
The amount left on your card is $5.00
</pre>

Overdraw Cash Card behavior
<pre>
Enter the total price: <b>$40.00</b>
Enter your name: <b>Sidney Lee</b>
Choose the card you will be paying with:
1 - Cash Card
2 - Debit Card
Choice: <b>1</b>
Enter the balance on your card: <b>$35.00</b>
Insufficient funds
The amount left on your card is $35.00
</pre>

Normal Debit Card behavior
<pre>
Enter the total price: <b>$35.00</b>
Enter your name: <b>Charlie Rose</b>
Choose the card you will be paying with:
1 - Cash Card
2 - Debit Card
Choice: <b>2</b>
Enter the balance on your card: <b>$40.00</b>
The amount left on your card is $5.00
</pre>

Overdraw Debit Card behavior
<pre>
Enter the total price: <b>$50.00</b>
Enter your name: <b>Royal Johnson</b>
Choose the card you will be paying with:
1 - Cash Card
2 - Debit Card
Choice: <b>2</b>
Enter the balance on your card: <b>$40.00</b>
Overdraft Fee of $30.00 Incurred
The amount left on your card is $-40.00
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `cash_debit_card.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp cash_debit_card.cpp -o main
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
    git add main.cpp cash_debit_card.hpp cash_debit_card.cpp
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
