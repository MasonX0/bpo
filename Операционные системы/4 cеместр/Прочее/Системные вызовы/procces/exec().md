### **семейство — замена образа процесса**

```
#include <unistd.h>
int execl(const char *path, const char *arg0, ..., (char *)NULL);
int execv(const char *path, char *const argv[]);
int execlp(const char *file, const char *arg0, ..., (char *)NULL);
int execvp(const char *file, char *const argv[]);

```

**Суффиксы:**

- **l** — аргументы передаются списком (list)
    
- **v** — аргументы передаются массивом (vector)
    
- **p** — ищет программу в PATH
    
- **e** — передает environment (envp)

```
// Запускаем ls -l
execl("/bin/ls", "ls", "-l", NULL);

// Или с поиском в PATH
execlp("grep", "grep", "pattern", "file.txt", NULL);

// С массивом аргументов
char *args[] = {"ls", "-l", "-a", NULL};
execv("/bin/ls", args);

```