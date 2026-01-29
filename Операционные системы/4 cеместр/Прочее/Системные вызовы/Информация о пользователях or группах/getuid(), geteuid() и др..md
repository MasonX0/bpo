```
	c

#include <unistd.h>
uid_t getuid(void);   // Реальный UID
uid_t geteuid(void);  // Эффективный UID
gid_t getgid(void);   // Реальный GID  
gid_t getegid(void);  // Эффективный GID
```

**Разница:**

- **Real UID/GID** — кто запустил процесс
    
- **Effective UID/GID** — чьи права использует процесс (для доступа к файлам)