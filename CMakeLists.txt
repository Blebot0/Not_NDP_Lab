cmake_minimum_required(VERSION 2.8.3)

# The name of this package.
project(ndp_lab)

include_directories(
  include
  "${PROJECT_SOURCE_DIR}/include/",
  "${PROJECT_SOURCE_DIR}/src/"
)
  
# Declare a C++ library for Server
add_library( server_header

  include/Server.h
  src/Server.cpp
)

# Specify executables and libraries against which to link.
add_executable(server src/server_node.cpp)
add_dependencies(server server_header)
target_link_libraries(server server_header)

# Declare a C++ library for Client
add_library( client_header

  include/Client.h
  src/Client.cpp
)

add_executable(client src/client_node.cpp)
add_dependencies(client client_header)
target_link_libraries(client client_header)
