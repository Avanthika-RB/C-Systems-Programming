PROG = lab06
OBJS = lab06.o dynamiclist.o

%.o: %.c
	gcc -c -g -o $@ $< 

$(PROG): $(OBJS)
	gcc -g -o $@ $^ 

clean:
	rm -rf $(PROG) $(OBJS)
