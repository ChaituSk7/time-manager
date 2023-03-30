cc=g++
header_path=../lib/include
so_path=../lib

all: sample sample_application.o

sample: sample_application.o
	$(cc) -o sample sample_application.cpp -ltime_manager -I$(header_path)/ -L$(so_path)/

sample_application.o: sample_application.cpp
	$(cc) -c sample_application.cpp -I$(header_path) 

clean:
	rm -f *.o sample

