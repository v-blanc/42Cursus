# get_next_line

<div align="center">

![Banner](assets/banner.png)
![C Language](https://img.shields.io/badge/Language-C-000000?style=flat&logo=c)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</div>

## Grade
![Grade](assets/grade.png)

## Description

**get_next_line** is a C function that reads a file or input stream line by line, returning one line per call.  
This project focuses on low-level file reading, buffer management, and memory handling.

The challenge is to handle edge cases such as very long lines, multiple file descriptors, and minimal system calls — all while managing memory and respecting the norm (coding standard).

## Prototype

```c
char *get_next_line(int fd);
```

- fd: file descriptor to read from
- Returns:
    - A null-terminated string ending with a \n (if there is one),
    - Or NULL when there's nothing left to read or on error.

## Features

- Read one line at a time, even with very large files
- Efficient buffer management
- Handles lines with or without \n
- No memory leaks

## Build

```
make
```

This will create get_next_line.o and optionally a.out if you compile with your own main.c.

### Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

### Customization
You can define BUFFER_SIZE at compile time:

```
gcc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

Or set it inside the header file as a #define.
