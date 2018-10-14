





CC=g++
CCFLAGS=--std=c++11
LD=ld
INCLUDE=-I./
TARGET=DPObserver

objs=Client.cpp Observer.h Observer.cpp Subject.h Subject.cpp User.h User.cpp PublicNumber.h PublicNumber.cpp
DPObserver: $(objs)
	$(CC) $(CCFLAGS) -o $(TARGET) $(objs)

clean:
	rm $(TARGET)
