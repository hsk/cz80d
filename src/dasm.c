#include <stdio.h>
#include "op.h"

static uint8_t print_line(char *op, uint8_t *code, uint8_t len, uint32_t pc,uint8_t clock) {
    printf("0x%06x:    ", pc);
    for(int i=0;i<len;i++) printf("%02x ", code[i]);
    for(int i=len;i<4;i++) printf("   ");
    printf("   %-20s ; [%d]\n", op,clock);
    return len;
}
static uint8_t print_op(const OP *ops, uint8_t *code, uint32_t pc) {
    const OP* pop = &ops[*code];
    char op[32];
    if (pop->len < 3) snprintf(op, 32, pop->str, code[1]);
    else snprintf(op, 32, pop->str, code[2], code[1]);
    return print_line(op, code, pop->len, pc, pop->clock);
}
static uint8_t print_op2(const OP *ops, uint8_t *code, uint32_t pc) {
    OP* pop = (OP*)&ops[code[1]];
    char op[32];
    if (pop->len==0) {
      pop = &(OP){3, 0, 0,"defb 0x%02X,0x%02X,0x%02X  ; illigal",0};
      snprintf(op, 32, pop->str, code[0],code[1],code[2]);
    } else
    if (pop->len < 4) snprintf(op, 32, pop->str, code[2]);
    else if(pop->mode==0) snprintf(op, 32, pop->str, code[3], code[2]);
    else snprintf(op, 32, pop->str, code[2], code[3]);
    return print_line(op, code, pop->len, pc, pop->clock);
}
static uint8_t print_op3(const OP *ops, uint8_t *code, uint32_t pc) {
    const OP* pop = &ops[code[3]];
    char op[32];
    if (pop->len < 5) snprintf(op, 32, pop->str, code[2]);
    else snprintf(op, 32, pop->str, code[4], code[2]);
    return print_line(op, code, pop->len, pc, pop->clock);
}
uint8_t dasm(uint8_t *buf, uint32_t pc) {
    uint8_t *code = &buf[pc];
    switch(*code) {
      case 0xcb: return print_op2(cb_ops,code,pc);
      case 0xdd: if(code[1]==0xcb) return print_op3(ddcb_ops,code,pc);
                 return print_op2(dd_ops,code,pc);
      case 0xed: return print_op2(ed_ops,code,pc);
      case 0xfd: if(code[1]==0xcb) return print_op3(fdcb_ops,code,pc);
                 return print_op2(fd_ops,code,pc);
      default:   return print_op(ops, code, pc);
    }
}
