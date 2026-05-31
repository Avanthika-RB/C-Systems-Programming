PROG = buf_of
OBJS = buf_of.o buf_of.o

%.o: %.c
	gcc -c -g -o $@ $< 

$(PROG): $(OBJS)
	gcc -g -o $@ $^ 

clean:
	rm -rf $(PROG) $(OBJS)
