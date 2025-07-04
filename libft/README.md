# Libft

<div align="center">

![Banner](assets/banner.png)
![C Language](https://img.shields.io/badge/Language-C-000000?style=flat&logo=c)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</div>

## Grade

![Grade](assets/grade.png)

## Description

Libft is a foundational project that consists of rebuilding key functions from the C standard library, along with additional utilities for memory manipulation, string processing, character checks, linked lists, and more.

This project helps reinforce a deep understanding of memory, pointers, buffer management, and data structures in C — all implemented **from scratch**, without relying on any external functions (except `write`, `malloc`, and `free`).

## Features

- Custom implementations of standard C library functions:
  - `strlen`, `strcpy`, `strdup`, `atoi`, `memset`, `bzero`, etc.
- Memory and string manipulation tools
- Character classification and conversion functions (like `isalpha`, `toupper`)
- Singly linked list utilities:
  - `ft_lstnew`, `ft_lstadd_front`, `ft_lstdelone`, `ft_lstmap`, etc.
- Full modularity and strict coding standards (42 Norme)

## Usage

### Clone and build the library:

    git clone https://github.com/v-blanc/libft.git
    cd libft
    make

### Compile with your own project:

To use `libft.a` in another project:

    gcc main.c -L. -lft

### Clean build files:

    make clean      # remove object files
    make fclean     # remove object files + libft.a
    make re         # rebuild everything

## Example

```c
#include "libft.h"

int main(void)
{
    const char *str = "Hello, World!";
    char *copy = ft_strdup(str);
    free(copy);
    return 0;
}
```