PROG = proj04
OBJS = sha256.o linkedlist.o map.o proj04.o

%.o: %.c
	gcc -c -g -o $@ $< -lm

$(PROG): $(OBJS)
	gcc -g -o $@ $^ -lm

clean:
	rm -rf $(PROG) $(OBJS)
