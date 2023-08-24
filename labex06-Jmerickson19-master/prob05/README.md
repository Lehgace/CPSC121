# Character Counter
Your goal is to learn how to interface with the `string` object and it's various member functions.
The program should take in 1 word, and then pass that string into two functions:

1. One that counts the vowels in that word and returns the number of vowels. `count_vowels`
1. One that counts the consonants in that word and returns the number of consonants. `count_consonants`

Within those functions you will be playing around with `string` methods.

Place the `count_vowels` and `count_consonants` function prototypes in `counter_functions.hpp`. Place their implementation in `counter_functions.cpp`. The `main` function already contains some code, but you need to complete the requirements that is described inside the file.


## The `string` Object
#### Index Operator
If we really think about it, a string is just a set of characters placed in a certain order.

So what kind of structure would represent characters next to each other perfectly?

An Array!

So using that logic we can actually access individual characters in an string. For example:
```
//Lets look at the string:
std::string s = "Hello";
```
We can actually access individual characters within that string `s`. Lets say I want to access the second character in that string, `e`.
Then to get that character is a simple as looking at the string as if it was an array.
```
H|e|l|l|o
0|1|2|3|4
```
So then to access the `e` in the string `s` all we would need to do is
```
s[1]
```
and that should give us that `e`
#### .size() and .length()
There is another string function we could use in this assignment, they are `.size()` and `.length()` both do the same thing, just with different names. But what they perform is
a very useful operation for us. They give us the length of the string. Lets reference the string object from our last example.
```
//Lets look at the string:
std::string s = "Hello";
```
To get the length of the string we can use the member functions `size()` or `length()` to get the length of our string. In this case `s.length()` will return a value of `5` The length of the word `Hello`.

### Example Output
Here is some example output:

```
Please input a single word: Fullerton
The number of vowels in this string is: 3
The number of consonants in this string is: 6
```

# Submission checklist
1. Created function prototype
1. Created function implementation
1. Called function in the driver
1. Followed the [proper file structure for using functions](https://github.com/ILXL-guides/function-file-organization)
1. Compiled and ran the driver
1. Tested the program using the sample inputs
1. No errors on the unit test (make test)
1. No errors on the style check (make stylecheck)
1. No errors on the format check (make formatcheck)

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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `counter_functions.cpp` and `main.cpp` into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 counter_functions.cpp main.cpp -o main
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
    git add .
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
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
