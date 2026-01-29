### **1. ` — информация о времени процесса

```

#include <sys/times.h>
clock_t times(struct tms *buf);

Заполняет структуру:

struct tms {
    clock_t tms_utime;   // время в пользовательском режиме
    clock_t tms_stime;   // время в системном режиме  
    clock_t tms_cutime;  // пользовательское время потомков
    clock_t tms_cstime;  // системное время потомков
};
```