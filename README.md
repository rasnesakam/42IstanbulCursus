# PUSH SWAP
Push swap is one of the most challenging projects in 42 cursus.
Project aims that sorting the stack data structure with another stack data structure
using some of push-swap verbs

## Verbs are
| Verb | Description |
| :--: | :---------: |
| sa   | Swap first two elements of **stack a** |
| sb   | Swap first two elements of **stack b** |
| ss   | Swap first two elements of **both stacks** |
| pa   | Take first element of **b stack**, <br /> and push it to **a stack** if element exists <br /> Or, do nothing |
| pb   | Take first element of **a stack**, <br /> and push it to **b stack** if element exists <br /> Or, do nothing |
| ra   | Shift up all elements of **stack a by 1** |
| rb   | Shift up all elements of **stack b by 1** |
| rr   | Shift up all elements of **both stacks by 1** |
| rra  | Shift down all elements of **stack a** |
| rrb  | Shift down all elements of **stack b** |
| rrr  | Shift down all elements of **both stacks** |

## Algorithm

### Push and swap
This methods uses only push and swap verbs of this project.  
The methodology of this algorithm is, collecting minimum and maximum numbers on the top of the both stacks

1. Pop the top of the **a stack**, store it on the **temp** and push it to top of the **b stack**
2. If variable for the top of the **b stack** (**top**) is not defined, assign it to **temp** value
3. If **top** is defined, compare it with **temp**
4. If **temp** is greater than **top**, swap first two elements of **b stack** and assign **top** to **temp**
5. If **a stack** is empty, do similar things on the stack a, But swap elements if **temp** is less than **top**
6. Check order of **a stack** if not ordered correctly, go to 1.

#### Pseudo code
```
This program sorts the datas of the stack using another stack and some of verbs

DEFINE temp
DEFINE top

WHILE NOT isOrdered (stack_a)
	
	WHILE NOT empty (stack_a)
		
		temp = pop (stack_a)
		push (stack_b, temp)
		IF temp < top AND size (stack_b) > 2
			swap (stack_b)
		ELSE
			top = temp

	WHILE NOT empty (stack_b) 
		temp = pop (stack_b)
		push (stack_a, temp)
		IF temp > top AND size (stack_b) > 2
			swap (stack_b)
		ELSE
			top = temp
		

```