





CC=g++
CCFLAGS=--std=c++11
LD=ld
INCLUDE=-I./

objs=Client.cpp Observer.h Observer.cpp Subject.h Subject.cpp User.h User.cpp PublicNumber.h PublicNumber.cpp
DPObserver: $(objs)
	$(CC) $(CCFLAGS) -o DPObserver $(objs)

clean:
	rm DPObserver
