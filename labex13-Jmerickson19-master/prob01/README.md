# Array Exceptions
You will be creating a program that throws and catches exceptions. The focus of this exercise is to demonstrate exception handling, with an operator overloading treat.

## Exception class
This class has been implemented for you. It is the base class for other specific exceptions that your program will handle.

### Class members
The `Exception` class contains one data member which is a `std::string` variable to hold the exception message. It also contains an accessor and a mutator for the message.

### Constructors
The `Exception` class contains a public non-default constructor that accepts a `std::string` to set the message data member. In addition, it contains a protected default constructor so that only subclasses of this base class can instantiate an `Exception` with no message text.

## IndexOutOfRangeException class
This class has also been implemented for you. It inherits from the `Exception` class, but creates its own specific exception message.

### Constructors
The `IndexOutOfRangeException` class contains only one constructor. This constructor is a public non-default constructor that accepts two `int` parameters which represent the index and range of the array. These are used to set the exception message.

## InvalidArrayLengthException class
This class has been <b>partially</b> implemented for you. It also inherits from the `Exception` class, and creates its own specific exception message.

### Constructors
The `InvalidArrayLengthException` class should contain only one constructor. This constructor is a public non-default constructor that accepts one `int` parameter which represents the number of elements in the array. This value should be used in the exception message.

You need to create this constructor, which should set the exception message for this class. See the sample output below for the content and format of the exception message. And you can use the non-default constructor in the other exception class as a model for implementation of this constructor.

## ArrayDouble class
This class has been <b>partially</b> implemented for you. The class declaration in the hpp file is complete, but none of the functions have been implemented. Implementation of these functions should be done in the `array_double.cpp` file.

### Data members
The `ArrayDouble` class should contain the following private data members:
1. `array_` which is a pointer to a `double` and represents the array of doubles
1. `num_` which is an `int` and represents the number of elements in the array

### Constructors
The `ArrayDouble` class should contain only one constructor. This class does not contain a default constructor. The non-default constructor should be public and accept one `int` parameter which represents the number of elements in the array.

The member initialization list for this constructor should set the `array_` pointer to `nullptr` and the value of `num_` to `0`.

In the body of this constructor, it should throw an `InvalidArrayLengthException` if the value of the parameter is less than zero. Otherwise, the parameter value is valid. If this is the case then set the data member in the following way:
1. `num_` should be set to the value of the parameter.
1. `array_` should be set to a dynamically allocated array of `double` using the value of the parameter as the number of elements in the array. Make sure the value is greater than zero before allocating the array, and be sure to initialize all values in the array to zero.

### Destructor
The `ArrayDouble` class destructor should deallocate the memory that was allocated for the array.

### Member functions
The `ArrayDouble` class contains the following member functions. The function prototypes for these functions are found in the header file. You need to implement the function body for each in `array_double.cpp`.
1. double & operator[](int ix) const;
2. void display() const;

#### operator[]
The overloaded operator[] will provide an index into the array. This function receives a parameter representing an index in the array, and should throw an `IndexOutOfRangeException` if the index does not fall within the valid range for the array elements.

If the index is valid, then the function should return the value of the array at that index.

#### display()
This function displays the contents of the array, with 2 digits past the decimal for all `double` values. See the sample output below for the format of the string displayed. If the array has not yet been allocated, this function should display `Array is empty.`

## Other instructions
Complete the `main` function as described in `main.cpp`. Follow the sample output as closely as possible. Keep in mind <b>bold</b> values in the samples represent user input.

# Sample Output 1
<pre>
Please enter the number of elements for your array: <b>5</b>
Enter a value you would like to add to the array: <b>2.2</b>
Where would you like to add this number (array index 0 to 4)? <b>1</b>
Value at location 1 now contains 2.2
Array contents: 0.00 2.20 0.00 0.00 0.00
</pre>

# Sample Output 2
<pre>
Please enter the number of elements for your array: <b>0</b>
Array is empty.
</pre>

# Sample Output - invalid number of elements
<pre>
Please enter the number of elements for your array: <b>-2</b>
Invalid number of elements (-2). Value must be a positive integer.
</pre>

# Sample Output - invalid array index
<pre>
Please enter the number of elements for your array: <b>3</b>
Enter a value you would like to add to the array: <b>4.2</b>
Where would you like to add this number (array index 0 to 2)? <b>3</b>
Invalid index 3 for an array with 3 elements. Value must be between 0 and 2.
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `array_double.cpp` and `main.cpp`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cpp array_double.cpp -o main
./main
```

Alternatively, you can use the wildcard character to compile all files ending in `.cpp` from your current directory.

```
clang++ -std=c++17 *.cpp -o main
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
1. When everything runs correctly,  let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files: `git add .`

    ```
    git add main.cpp array_double.hpp array_double.cpp
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
