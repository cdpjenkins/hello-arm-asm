#include <stdint.h>
#include "kernstdlib.h"

void handler(uint64_t numid, uint64_t esr, uint64_t elr) {
    kprintf("numid is %d\n", numid);
    switch (numid) {
        case 1:
            kprintf("sync error at %X: %X\n", elr, esr);
            while (1) ;
            break;
        default:
            kprintf("unknown exception: %d\n", numid);
            while (1) ;
            break;
    }
}