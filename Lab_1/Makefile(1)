CC = gcc
CFLAGS  = -g -Wall
TARGET=main
TARGET1=punishment
TARGET2=averages
all:	
	$(CC) main.c -o $(TARGET) 
	$(CC) punishment.c -o $(TARGET1)
	$(CC) averages.c -o $(TARGET2)
clean: 
	rm -f $(TARGET) $(TARGET1) $(TARGET2)
	# rm *.o $(TARGET)
run:
	./main

run1:
	./punishment

run2:
	./averages
