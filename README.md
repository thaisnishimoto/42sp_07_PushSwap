<p align="center">
  <img src="https://github.com/thaisnishimoto/42-project-badges/blob/main/badges/push_swapm.png" alt="Push bonus"/>
</p>

<h1 align=center>
	<b>Push_swap</b>
</h1>

<p align="center"><i>"This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions."</i></p>  
<h2>
 Status
</h2>

**Finished:**  2023, November 17th <br>
**Grade:** 125/100

<h2>
Content
</h2>

[Mandatory Part](https://github.com/thaisnishimoto/42sp_07_PushSwap#about-the-project---mandatory-part)

[Bonus Part](https://github.com/thaisnishimoto/42sp_07_PushSwap#bonus-part---checker)

[My Tester](https://github.com/thaisnishimoto/42sp_07_PushSwap#my-tester)

<br>
<h2>
About the project - mandatory part
</h2>

The program `push_swap` gives a list of instructions to sort numbers on a stack, in ascending order. <br>
You have 2 stacks at your disposal: Stack a contains a list of numbers and stack b is empty.

### Operations allowed on the stacks

| Code  | Operation                           | Action                                                  |
| ----- | ----------------------------------- | ------------------------------------------------------- |
| `sa`  | swap a                              | swaps the first 2 elements at the top of stack a        |
| `sb`  | swap b                              | swaps the first 2 elements at the top of stack b        |
| `ss`  | swap a + swap b                     | `sa` and `sb` at the same time                          |
| `pa`  | push a                              | puts the first element of stack b at the top of stack a |
| `pb`  | push b                              | puts the first element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts up all elements of stack a by 1                  |
| `rb`  | rotate b                            | shifts up all elements of stack b by 1                  |
| `rr`  | rotate a + rotate b                 | `ra` and `rb` at the same time                          |
| `rra` | reverse rotate a                    | shifts down all elements of stack a by 1                |
| `rrb` | reverse rotate b                    | shifts down all elements of stack b by 1                |
| `rrr` | reverse rotate a + reverse rotate b | `rra` and `rrb` at the same time                        |

### Algorithm

I started out by studying about sorting algorithms and implemented a few based on:
* [Quicksort](https://github.com/thaisnishimoto/42sp_07_PushSwap/blob/master/src/extra_algos/ft_quicksort.c): Divide the stack in smaller cohorts and then find the greatest number to push back to final stack. <br>
* [Radix Sort](https://github.com/thaisnishimoto/42sp_07_PushSwap/blob/master/src/extra_algos/ft_radixsort.c): Sorts the number in the chosen base, separating by the digits (by the units, dozens, hundreds, etc.). It doesn't require comparisons and handles negative numbers <br>
* [Opt Radix Sort](https://github.com/thaisnishimoto/42sp_07_PushSwap/blob/master/src/extra_algos/ft_opt_radixsort.c): To optimize radixsort, simplify the numbers so that it ranges from 0 to N (N being the size of the list). This minimizes the number of digits and removes the need to handle negative numbers. Also, use a binary base, so that only digits == 0 have to be pushed around.

Finally, to achieve the performance necessary to score 100 on the mandatory, I based my final algorithm on the [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97). It consists on the following steps:
1. Push all numbers, but the last 3 to **stack b**.
2. Sort the remaining 3 numbers on **stack a** with a specific [hard coded algorithm](https://github.com/thaisnishimoto/42sp_07_PushSwap/blob/master/src/ft_sort_3.c) that checks for all possible combinations.
3. Calculate the amount of operations necessary to move each of the numbers on **stack b** to it's correct location on **stack a**.
4. Find the "cheapest" number to move and execute the commands to push it to it's target location.
5. Repeat step 3 and 4 until **stack b** is empty.
6. **Stack a** will be sorted, but not necessarily with the lowest number on top, so find the lowest number and shift if to the top.

### Usage example

```sh
git clone git@github.com:thaisnishimoto/42sp_07_PushSwap.git
```
```sh
make
```
```
$>./push_swap 25 -19 42 -7 0
pb
pb
ra
pa
rra
pa
ra
ra

$>ARG="25 -19 42 -7 0"; ./push_swap $ARG | wc -l
8
```

### Visualization

To illustrate how my `push_swap` handles the numbers to sort them, I used a [visualizer](https://github.com/o-reo/push_swap_visualizer) program. <br>
It checks if the list of commands is correct, and then executes them. 

![](https://github.com/thaisnishimoto/42sp_07_PushSwap/blob/master/gif/gif_push_swap.gif) _Sorting 500 numbers_

<br>
<h2>
Bonus part - Checker
</h2>

The `checker` program receives random numbers as argument and waits for instructions to sort them. <br>
When the instructions are over, press `CTRL + D` so it stops reading from the `STDIN` <br>
It will then check if the stack is sorted or not.

### Usage example

```sh
make bonus
```
```
$>./checker 3 1 2
ra
[ctrl + d]
OK

$>./checker 3 1 2
sa
[ctrl + d]
KO

$>ARG="25 -19 42 -7 0"; ./push_swap $ARG | ./checker $ARG
OK
```

<br>
<h2>
My Tester
</h2>

I wrote a script to run multiple tests on `push_swap`. <br>
It has 2 arguments:
* Amount of tests - it runs this amount of tests and shows the count of operations needed for each of them.
* Amount of numbers - it generates this amount of random numbers for each test. 
At the end, it checks if the sorting was done correctly (OK/KO) and displays the average of moves among all the tests run.

### Usage

Copy [my_test directory](https://github.com/thaisnishimoto/42sp_07_PushSwap/tree/master/my_tests) into your project's directory.
```sh
cp push_swap ./my_tests/push_swap
```
```sh
cd my_tests
```
```sh
cp push_swap ./my_tests/push_swap
```
```sh
chmod +x checker_linux push_swap
```
```sh
bash tester_push.sh [amout of tests] [amount of numbers]
```

### Example
```
$> bash tester_push.sh 10 100
--------------------------------------------------
      PUSH SWAP TESTER: Sorting 100 numbers
--------------------------------------------------

Test 1. [OK] (550 moves) 
Test 2. [OK] (603 moves) 
Test 3. [OK] (576 moves) 
Test 4. [OK] (585 moves) 
Test 5. [OK] (598 moves) 
Test 6. [OK] (570 moves) 
Test 7. [OK] (606 moves) 
Test 8. [OK] (571 moves) 
Test 9. [OK] (632 moves) 
Test 10. [OK] (637 moves) 

----Results----
OK: [10/10]
Avg moves:592
```
