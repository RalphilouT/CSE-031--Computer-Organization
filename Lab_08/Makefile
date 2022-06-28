CC = gcc
CFLAGS  = -g -Wall
TARGET1=recursion
TARGET2=recursion1
TARGET3=proc3
#TARGET3=cyclic_ll

all:	
	$(CC) recursion.c -o $(TARGET1) 
	$(CC) recursion1.c -o $(TARGET2)
	#$(CC) proc3.c -o $(TARGET3)

clean: 
	rm -f $(TARGET1) $(TARGET2) 
	# rm *.o $(TARGET)
run1:
	./recursion

run2:
	./recursion1


