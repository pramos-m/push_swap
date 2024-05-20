# Push Swap — A Journey to Find the Most Efficient Sorting Algorithm

## Introduction
**Push_swap** is an algorithm project at 42 Programming School. I achieved a full score of 125/125 and will explain my solution.

## Project Overview
Push_swap involves sorting a list of integers using two stacks (`a` and `b`) with the following operations:
- `sa`, `sb`, `ss`: Swap the first two elements of a stack.
- `pa`, `pb`: Push the top element from one stack to another.
- `ra`, `rb`, `rr`: Rotate the stack (shift elements up).
- `rra`, `rrb`, `rrr`: Reverse rotate the stack (shift elements down).

The goal is to sort all integers in stack `a` in ascending order with stack `b` empty at the end.

## The Turk Algorithm
I developed what I call the **Turk Algorithm**. Here's a step-by-step guide:

### 1. Initial Push to Stack B
- Push two numbers from `a` to `b` without checking their order.

### 2. Find the Cheapest Number
- Calculate the operations required to push each element from `a` to the correct position in `b`.
- Always push the number that requires the fewest operations.

### 3. Handle Special Cases with Stack Size Three
- If only three elements remain in `a`, sort them directly within `a` using at most two operations.

### 4. Push Back to Stack A
- Push elements back to `a` from `b`, ensuring each element is placed correctly by rotating `a` as needed.

### 5. Final Arrangement
- Ensure the smallest number is at the top of `a`.

## Detailed Steps

### Initial Setup
- Start by pushing two elements from `a` to `b`.

### Calculate the Cheapest Move
For each element in `a`, calculate:
- **Rotations** required for `a` and `b`.
- **Push** operation to move the element from `a` to `b`.

Always perform the move that requires the fewest operations.

### Sorting the Last Three Elements
When `a` contains only three elements, sort them directly within `a`.

### Final Push to Stack A
- Push elements back to `a` from `b`, ensuring correct positioning by rotating `a` before each push.

### Ensure Correct Order
- Rotate `a` so that the smallest element is on top.

## Example
### Initial State
- `a`: [4, 3, 2, 1]
- `b`: []

### Operations
1. Push two elements to `b`:

### pb
- `a`: [2, 1]
- `b`: [4, 3]

2. Calculate and push the cheapest element from `a` to `b`:
### pb
- `a`: [1]
- `b`: [4, 3, 2]

3. Sort remaining elements in `a`:

### sa
- `a`: [1]
- `b`: [4, 3, 2]

4. Push elements back to `a`, ensuring correct order:
### pa | pa | pa
- `a`: [1, 2, 3, 4]
- `b`: []

### Final State
- `a`: [1, 2, 3, 4] (sorted)
- `b`: []

## Conclusion
By following these steps, you can achieve a full score in the push_swap project. This algorithm is simple and efficient, making it an excellent choice for the project. Good luck with your sorting!

For more details, visit my [repository](#). As a 42 student, I learned a lot from the community and aim to give back by sharing my approach.
