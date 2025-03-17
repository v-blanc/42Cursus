# Minishell - Checks

### srcs/

| File name | No leaks |
|-----------|-----------|
| main.c | ❓ |
| utils_env.c | ✅ |

---

### srcs/builtins/

| File name | No leaks | Code errors |
|-----------|-----------|-----------|
| cd.c | ✅ | ❓ |
| echo.c | ❓ | ❓ |
| env.c | ✅ | ❓ |
| exit.c | ✅ | ❓ |
| pwd.c | ✅ | ❓ |

---

### srcs/parsing/

| File name | No leaks |
|-----------|-----------|
| parse.c | ❓ |