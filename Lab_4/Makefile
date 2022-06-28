CC = gcc
CFLAGS  = -g -Wall
TARGET=MemCast
TARGET1=Array2D
TARGET2=MatrixMult
TARGET3=cyclic_ll

all:	
	$(CC) MemCast.c -o $(TARGET) 
	$(CC) Array2D.c -o $(TARGET1)
	$(CC) MatrixMult.c -o $(TARGET2)

clean: 
	rm -f $(TARGET1) $(TARGET2) $(TARGET)
	# rm *.o $(TARGET)
run:
	./MemCast

run1:
	./Array2D

run2:
	./MatrixMult

