CC = gcc
CFLAGS = -Wall -pedantic -I include -g 
SRC = $(wildcard *.c src/*.c src/**/*.c src/**/**/*.c)
HEAD = $(wildcard include/*.h include/**/*.h)
OBJ = $(SRC:.c=.o)
EXEC = bin/sip

all: clean $(OBJ) $(EXEC) $(HEAD)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@
	rm -rf src/*.o
	rm -rf src/**/*.o
	rm -rf src/**/**/*.o

%.o: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

build:
	make
	cd bin
	zip csn.zip ./csn
	cd ..
	make clean

install:
	chmod +x install.sh
	./install.sh

clean:
	rm -rf *.o src/*.o src/**/*.o src/**/**/*.o $(EXEC)