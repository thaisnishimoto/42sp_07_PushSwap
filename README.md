<h1 align=center>
	<b>Push_swap</b>
</h1>

<p align="center"><i>"This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions."</i></p>  
<h2>
 Status
</h2>

**Finished:**  ___ <br>
**Grade:** ___/100

<h2>
About the project - mandatory part
</h2>

The program `push_swap` gives a list of operations to sort numbers on a stack, in ascending order.
You have at your disposal 2 stacks. Stack a contains a list of numbers and stack b is empty.

## Operations allowed on the stacks

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

Algorithm

I s
