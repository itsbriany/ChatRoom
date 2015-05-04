project(ChatRoomServer)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(ChatRoomServer AppMain.cpp ChatRoom.cpp
                   ChatSession.cpp Logger.cpp Participant.cpp
                   Server.cpp TcpConnection.cpp)
    target_link_libraries(ChatRoomServer Threads::Threads)
    target_link_libraries(ChatRoomServer ${Boost_LIBRARIES})
endif()
