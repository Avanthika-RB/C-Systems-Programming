PROG = proj045
OBJS = sha256.o linkedlist.o map.o proj045.o

%.o: %.c
	gcc -c -g -o $@ $< -lm

$(PROG): $(OBJS)
	gcc -g -o $@ $^ -lm

clean:
	rm -rf $(PROG) $(OBJS)
