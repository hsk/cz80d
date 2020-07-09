SRCS=$(wildcard src/*.c)
OBJS=$(subst src/,out/,$(SRCS:.c=.o))

all: cz80d

cz80d: $(OBJS)
	gcc -o cz80d $(OBJS)

out/%.o: src/%.c
	gcc -c $< -o $@

clean:
	$(RM) $(OBJS) cz80d
