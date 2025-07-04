<div align="center">

![Banner](assets/banner.png)  
![Language](https://img.shields.io/badge/Language-C-000000?style=flat&logo=c)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</div>

## 🎓 Grade
![Grade](assets/grade.png)

## 📘 Description

**get_next_line** is a project with the goal of implementing a function that reads from a file descriptor and returns the next line, one call at a time — handling multiple file descriptors and partial reads, with efficient memory management and buffer control.

It reinforces knowledge of file I/O, static variables, string manipulation, and dynamic memory allocation.

## 🧠 Key Concepts

- File descriptor manipulation (`read`)
- Static variables and persistent state
- Dynamic string allocation and joining
- Buffer management with fixed-size reads
- Memory safety and error handling
- Handling edge cases (e.g., EOF without newline)

## 🚀 Usage

1. Compile the project:
```
make
```

2. Use it in your program:

```
gcc main.c get_next_line.c get_next_line_utils.c -I -D BUFFER_SIZE=42
```

3. Clean build files:
```bash
make clean      # Removes object files  
make fclean     # Removes object files and binaries  
make re         # Rebuilds everything
```

