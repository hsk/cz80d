# cz80d

This disassembler is as simple as it gets.
However It output instruction cycles.

## Usage

```
$ ./cz80d 
usage: ./cz80d <rom_file>

$ ./cz80d test/test00.out 
0x000000:    00             NOP                  ; [4]
0x000001:    01 01 00       LD     BC,0x001      ; [10]
0x000004:    02             LD     (BC),A        ; [7]
0x000005:    03             INC    BC            ; [6]
0x000006:    04             INC    B             ; [4]
0x000007:    05             DEC    B             ; [4]
0x000008:    06 00          LD     B,0x0         ; [7]
0x00000a:    07             RLCA                 ; [4]
0x00000b:    08             EX     AF,AF'        ; [4]
0x00000c:    09             ADD    HL,BC         ; [11]
0x00000d:    0a             LD     A,(BC)        ; [7]
0x00000e:    0b             DEC    BC            ; [6]
0x00000f:    0c             INC    C             ; [4]
0x000010:    0d             DEC    C             ; [4]
0x000011:    0e 00          LD     C,0x0         ; [7]
0x000013:    0f             RRCA                 ; [4]
```
