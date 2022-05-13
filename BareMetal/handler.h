#ifndef _HANDLER_H
#define _HANDLER_H

#include <stdint.h>

#include "memory.h"

#define CNTP_EL0 ((uint32_t *)          P2V(0x40000040))
#define CNTP_STATUS_EL0 ((uint32_t *)   P2V(0x40000060))

#define BASE_ADDR                       P2V(0x3f000000)

#define IRQ_BASIC_PENDING       ((volatile uint32_t *)(BASE_ADDR + 0xB200))
#define ENABLE_IRQS_1           ((volatile uint32_t *)(BASE_ADDR + 0xB210))
#define ENABLE_IRQS_2           ((volatile uint32_t *)(BASE_ADDR + 0xB214))
#define ENABLE_BASIC_IRQS       ((volatile uint32_t *)(BASE_ADDR + 0xB218))
#define DISABLE_IRQS_1          ((volatile uint32_t *)(BASE_ADDR + 0xB21C))
#define DISABLE_IRQS_2          ((volatile uint32_t *)(BASE_ADDR + 0xB220))
#define DISABLE_BASIC_IRQS      ((volatile uint32_t *)(BASE_ADDR + 0xB224))


// c
uint64_t read_timer_freq();
uint64_t read_timer_value();
void init_timer(void);
void init_interrupt_controller();

// asm
void enable_timer();
void enable_irq();
void set_timer_interval(uint32_t value);
uint32_t read_timer_status();


#endif //_HANDLER_H
