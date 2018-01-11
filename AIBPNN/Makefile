





CC=g++
CCFLAGS=--std=c++11
LD=ld
INCLUDE=-I./
TARGET=AIBPNN

objs=Client.cpp AnnClassifier.h AnnClassifier.cpp DataNode.h DataNode.cpp Neuron.h Neuron.cpp 
AIBPNN: $(objs)
	$(CC) $(CCFLAGS) -o $(TARGET) $(objs)

clean:
	rm $(TARGET)
