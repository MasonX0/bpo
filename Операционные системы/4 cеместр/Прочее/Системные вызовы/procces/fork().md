### **создание процесса-потомка**

```
#include <unistd.h>
pid_t fork(void);

```

**Что делает:** Создает **полную копию** текущего процесса (копия памяти, дескрипторов, регистров).

**Возвращает:**

- **0** — в процессе-потомке
    
- **>0** (PID потомка) — в процессе-родителе
    
- **-1** — ошибка


```
pid_t pid = fork();
if (pid == -1) {
    perror("fork failed");
} else if (pid == 0) {
    // Код потомка
    printf("I'm child, my PID is %d\n", getpid());
} else {
    // Код родителя
    printf("I'm parent, child PID is %d\n", pid);
}

```


