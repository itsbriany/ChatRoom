include env.mk

CXX=g++
VERSION=-std=c++14
FLAGS=-g -Wall -Werror
BOOST=-lpthread -lboost_system -lboost_log -lboost_filesystem -lboost_date_time -lboost_thread -lboost_regex

OBJS = Logger.o

all: $(OBJS)

$(OBJS): %.o: %.cpp
	$(CXX) $(INCLUDES) $(VERSION) $(FLAGS) $< -o $@ $(LINKDIR) $(BOOST)

clean:
	rm *.o
