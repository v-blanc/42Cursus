<div align="center">

![Banner](assets/banner.png)  
![Language](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)
![Algorithm](https://img.shields.io/badge/Radix%20Algorithm-897BFF?logo=buffer&logoColor=white)
![Solo](https://img.shields.io/badge/Group-Alone-gainsboro)
![Duration](https://img.shields.io/badge/Estimated%20Hours-60h-A65B23)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</div>

> ⚠️ **Important notice for 42 students**  
> This repository is intended as a reference and for educational purposes **only**.  
> Directly copying, submitting, or presenting this code as your own work in the 42 curriculum is a violation of the school's academic integrity policy and may result in disciplinary action.  
>  
> Feel free to read, learn, and get inspired — but always write your own code.

## 🎓 Grade
![Grade](assets/grade.png)

## 📘 Description

**push_swap** is an algorithmic project, where the goal is to sort a stack of integers using a very limited set of stack operations and with the fewest moves possible.  
You must write a program that generates a list of operations, and a checker program that verifies whether those operations correctly sort the stack.

This project teaches low-level data structures, sorting algorithms, complexity optimization, and input validation in pure C.

## 🧠 Key Concepts

- Stack-based sorting with limited operations (`sa`, `pb`, `ra`, etc.)
- Doubly or singly linked lists
- Input parsing and error handling
- Algorithm design (radix sort, insertion sort, quick sort strategies)
- Time and space complexity awareness
- Writing a checker to validate your output

## 🚀 Usage

1. Build the project:
```
make
```

2. Run the `push_swap` program:
```
./push_swap 8 67 3 87 23
```

This will output a list of instructions to sort the numbers using two stacks.

3. Test the output with the `checker_linux` (*only for linux, and provided by 42*) program:
```
./push_swap 3 2 1 | ./checker_linux 3 2 1
```

If everything is correct, it should print `OK`.  
Otherwise, it should print `KO`.

4. Clean build files:
```bash
make clean      # Removes object files  
make fclean     # Removes objects and binaries  
make re         # Rebuilds everything
```

## 🎥 Demo

First `make` the project, then:  
![Demo](assets/demo.gif)
 