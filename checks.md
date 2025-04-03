# Minishell - Checks

## Notes, To Do and Ideas

- **Notes**:
    - To debug leaks **without** leaking functions, run:
```
valgrind --leak-check=full --show-leak-kinds=all --suppressions=valgrind.supp ./minishell
```
- **To Do**: 
    - Check every exit code of the builtins
    - Handle cd command when current path/folder is deleted (zsh: permission denied: *path*)

- **Ideas**:
    - none :(

## Mandatory check

- ✅ | Display a prompt when waiting for a new command.
- ✅ | Have a working history.
- ❌ | Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path).
- ❓ | Avoid using more than one global variable to indicate a received signal. Consider
the implications: this approach ensures that your signal handler will not access your
main data structures.
- ❌ | Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- ❌ | Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
- ❌ | Implement redirections:
    - ❌ | < should redirect input.
    - ❌ | \> should redirect output.
    - ❌ | << should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history!
    - ❌ | \>\> should redirect output in append mode
- ❌ | Implement pipes (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.
- ❌ | Handle environment variables ($ followed by a sequence of characters) which
should expand to their values.
- ❌ | Handle $? which should expand to the exit status of the most recently executed
foreground pipeline.
- ❌ | Handle ctrl-C✅, ctrl-D❌ and ctrl-\❌ which should behave like in bash.
- ❌ | In interactive mode:
    - ❌ | ctrl-C displays a new prompt on a new line.
    - ✅ | ctrl-D exits the shell.
    - ❌ | ctrl-\ does nothing.
- ✅ | Your shell must implement the following builtins:
    - ✅ | echo with option -n
    - ✅ | cd with only a relative✅ or absolute✅ path
    - ✅ | pwd with no options
    - ✅ | export with no options (export✅, export VAR_NAME✅, export VAR_NAME=value✅)
    - ✅ | unset with no options
    - ✅ | env with no options or arguments
    - ❓ | exit with no options

## Bonus checks

- ❌ | && and || with parenthesis for priorities.
- ❌ | Wildcards * should work for the current working directory.

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
| export.c | ❓ | ❓ |
| pwd.c | ✅ | ❓ |
| unset.c | ❓ | ❓ |


---

### srcs/parsing/

| File name | No leaks |
|-----------|-----------|
| parse.c | ❓ |