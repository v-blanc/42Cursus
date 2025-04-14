# Minishell - Fonctions externes

## Sommaire

- [1 - Gestion de l'entrée utilisateur ✅](#gestion-de-lentrée-utilisateur)
  - [1.1 - readline ✅](#readline)
  - [1.2 - rl_clear_history ✅](#rl_clear_history)
  - [1.3 - rl_on_new_line ✅](#rl_on_new_line)
  - [1.4 - rl_replace_line ✅](#rl_replace_line)
  - [1.5 - rl_redisplay ✅](#rl_redisplay)
  - [1.6 - add_history ✅](#add_history)
- [2 - Gestion des processus](#gestion-des-processus)
  - [2.1 - fork](#fork)
  - [2.2 - wait](#wait)
  - [2.3 - waitpid](#waitpid)
  - [2.4 - wait3](#wait3)
  - [2.5 - wait4](#wait4)
  - [2.6 - execve](#execve)
- [3 - Gestion des fichiers](#gestion-des-fichiers)
  - [3.1 - open](#open)
  - [3.2 - read](#read)
  - [3.3 - write](#write)
  - [3.4 - close](#close)
  - [3.5 - unlink](#unlink)
  - [3.6 - stat](#stat)
  - [3.7 - lstat](#lstat)
  - [3.8 - fstat](#fstat)
- [4 - Gestion des répertoires](#gestion-des-répertoires)
  - [4.1 - opendir](#opendir)
  - [4.2 - readdir](#readdir)
  - [4.3 - closedir](#closedir)
- [5 - Gestion des signaux](#gestion-des-signaux)
  - [5.1 - signal](#signal)
  - [5.2 - sigaction](#sigaction)
  - [5.3 - sigemptyset](#sigemptyset)
  - [5.4 - sigaddset](#sigaddset)
  - [5.5 - kill](#kill)
- [6 - Gestion de la mémoire ✅](#gestion-de-la-mémoire)
  - [6.1 - malloc ✅](#malloc)
  - [6.2 - free ✅](#free)
- [7 - Gestion des erreurs ✅](#gestion-des-erreurs)
  - [7.1 - strerror ✅](#strerror)
  - [7.2 - perror ✅](#perror)
- [8 - Gestion des terminaux](#gestion-des-terminaux)
  - [8.1 - isatty](#isatty)
  - [8.2 - ttyname](#ttyname)
  - [8.3 - ttyslot](#ttyslot)
  - [8.4 - ioctl](#ioctl)
  - [8.5 - tcsetattr](#tcsetattr)
  - [8.6 - tcgetattr](#tcgetattr)
- [9 - Gestion de l'environnement ✅](#gestion-de-lenvironnement)
  - [9.1 - getenv ✅](#getenv)
- [10 - Gestion des tubes (pipes)](#gestion-des-tubes-pipes)
  - [10.1 - pipe](#pipe)
  - [10.2 - dup](#dup)
  - [10.3 - dup2](#dup2)
- [11 - Gestion des informations système ✅](#gestion-des-informations-système)
  - [11.1 - getcwd ✅](#getcwd)
  - [11.2 - chdir ✅](#chdir)
- [12 - Gestion de la base de données terminfo](#gestion-de-la-base-de-données-terminfo)
  - [12.1 - tgetent](#tgetent)
  - [12.2 - tgetflag](#tgetflag)
  - [12.3 - tgetnum](#tgetnum)
  - [12.4 - tgetstr](#tgetstr)
  - [12.5 - tgoto](#tgoto)
  - [12.6 - tputs](#tputs)
- [13 - Fonctions diverses ✅](#fonctions-diverses)
  - [13.1 - printf ✅](#printf)
  - [13.2 - exit ✅](#exit)
  - [13.3 - access ✅](#access)

## Bibliothèques

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>
#include <termios.h>
#include <errno.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
```

## Fonctions

### Gestion de l'entrée utilisateur

#### `readline`

**Description** : Lit une ligne de texte depuis l'entrée standard.

**Bibliothèque** : `#include <readline/readline.h>`

**Prototypage** : `char *readline(const char *prompt);`

**Paramètres** :
- `const char *prompt` - Le prompt à afficher.

**Valeur de retour** :
- `char *` - La ligne lue, ou `NULL` en cas d'erreur.

**Exemple** :
```c
char *input = readline("Entrez votre nom : ");
if (input) {
    printf("Vous avez entré : %s\n", input);
    free(input);
}
```

#### `rl_clear_history`

**Description** : Efface l'historique de `readline`.

**Bibliothèque** : `#include <readline/history.h>`

**Prototypage** : `void rl_clear_history(void);`

**Paramètres** : Aucun.

**Valeur de retour** : Aucune.

**Exemple** :
```c
rl_clear_history();
```

#### `rl_on_new_line`

**Description** : Déplace le curseur à la ligne suivante.

**Bibliothèque** : `#include <readline/readline.h>`

**Prototypage** : `void rl_on_new_line(void);`

**Paramètres** : Aucun.

**Valeur de retour** : Aucune.

**Exemple** :
```c
rl_on_new_line();
```

#### `rl_replace_line`

**Description** : Remplace la ligne courante par une nouvelle ligne.

**Bibliothèque** : `#include <readline/readline.h>`

**Prototypage** : `void rl_replace_line(const char *text, int zero);`

**Paramètres** :
- `const char *text` - Le texte de remplacement.
- `int zero` - Si différent de zéro, met à jour le point de départ.

**Valeur de retour** : Aucune.

**Exemple** :
```c
rl_replace_line("Nouvelle ligne", 1);
```

#### `rl_redisplay`

**Description** : Réaffiche la ligne courante.

**Bibliothèque** : `#include <readline/readline.h>`

**Prototypage** : `void rl_redisplay(void);`

**Paramètres** : Aucun.

**Valeur de retour** : Aucune.

**Exemple** :
```c
rl_redisplay();
```

#### `add_history`

**Description** : Ajoute une ligne à l'historique de `readline`.

**Bibliothèque** : `#include <readline/history.h>`

**Prototypage** : `void add_history(const char *line);`

**Paramètres** :
- `const char *line` - La ligne à ajouter.

**Valeur de retour** : Aucune.

**Exemple** :
```c
add_history("Commande ajoutée à l'historique");
```

### Gestion des processus

#### `fork`

**Description** : Crée un nouveau processus.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `pid_t fork(void);`

**Paramètres** : Aucun.

**Valeur de retour** :
- `pid_t` - `0` dans le processus enfant, l'ID du processus enfant dans le processus parent, ou `-1` en cas d'erreur.

**Exemple** :
```c
pid_t pid = fork();
if (pid == 0) {
    // Code du processus enfant
    printf("Je suis l'enfant.\n");
} else if (pid > 0) {
    // Code du processus parent
    printf("Je suis le parent.\n");
} else {
    // Erreur
    perror("fork");
}
```

#### `wait`

**Description** : Attend la fin d'un processus enfant.

**Bibliothèque** : `#include <sys/wait.h>`

**Prototypage** : `pid_t wait(int *status);`

**Paramètres** :
- `int *status` - Le statut de sortie du processus enfant.

**Valeur de retour** :
- `pid_t` - L'ID du processus enfant terminé, ou `-1` en cas d'erreur.

**Exemple** :
```c
int status;
wait(&status);
if (WIFEXITED(status)) {
    printf("Enfant terminé avec le code %d\n", WEXITSTATUS(status));
}
```

#### `waitpid`

**Description** : Attend la fin d'un processus enfant spécifique.

**Bibliothèque** : `#include <sys/wait.h>`

**Prototypage** : `pid_t waitpid(pid_t pid, int *status, int options);`

**Paramètres** :
- `pid_t pid` - L'ID du processus enfant.
- `int *status` - Le statut de sortie.
- `int options` - Les options (ex. `WNOHANG`).

**Valeur de retour** :
- `pid_t` - L'ID du processus enfant terminé, ou `-1` en cas d'erreur.

**Exemple** :
```c
waitpid(pid, &status, 0);
```

#### `wait3`

**Description** : Attend la fin d'un processus enfant et obtient des informations sur l'utilisation des ressources.

**Bibliothèque** : `#include <sys/wait.h>`

**Prototypage** : `pid_t wait3(int *status, int options, struct rusage *rusage);`

**Paramètres** :
- `int *status` - Le statut de sortie.
- `int options` - Les options.
- `struct rusage *rusage` - Les informations sur l'utilisation des ressources.

**Valeur de retour** :
- `pid_t` - L'ID du processus enfant terminé, ou `-1` en cas d'erreur.

**Exemple** :
```c
struct rusage ru;
wait3(&status, 0, &ru);
```

#### `wait4`

**Description** : Attend la fin d'un processus enfant spécifique et obtient des informations sur l'utilisation des ressources.

**Bibliothèque** : `#include <sys/wait.h>`

**Prototypage** : `pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);`

**Paramètres** :
- `pid_t pid` - L'ID du processus enfant.
- `int *status` - Le statut de sortie.
- `int options` - Les options.
- `struct rusage *rusage` - Les informations sur l'utilisation des ressources.

**Valeur de retour** :
- `pid_t` - L'ID du processus enfant terminé, ou `-1` en cas d'erreur.

**Exemple** :
```c
wait4(pid, &status, 0, &ru);
```

#### `execve`

**Description** : Exécute un programme.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `int execve(const char *pathname, char *const argv[], char *const envp[]);`

**Paramètres** :
- `const char *pathname` - Le chemin du programme.
- `char *const argv[]` - Les arguments.
- `char *const envp[]` - L'environnement.

**Valeur de retour** :
- `int` - Ne retourne pas en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
char *args[] = {"/bin/ls", NULL};
char *env[] = {NULL};
execve("/bin/ls", args, env);
```

### Gestion des fichiers

#### `open`

**Description** : Ouvre un fichier.

**Bibliothèque** : `#include <fcntl.h>`

**Prototypage** : `int open(const char *pathname, int flags, ...);`

**Paramètres** :
- `const char *pathname` - Le chemin du fichier.
- `int flags` - Les options d'ouverture (ex. `O_RDONLY`).
- `mode_t mode` - Les permissions (pour la création).

**Valeur de retour** :
- `int` - Le descripteur de fichier, ou `-1` en cas d'erreur.

**Exemple** :
```c
int fd = open("fichier.txt", O_RDONLY);
if (fd != -1) {
    close(fd);
}
```

#### `read`

**Description** : Lit des données depuis un fichier.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `ssize_t read(int fd, void *buf, size_t count);`

**Paramètres** :
- `int fd` - Le descripteur de fichier.
- `void *buf` - Le buffer de lecture.
- `size_t count` - Le nombre d'octets à lire.

**Valeur de retour** :
- `ssize_t` - Le nombre d'octets lus, ou `-1` en cas d'erreur.

**Exemple** :
```c
char buffer[100];
ssize_t n = read(fd, buffer, sizeof(buffer));
if (n > 0) {
    buffer[n] = '\0';
    printf("Lu : %s\n", buffer);
}
```

#### `write`

**Description** : Écrit des données dans un fichier.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `ssize_t write(int fd, const void *buf, size_t count);`

**Paramètres** :
- `int fd` - Le descripteur de fichier.
- `const void *buf` - Le buffer à écrire.
- `size_t count` - Le nombre d'octets à écrire.

**Valeur de retour** :
- `ssize_t` - Le nombre d'octets écrits, ou `-1` en cas d'erreur.

**Exemple** :
```c
const char *message = "Bonjour\n";
write(STDOUT_FILENO, message, strlen(message));
```

#### `close`

**Description** : Ferme un fichier.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `int close(int fd);`

**Paramètres** :
- `int fd` - Le descripteur de fichier.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
close(fd);
```

#### `unlink`

**Description** : Supprime un fichier.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `int unlink(const char *pathname);`

**Paramètres** :
- `const char *pathname` - Le chemin du fichier.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
if (unlink("fichier.txt") == 0) {
    printf("Fichier supprimé.\n");
}
```

#### `stat`

**Description** : Obtient des informations sur un fichier.

**Bibliothèque** : `#include <sys/stat.h>`

**Prototypage** : `int stat(const char *pathname, struct stat *statbuf);`

**Paramètres** :
- `const char *pathname` - Le chemin du fichier.
- `struct stat *statbuf` - La structure pour stocker les informations.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
struct stat sb;
if (stat("fichier.txt", &sb) == 0) {
    printf("Taille du fichier : %ld octets\n", sb.st_size);
}
```

#### `lstat`

**Description** : Obtient des informations sur un fichier ou un lien symbolique.

**Bibliothèque** : `#include <sys/stat.h>`

**Prototypage** : `int lstat(const char *pathname, struct stat *statbuf);`

**Paramètres** :
- `const char *pathname` - Le chemin du fichier.
- `struct stat *statbuf` - La structure pour stocker les informations.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
lstat("lien.sym", &sb);
```

#### `fstat`

**Description** : Obtient des informations sur un fichier ouvert.

**Bibliothèque** : `#include <sys/stat.h>`

**Prototypage** : `int fstat(int fd, struct stat *statbuf);`

**Paramètres** :
- `int fd` - Le descripteur de fichier.
- `struct stat *statbuf` - La structure pour stocker les informations.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
fstat(fd, &sb);
```

### Gestion des répertoires

#### `opendir`

**Description** : Ouvre un répertoire.

**Bibliothèque** : `#include <dirent.h>`

**Prototypage** : `DIR *opendir(const char *name);`

**Paramètres** :
- `const char *name` - Le chemin du répertoire.

**Valeur de retour** :
- `DIR *` - Le pointeur vers le répertoire, ou `NULL` en cas d'erreur.

**Exemple** :
```c
DIR *dir = opendir(".");
if (dir) {
    closedir(dir);
}
```

#### `readdir`

**Description** : Lit une entrée de répertoire.

**Bibliothèque** : `#include <dirent.h>`

**Prototypage** : `struct dirent *readdir(DIR *dirp);`

**Paramètres** :
- `DIR *dirp` - Le pointeur vers le répertoire.

**Valeur de retour** :
- `struct dirent *` - L'entrée de répertoire, ou `NULL` en cas d'erreur ou de fin de répertoire.

**Exemple** :
```c
struct dirent *entry;
while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
}
```

#### `closedir`

**Description** : Ferme un répertoire.

**Bibliothèque** : `#include <dirent.h>`

**Prototypage** : `int closedir(DIR *dirp);`

**Paramètres** :
- `DIR *dirp` - Le pointeur vers le répertoire.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
closedir(dir);
```

### Gestion des signaux

#### `signal`

**Description** : Définit un gestionnaire de signal.

**Bibliothèque** : `#include <signal.h>`

**Prototypage** : `sighandler_t signal(int signum, sighandler_t handler);`

**Paramètres** :
- `int signum` - Le numéro du signal.
- `sighandler_t handler` - Le gestionnaire de signal.

**Valeur de retour** :
- `sighandler_t` - L'ancien gestionnaire de signal.

**Exemple** :
```c
signal(SIGINT, SIG_IGN); // Ignore le signal SIGINT (Ctrl+C)
```

#### `sigaction`

**Description** : Examine ou modifie l'action associée à un signal.

**Bibliothèque** : `#include <signal.h>`

**Prototypage** : `int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);`

**Paramètres** :
- `int signum` - Le numéro du signal.
- `const struct sigaction *act` - La nouvelle action.
- `struct sigaction *oldact` - L'ancienne action.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
struct sigaction sa;
sa.sa_handler = SIG_IGN;
sigaction(SIGINT, &sa, NULL);
```

#### `sigemptyset`

**Description** : Initialise un ensemble de signaux vide.

**Bibliothèque** : `#include <signal.h>`

**Prototypage** : `int sigemptyset(sigset_t *set);`

**Paramètres** :
- `sigset_t *set` - L'ensemble de signaux.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
sigset_t set;
sigemptyset(&set);
```

#### `sigaddset`

**Description** : Ajoute un signal à un ensemble de signaux.

**Bibliothèque** : `#include <signal.h>`

**Prototypage** : `int sigaddset(sigset_t *set, int signum);`

**Paramètres** :
- `sigset_t *set` - L'ensemble de signaux.
- `int signum` - Le numéro du signal.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
sigaddset(&set, SIGINT);
```

#### `kill`

**Description** : Envoie un signal à un processus.

**Bibliothèque** : `#include <signal.h>`

**Prototypage** : `int kill(pid_t pid, int sig);`

**Paramètres** :
- `pid_t pid` - L'ID du processus.
- `int sig` - Le numéro du signal.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
kill(pid, SIGTERM); // Envoie le signal SIGTERM pour terminer le processus
```

### Gestion de la mémoire

#### `malloc`

**Description** : Alloue de la mémoire dynamiquement.

**Bibliothèque** : `#include <stdlib.h>`

**Prototypage** : `void *malloc(size_t size);`

**Paramètres** :
- `size_t size` - La taille de la mémoire à allouer.

**Valeur de retour** :
- `void *` - Un pointeur vers la mémoire allouée, ou `NULL` en cas d'erreur.

**Exemple** :
```c
int *tableau = (int *)malloc(10 * sizeof(int));
if (tableau != NULL) {
    // Utiliser tableau
    free(tableau);
}
```

#### `free`

**Description** : Libère de la mémoire allouée dynamiquement.

**Bibliothèque** : `#include <stdlib.h>`

**Prototypage** : `void free(void *ptr);`

**Paramètres** :
- `void *ptr` - Le pointeur vers la mémoire à libérer.

**Valeur de retour** : Aucune.

**Exemple** :
```c
free(tableau);
```

### Gestion des erreurs

#### `strerror`

**Description** : Retourne une chaîne décrivant une erreur.

**Bibliothèque** : `#include <string.h>`

**Prototypage** : `char *strerror(int errnum);`

**Paramètres** :
- `int errnum` - Le numéro de l'erreur.

**Valeur de retour** :
- `char *` - La chaîne décrivant l'erreur.

**Exemple** :
```c
printf("Erreur : %s\n", strerror(errno));
```

#### `perror`

**Description** : Affiche une chaîne décrivant une erreur sur la sortie standard d'erreur.

**Bibliothèque** : `#include <stdio.h>`

**Prototypage** : `void perror(const char *s);`

**Paramètres** :
- `const char *s` - Le préfixe à afficher.

**Valeur de retour** : Aucune.

**Exemple** :
```c
perror("Erreur");
```

### Gestion des terminaux

#### `isatty`

**Description** : Vérifie si un descripteur de fichier est associé à un terminal.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `int isatty(int fd);`

**Paramètres** :
- `int fd` - Le descripteur de fichier.

**Valeur de retour** :
- `int` - `1` si c'est un terminal, `0` sinon.

**Exemple** :
```c
if (isatty(STDOUT_FILENO)) {
    printf("STDOUT est un terminal.\n");
}
```

#### `ttyname`

**Description** : Retourne le nom du terminal associé à un descripteur de fichier.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `char *ttyname(int fd);`

**Paramètres** :
- `int fd` - Le descripteur de fichier.

**Valeur de retour** :
- `char *` - Le nom du terminal, ou `NULL` en cas d'erreur.

**Exemple** :
```c
char *tty = ttyname(STDOUT_FILENO);
if (tty) {
    printf("Nom du terminal : %s\n", tty);
}
```

#### `ttyslot`

**Description** : Retourne l'index du slot du terminal.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `int ttyslot(void);`

**Paramètres** : Aucun.

**Valeur de retour** :
- `int` - L'index du slot, ou `-1` en cas d'erreur.

**Exemple** :
```c
int slot = ttyslot();
if (slot != -1) {
    printf("Slot du terminal : %d\n", slot);
}
```

#### `ioctl`

**Description** : Effectue une opération d'entrée/sortie de contrôle.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `int ioctl(int fd, int request, ...);`

**Paramètres** :
- `int fd` - Le descripteur de fichier.
- `int request` - La requête.
- `...` - Les arguments supplémentaires.

**Valeur de retour** :
- `int` - Dépend de la requête, `-1` en cas d'erreur.

**Exemple** :
```c
int value;
ioctl(fd, FIONREAD, &value); // Obtient le nombre d'octets disponibles pour la lecture
```

#### `tcsetattr`

**Description** : Définit les paramètres du terminal.

**Bibliothèque** : `#include <termios.h>`

**Prototypage** : `int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);`

**Paramètres** :
- `int fd` - Le descripteur de fichier.
- `int optional_actions` - Les actions optionnelles.
- `const struct termios *termios_p` - Les nouveaux paramètres.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
struct termios t;
tcgetattr(STDIN_FILENO, &t);
t.c_lflag &= ~ICANON;
tcsetattr(STDIN_FILENO, TCSANOW, &t);
```

#### `tcgetattr`

**Description** : Obtient les paramètres du terminal.

**Bibliothèque** : `#include <termios.h>`

**Prototypage** : `int tcgetattr(int fd, struct termios *termios_p);`

**Paramètres** :
- `int fd` - Le descripteur de fichier.
- `struct termios *termios_p` - La structure pour stocker les paramètres.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
struct termios t;
tcgetattr(STDIN_FILENO, &t);
```

### Gestion de l'environnement

#### `getenv`

**Description** : Obtient la valeur d'une variable d'environnement.

**Bibliothèque** : `#include <stdlib.h>`

**Prototypage** : `char *getenv(const char *name);`

**Paramètres** :
- `const char *name` - Le nom de la variable.

**Valeur de retour** :
- `char *` - La valeur de la variable, ou `NULL` si elle n'existe pas.

**Exemple** :
```c
char *path = getenv("PATH");
if (path) {
    printf("PATH : %s\n", path);
}
```

### Gestion des tubes (pipes)

#### `pipe`

**Description** : Crée un tube (pipe) pour la communication entre processus.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `int pipe(int pipefd[2]);`

**Paramètres** :
- `int pipefd[2]` - Le tableau pour stocker les descripteurs de fichier du tube.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
int fd[2];
if (pipe(fd) == 0) {
    // Utiliser fd[0] pour lire, fd[1] pour écrire
}
```

#### `dup`

**Description** : Duplique un descripteur de fichier.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `int dup(int oldfd);`

**Paramètres** :
- `int oldfd` - Le descripteur de fichier à dupliquer.

**Valeur de retour** :
- `int` - Le nouveau descripteur de fichier, ou `-1` en cas d'erreur.

**Exemple** :
```c
int newfd = dup(oldfd);
```

#### `dup2`

**Description** : Duplique un descripteur de fichier dans un autre.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `int dup2(int oldfd, int newfd);`

**Paramètres** :
- `int oldfd` - Le descripteur de fichier à dupliquer.
- `int newfd` - Le nouveau descripteur de fichier.

**Valeur de retour** :
- `int` - Le nouveau descripteur de fichier, ou `-1` en cas d'erreur.

**Exemple** :
```c
dup2(oldfd, newfd);
```

### Gestion des informations système

#### `getcwd`

**Description** : Obtient le répertoire de travail courant.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `char *getcwd(char *buf, size_t size);`

**Paramètres** :
- `char *buf` - Le buffer pour stocker le chemin.
- `size_t size` - La taille du buffer.

**Valeur de retour** :
- `char *` - Le chemin du répertoire courant, ou `NULL` en cas d'erreur.

**Exemple** :
```c
char buffer[1024];
if (getcwd(buffer, sizeof(buffer)) != NULL) {
    printf("Répertoire courant : %s\n", buffer);
}
```

#### `chdir`

**Description** : Change le répertoire de travail courant.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `int chdir(const char *path);`

**Paramètres** :
- `const char *path` - Le chemin du nouveau répertoire.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
if (chdir("/tmp") == 0) {
    printf("Répertoire changé en /tmp.\n");
}
```

### Gestion de la base de données terminfo

#### `tgetent`

**Description** : Lit une entrée de la base de données terminfo.

**Bibliothèque** : `#include <term.h>`

**Prototypage** : `int tgetent(char *bp, const char *name);`

**Paramètres** :
- `char *bp` - Le buffer pour stocker l'entrée.
- `const char *name` - Le nom du terminal.

**Valeur de retour** :
- `int` - `1` en cas de succès, `0` si l'entrée n'existe pas, `-1` en cas d'erreur.

**Exemple** :
```c
char buf[1024];
if (tgetent(buf, "xterm") == 1) {
    // Utiliser buf
}
```

#### `tgetflag`

**Description** : Obtient la valeur d'un flag booléen de terminfo.

**Bibliothèque** : `#include <term.h>`

**Prototypage** : `int tgetflag(char *id);`

**Paramètres** :
- `char *id` - L'identifiant du flag.

**Valeur de retour** :
- `int` - La valeur du flag, ou `-1` en cas d'erreur.

**Exemple** :
```c
int flag = tgetflag("bw");
```

#### `tgetnum`

**Description** : Obtient la valeur d'un nombre de terminfo.

**Bibliothèque** : `#include <term.h>`

**Prototypage** : `int tgetnum(char *id);`

**Paramètres** :
- `char *id` - L'identifiant du nombre.

**Valeur de retour** :
- `int` - La valeur du nombre, ou `-1` en cas d'erreur.

**Exemple** :
```c
int num = tgetnum("li");
```

#### `tgetstr`

**Description** : Obtient la valeur d'une chaîne de terminfo.

**Bibliothèque** : `#include <term.h>`

**Prototypage** : `char *tgetstr(char *id, char **area);`

**Paramètres** :
- `char *id` - L'identifiant de la chaîne.
- `char **area` - Le buffer pour stocker la chaîne.

**Valeur de retour** :
- `char *` - La chaîne, ou `NULL` en cas d'erreur.

**Exemple** :
```c
char *str;
tgetstr("cm", &str);
```

#### `tgoto`

**Description** : Calcule les paramètres pour une commande de curseur.

**Bibliothèque** : `#include <term.h>`

**Prototypage** : `char *tgoto(const char *cm, int destcol, int destline);`

**Paramètres** :
- `const char *cm` - La commande de curseur.
- `int destcol` - La colonne de destination.
- `int destline` - La ligne de destination.

**Valeur de retour** :
- `char *` - La commande de curseur calculée.

**Exemple** :
```c
char *cmd = tgoto(cursor_cmd, col, row);
```

#### `tputs`

**Description** : Envoie une commande de terminfo à un terminal.

**Bibliothèque** : `#include <term.h>`

**Prototypage** : `int tputs(const char *str, int affcnt, int (*putfunc)(int));`

**Paramètres** :
- `const char *str` - La commande.
- `int affcnt` - Le nombre d'affirmations.
- `int (*putfunc)(int))` - La fonction de sortie.

**Valeur de retour** :
- `int` - `0` en cas de succès, `-1` en cas d'erreur.

**Exemple** :
```c
tputs(cmd, 1, putchar);
```

### Fonctions diverses

#### `printf`

**Description** : Affiche du texte formaté sur la sortie standard.

**Bibliothèque** : `#include <stdio.h>`

**Prototypage** : `int printf(const char *format, ...);`

**Paramètres** :
- `const char *format` - La chaîne de format, suivie des arguments correspondants.

**Valeur de retour** :
- `int` - Le nombre de caractères écrits.

**Exemple** :
```c
int age = 30;
printf("Bonjour, j'ai %d ans.\n", age);
```

#### `exit`

**Description** : Termine le processus courant.

**Bibliothèque** : `#include <stdlib.h>`

**Prototypage** : `void exit(int status);`

**Paramètres** :
- `int status` - Le statut de sortie.

**Valeur de retour** : Aucune.

**Exemple** :
```c
exit(EXIT_SUCCESS); // Termine le programme avec succès
```

#### `access`

**Description** : Vérifie les permissions d'un fichier.

**Bibliothèque** : `#include <unistd.h>`

**Prototypage** : `int access(const char *pathname, int mode);`

**Paramètres** :
- `const char *pathname` - Le chemin du fichier.
- `int mode` - Le mode de vérification (ex. `F_OK`, `R_OK`).

**Valeur de retour** :
- `int` - `0` si l'accès est possible, `-1` sinon.

**Exemple** :
```c
if (access("fichier.txt", F_OK) == 0) {
    printf("Le fichier existe.\n");
}
```
