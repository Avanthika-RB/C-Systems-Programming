PROG = proj05
OBJS = mymod.o proj05.o

%.o: %.c
	gcc -c -g -o $@ $< 

$(PROG): $(OBJS)
	gcc -g -o $@ $^ 

clean:
	rm -rf $(PROG) $(OBJS)
