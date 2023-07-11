CFLAGS += -g -Wall

main : main.c libadd.so
	cc -o main main.c -ldl -ladd
libadd.so : add.o
	cc -shared add.o -o libadd.so
add.o : add.c
	cc -fPIC -c add.c -o add.o
.PHONY :
clean:
	rm -f main *.o *.so *.a
