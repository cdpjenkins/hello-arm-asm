#ifndef _HANDLER_H
#define _HANDLER_H

#include <stdint.h>

#define CNTP_EL0 ((uint32_t *)(0x40000040))

#define CNTP_STATUS_EL0 ((uint32_t *) 0x40000060)

// c
uint64_t read_timer_freq();
uint64_t read_timer_value();
void init_timer(void);

// asm
void enable_timer();
void enable_irq();
void set_timer_interval(uint32_t value);
uint32_t read_timer_status();


#endif //_HANDLER_H
