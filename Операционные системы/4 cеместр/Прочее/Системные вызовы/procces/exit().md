###  **завершение процесса**

```
#include <stdlib.h>
void exit(int status);
#include <unistd.h>
void _exit(int status);

```

**Разница:**

- `exit()` — из stdlib.h, вызывает atexit(), сбрасывает буферы stdio
    
- `_exit()` — системный вызов, завершает немедленно


```
if (error) {
    exit(EXIT_FAILURE);  // 1
}
// Или
_exit(0);  // Немедленное завершение


всегда завершается удачно
