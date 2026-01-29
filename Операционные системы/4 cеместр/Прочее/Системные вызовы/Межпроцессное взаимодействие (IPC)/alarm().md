### ` — установка будильника


```
#include <unistd.h>
unsigned int alarm(unsigned int seconds);
```
Через `seconds` секунд процесс получит SIGALRM.