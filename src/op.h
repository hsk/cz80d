#include <stdint.h>
typedef struct OP {
  uint8_t len;
  uint8_t clock;
  uint8_t clock2;
  char* str;
  uint8_t mode;
} OP;
extern const OP ops[256];
extern const OP cb_ops[256];
extern const OP dd_ops[256];
extern const OP ddcb_ops[256];
extern const OP fd_ops[256];
extern const OP fdcb_ops[256];
extern const OP ed_ops[256];
