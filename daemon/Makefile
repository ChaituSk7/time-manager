cc=g++
path=src
all: time_daemon time_manager_daemon.o

time_manager_daemon.o: $(path)/*.cpp
	$(cc) -c $(path)/*.cpp -pthread

time_daemon: time_manager_daemon.o 
	$(cc) -o time_daemon $(path)/*.cpp -pthread
clean:
	rm -f *.o time_daemon
