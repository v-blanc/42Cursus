<div align="center">

![Banner](assets/banner.png)  
![Language](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)
![Solo](https://img.shields.io/badge/Group-Alone-gainsboro)
![Duration](https://img.shields.io/badge/Estimated%20Hours-70h-A65B23)
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

**ft_printf** is a custom implementation of the standard `printf` function in C.  
It reproduces formatted output using a restricted set of tools — without calling the original `printf`.  
The project teaches formatted output, variadic functions, buffer and memory handling, and modular design.

The supported format specifiers include `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, and `%%`.

## 🧠 Key Concepts

- Variadic functions with `<stdarg.h>`
- Format string parsing
- Integer and pointer base conversions
- Character and string formatting
- Output to standard output using `write`
- Memory-safe design with no leaks

## 🚀 Usage

1. Build the library:
```
make
```

2. Compile your program with it:
```
gcc your_file.c -L. -lftprintf
```

3. Clean build files:
```bash
make clean      # Removes object files  
make fclean     # Removes objects and the library  
make re         # Rebuilds everything
```
