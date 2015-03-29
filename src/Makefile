include env.mk

CXX=g++
VERSION=-std=c++14
FLAGS=-g -Wall -Werror
BOOST=-lpthread -lboost_system -lboost_log -lboost_filesystem -lboost_date_time -lboost_thread -lboost_regex

OBJS = \
			 Server.o \
			 AppMain.o \
       Logger.o 

BINARY = ChatRoomServer

all: main 

main: $(OBJS)
	$(CXX) *.o -o	$(BINARY) $(LINKDIR) $(BOOST)

$(OBJS): %.o: %.cpp
	$(CXX) -c $(INCLUDES) $(VERSION) $(FLAGS) $< 
	

#$(OBJS): %.o: %.cpp
#	$(CXX) -c $(INCLUDES) $(VERSION) $(FLAGS) $< -o $@ $(LINKDIR) $(BOOST)



clean:
	rm *.o $(BINARY)
