CXX=clang-3.5
VERSION=-std=c++14
FLAGS=-Wall -Werror -Wextra
INCLUDES=-I/home/itsbriany/workbench/libs/boost_1_57_0/
LINKDIR=-L/home/itsbriany/workbench/libs/workbench/libs/boost_1_57_0/stage/lib/
BOOST=-lboost_system

OBJS = Server.o

all: $(OBJS)

$(OBJS): %.o: %.cpp
	$(CXX) $(INCLUDES) $(VERSION) $(FLAGS) $< -o $@ $(LINKDIR)

clean:
	rm *.o
