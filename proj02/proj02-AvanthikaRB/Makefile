PROG = proj02
OBJS = proj02.o linkedlist.o

%.o: %.c
	gcc -c -g -o $@ $<

$(PROG): $(OBJS)
	gcc  -g -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
