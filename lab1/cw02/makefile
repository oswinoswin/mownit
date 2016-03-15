CC = gcc -Wall
FILE = gauss2.cpp 
OUTPUT = gauss2.o

all: gauss2.cpp


gauss2.o: $(FILE)
	$(CC) $(FILE) -c -o $(OUTPUT)

run:
	$(OUTPUT) 2
clean:
	rm gauss2
run:
	for number in 4 5 6 7 8 9 10 11 12 13 ; do \
	./gauss2 $$number >> wyniki.txt; \
	done
