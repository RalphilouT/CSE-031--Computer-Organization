CC = gcc
CFLAGS  = -g -Wall
TARGET1=proc1
TARGET2=proc2
TARGET3=proc3
#TARGET3=cyclic_ll

all:	
	$(CC) proc1.c -o $(TARGET1) 
	$(CC) proc2.c -o $(TARGET2)
	$(CC) proc3.c -o $(TARGET3)

clean: 
	rm -f $(TARGET1) $(TARGET2) $(TARGET3)
	# rm *.o $(TARGET)
run1:
	./proc1

run2:
	./proc2

run3:
	./proc3

