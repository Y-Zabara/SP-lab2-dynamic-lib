CC := g++
CFLAGS := -Wall -Wextra

binary: main.o libtest.so
	$(CC) -o binary main.o -L. -ltest -Wl,-rpath,.

main.o: main.cpp
	$(CC) -c main.cpp

libtest.so: Database.o Defect.o
	$(CC) -shared -o libtest.so Database.o Defect.o

Database.o: Database.cpp
	$(CC) -c -fPIC Database.cpp

Defect.o: Defect.cpp
	$(CC) -c -fPIC Defect.cpp

clean:
	rm -f *.o *.so binary


