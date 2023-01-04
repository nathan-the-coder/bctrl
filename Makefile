CC=g++

EXEC=bctrl

$(EXEC):
	$(CC) -o $(EXEC) $(EXEC).cpp

install: $(EXEC)
	install ./bctrl /usr/local/bin
clean:
	rm $(EXEC)
