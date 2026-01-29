### **ожидание завершения потомка**

```
#include <sys/wait.h>
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options);

```

**Параметры `waitpid`:**

- `pid`:
    
    - `>0` — ждать конкретный PID
        
    - `-1` — ждать любого потомка (как `wait()`)
        
    - `0` — ждать потомка из той же группы
        
- `options`:
    
    - `WNOHANG` — не блокировать, вернуться немедленно
        
    - `WUNTRACED` — ждать даже остановленных потомков

```
int status;
pid_t pid = fork();

if (pid == 0) {
    // Потомок
    exit(42);
} else {
    // Родитель ждет
    wait(&status);
    if (WIFEXITED(status)) {
        printf("Child exited with code %d\n", WEXITSTATUS(status));  // 42
    }
}

```