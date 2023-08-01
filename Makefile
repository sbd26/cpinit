# install:
# 	gcc main.c helper.c -o cpi
# 	mv cpi /usr/bin/





CC = gcc
SOURCE = *.c
PROG = cpi


$(PROG): $(SOURCE)
	$(CC) $(SOURCE) -o $(PROG)

install: $(PROG)
	cp $(PROG) /usr/bin

clean:
	rm -rf $(PROG)
