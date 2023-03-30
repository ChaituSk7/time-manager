# This makefile shall be used to create the time_manager.so shared library

path=src
cc=g++

all: time_manager_lib.o libtime_manager.so
	
time_manager_lib.o: $(path)/time_manager_lib.cpp
	$(cc) -c $(path)/time_manager_lib.cpp -fPIC

libtime_manager.so: time_manager_lib.o 
	$(cc) *.o -shared -o libtime_manager.so 

install: libtime_manager.so
	cp libtime_manager.so /usr/lib/

clean:
	rm -f *.o *.so 

