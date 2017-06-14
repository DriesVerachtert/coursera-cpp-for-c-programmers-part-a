CPPFLAGS	= -g -Wall -Wextra -Werror -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wno-unused -Wundef -std=c++11 -I. 
LDFLAGS		= -g
LDLIBS		= -L. -lboost_system -lboost_unit_test_framework -lpthread
CC			= g++
TARGETS		= W03Dijkstra GraphTest RandomGraphGeneratorTest ShortestPathCalculatorTest PriorityQueueTest
OBJS		= Graph.o RandomGraphGenerator.o ShortestPathCalculator.o PriorityQueue.o

all:	$(TARGETS) test

# Not perfect but acceptable for such a small program: simply depend on all objects
W03Dijkstra:  $(OBJS)
GraphTest:  $(OBJS)
RandomGraphGeneratorTest:  $(OBJS)
ShortestPathCalculatorTest: $(OBJS)
PriorityQueueTest: $(OBJS)


clean:
	rm -f *.o $(TARGETS)

# boost runtime parameters: http://www.boost.org/doc/libs/1_46_1/libs/test/doc/html/utf/user-guide/runtime-config/reference.html
test:
	./GraphTest --log_level=warning --report_level=short
	./RandomGraphGeneratorTest --log_level=warning --report_level=short
	./ShortestPathCalculatorTest --log_level=warning --report_level=short
	./PriorityQueueTest --log_level=warning --report_level=short