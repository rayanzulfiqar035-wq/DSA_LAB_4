# DSA Lab 04 - Singly Linked Lists

---

## Course Information

- **Course:** Data Structures and Algorithms
- **Lab:** Lab 04
- **Topic:** Singly Linked Lists
- **Language:** C++
- **Student:** Muhammad Rayan Zulfiqar
- **CMS:** 543021
- **Section:** BSCS 15-D

---

## Lab Overview

This lab focuses on implementing a **Singly Linked List** in C++ using dynamically allocated nodes.

The lab covers the following operations:

- Creating nodes
- Traversing a linked list
- Appending nodes
- Inserting at the beginning
- Searching by value
- Counting nodes
- Accessing the second node
- Deleting nodes
- Releasing dynamically allocated memory
- Building a menu-driven linked list application

---

## Learning Objectives

After completing this lab, the following concepts are practiced:

- Implementing a singly linked list using a `struct node`
- Using a `List` class to manage linked list operations
- Working with pointers
- Dynamic memory allocation using `new`
- Releasing memory using `delete`
- Traversing linked nodes
- Searching linked lists
- Inserting nodes
- Deleting nodes safely
- Handling empty and single-node lists
- Building a menu-driven C++ program

---

## Node Structure

The linked list uses a node containing data and a pointer to the next node.

```cpp
struct node {
    int data;
    node* next;
};
```

Each node contains:

- `data` - stores the integer value
- `next` - stores the address of the next node

The last node points to `nullptr`.

---

# Tasks

---

## Task 1 - Creating and Traversing a List

In this task, three nodes are dynamically created and linked together in the order entered by the user.

### Functions Used

```cpp
createThreeNodes()
printList()
clearList()
```

### Example

```text
10 -> 20 -> 30 -> NULL
```

The program also checks the list before creating any nodes.

---

## Task 2 - Appending Nodes Using a Loop

This task introduces insertion at the end of the linked list.

The user enters the number of nodes and then enters the data for each node.

### Functions Used

```cpp
addNode(int data)
countNodes()
printList()
clearList()
```

### Example

```text
10 -> 20 -> 30 -> 40 -> 50 -> NULL

Number of Nodes: 5
```

---

## Task 3 - Searching and Accessing the Second Node

This task implements searching for a value and displaying the second node.

### Functions Used

```cpp
searchNode(int target)
printSecondNode()
```

The first node is considered to be at position `1`.

### Example

```text
10 -> 20 -> 30 -> 20 -> NULL
```

Searching for:

```text
20
```

Output:

```text
The target node is at position 2.
```

Searching for:

```text
99
```

Output:

```text
Value not found.
```

---

## Task 4 - Inserting at the Beginning

This task implements insertion at the beginning of the linked list.

### Function Used

```cpp
insertAtTheBeginning(int data)
```

### Example

Insert `20`:

```text
20 -> NULL
```

Insert `10` at the beginning:

```text
10 -> 20 -> NULL
```

Append `30`:

```text
10 -> 20 -> 30 -> NULL
```

---

## Task 5 - Deleting a Node by Value

This task implements deletion of the **first occurrence** of a given value.

### Function Used

```cpp
deleteNode(int data)
```

The following cases are handled:

- Empty list
- First node
- Middle node
- Last node
- Only node
- Duplicate values
- Missing value

### Example

Before deletion:

```text
10 -> 20 -> 20 -> 30 -> NULL
```

Delete one occurrence of `20`:

```text
10 -> 20 -> 30 -> NULL
```

---

## Task 6 - Menu-Driven Linked List Application

All previously implemented linked list operations are combined into one menu-driven program.

### Menu

```text
a. Insert at the beginning
b. Insert at the end
c. Search by value
d. Delete by value
e. Display all nodes
f. Count nodes
g. Display second node
h. Exit
```

The menu keeps running until the user selects the exit option.

---

# Functions Implemented

| Function | Description |
|---|---|
| `createThreeNodes()` | Creates and links three nodes |
| `addNode(int)` | Inserts a node at the end |
| `insertAtTheBeginning(int)` | Inserts a node at the beginning |
| `printList()` | Displays all nodes |
| `countNodes()` | Counts the total number of nodes |
| `searchNode(int)` | Searches for the first matching value |
| `printSecondNode()` | Displays the second node |
| `deleteNode(int)` | Deletes the first matching node |
| `clearList()` | Deletes all dynamically allocated nodes |

---

# File Structure

```text
DSA-Lab-04/
│
├── task1.cpp
├── task2.cpp
├── task3.cpp
├── task4.cpp
├── task5.cpp
├── task6.cpp
└── README.md
```

---

# Compilation

The programs require a C++ compiler supporting **C++11 or later**.

### Compile

```bash
g++ task1.cpp -o task1
```

### Run

```bash
./task1
```

For Task 6:

```bash
g++ task6.cpp -o task6
./task6
```

On Windows:

```bash
g++ task6.cpp -o task6.exe
task6.exe
```

---

# Time Complexity

| Operation | Time Complexity |
|---|---:|
| Insert at beginning | `O(1)` |
| Insert at end | `O(n)` |
| Search by value | `O(n)` |
| Count nodes | `O(n)` |
| Display list | `O(n)` |
| Display second node | `O(1)` |
| Delete by value | `O(n)` |
| Clear list | `O(n)` |

---

# Memory Management

Nodes are dynamically created using:

```cpp
new node(...)
```

Memory is released using:

```cpp
delete
```

Before the program exits, the linked list is cleared so that dynamically allocated memory is released properly.

---

# Linked List Structure

```text
head
 |
 v
+------+------+
|  10  |   o------+
+------+------+   |
                   v
             +------+------+
             |  20  |   o------+
             +------+------+   |
                              v
                        +------+------+
                        |  30  | NULL |
                        +-------------+
```

Each node stores the address of the next node.

Unlike an array, linked list nodes do not need to be stored in contiguous memory locations.

---

# Key Concepts

This lab demonstrates the use of:

- Singly Linked Lists
- Structures
- Classes
- Pointers
- Dynamic Memory
- `new`
- `delete`
- Traversal
- Searching
- Insertion
- Deletion
- Memory Cleanup
- Menu-Driven Programming

---

## Repository Purpose

This repository contains the implementation of **DSA Lab 04 - Singly Linked Lists**.

The purpose of this lab is to practice the implementation of linked lists and their fundamental operations in C++.
