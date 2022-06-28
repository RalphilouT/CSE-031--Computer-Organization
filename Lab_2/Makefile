CC = gcc
CFLAGS  = -g -Wall
TARGET=pointers
TARGET1=average
TARGET2=appendTest
TARGET3=arrCopy

all:	
	$(CC) pointers.c -o $(TARGET) 
	$(CC) average.c -o $(TARGET1)
	$(CC) appendTest.c -o $(TARGET2)
	$(CC) arrCopy.c -o $(TARGET3)
clean: 
	rm -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET)
	# rm *.o $(TARGET)
run:
	./average

run1:
	./appendTest

run2:
	./arrCopy

run3:
	./pointers
