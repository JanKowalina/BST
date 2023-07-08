# Binary Search Tree (BST) Implementation

This program implements a binary search tree (BST) data structure. Each element in the tree is associated with a key (unsigned integer). The program supports the following operations:

- `+`: Add a new element with a given key to the tree.
- `-`: Remove an element with a given key from the tree (ignores the operation if the element is not found).
- `?`: Search the tree for an element with a given key. Prints '1' if the element is found, or '0' if not.
- `m`: Print the key of the minimum element in the tree.
- `M`: Print the key of the maximum element in the tree.
- `q`: Quit the program.

## Input

The program accepts any number of lines, with each line containing one of the following commands:

- `+ <key>`: Add an element with the specified key to the tree.
- `- <key>`: Remove an element with the specified key from the tree.
- `? <key>`: Search the tree for an element with the specified key.
- `m`: Get the minimum element key in the tree.
- `M`: Get the maximum element key in the tree.
- `q`: End the program.

Please note that `q` should always be the last operation.

## Output

The program produces the following output:

- For `m` and `M` operations: the key of the minimum or maximum element in the tree, respectively.
- For `?` operations: a single value of 0 or 1 indicating whether the element was found or not.

## Example

Input:
```
+ 10
+ 20
+ 30
m
M
? 20
- 20
? 20
q
```

Output:
```
10
30
1
0
```

This example demonstrates the addition of elements with keys 10, 20, and 30 to the tree. The minimum key is 10, and the maximum key is 30. The program then searches for the element with key 20, which is found and returns 1. The element with key 20 is then removed from the tree. After removal, the program searches for the element with key 20 again, but it is not found and returns 0. Finally, the program terminates.


## Compilation and Execution

To compile the program, follow these steps:

1. Use a C++ compiler (such as g++) to compile the code:

   ```shell
   g++ -o BST BST.cpp
   ```

2. Run the program using the following command:

   ```shell
   ./BST
   ```

   The program will start running and wait for user input.