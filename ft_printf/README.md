# ft_printf

<div align="center">

![Banner](assets/banner.png)
![C Language](https://img.shields.io/badge/Language-C-000000?style=flat&logo=c)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</div>

## Grade
![Grade](assets/grade.png)

## Description

**ft_printf** is a custom implementation of the standard C function `printf`.  
It reproduces formatted output to the standard output, handling many common format specifiers such as `%d`, `%s`, `%x`, etc., without using the standard library version of `printf`.

## Features

- Variadic functions
- String parsing
- Buffer and memory management
- Formatted output
- Code modularity and testing

## Supported Conversions

The following conversion specifiers are implemented:

| Specifier | Description             |
|-----------|-------------------------|
| `%c`      | Character               |
| `%s`      | String                  |
| `%p`      | Pointer address         |
| `%d`      | Signed decimal integer  |
| `%i`      | Signed decimal integer  |
| `%u`      | Unsigned decimal integer|
| `%x`      | Lowercase hex           |
| `%X`      | Uppercase hex           |
| `%%`      | Print a literal `%`     |


## Usage
```
make
```

This will create `libftprintf.a`, a static library.

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, your score is %d/100\n", "Alice", 95);
    return 0;
}
```

Compile with your own code

```
gcc main.c -L. -lftprintf
```
