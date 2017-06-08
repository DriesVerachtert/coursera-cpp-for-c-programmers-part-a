CPPFLAGS	= -g -Wall -std=c++11 -I.
LDFLAGS		= -g
LDLIBS		= -L. -lboost_system -lboost_unit_test_framework -lpthread
CC			= g++

TARGETS		= w03_dijkstra GraphTest
OBJS		= Graph.o

all:	$(TARGETS)

w03_dijkstra:  $(OBJS)
GraphTest:  $(OBJS)


clean:
	rm -f *.o $(TARGET)
