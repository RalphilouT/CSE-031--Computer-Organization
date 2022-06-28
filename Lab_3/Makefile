CC = gcc
CFLAGS  = -g -Wall
TARGET=mem
TARGET1=NodeStruct
TARGET2=array
TARGET3=cyclic_ll

all:	
	$(CC) mem.c -o $(TARGET) 
	$(CC) NodeStruct.c -o $(TARGET1)
	$(CC) array.c -o $(TARGET2)
	$(CC) cyclic_ll.c -o $(TARGET3)
clean: 
	rm -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET)
	# rm *.o $(TARGET)
run:
	./mem

run1:
	./NodeStruct

run2:
	./array

run3:
	./cyclic_ll
