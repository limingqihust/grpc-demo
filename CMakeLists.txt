cmake_minimum_required(VERSION 3.5)

project(TestGrpcHello LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#假设已经安装好grpc了
find_package(Threads REQUIRED)

set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)


# Find gRPC installation
# Looks for gRPCConfig.cmake file installed by gRPC's cmake installation.
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

set(_GRPC_GRPCPP gRPC::grpc++)


foreach(_target
  greeter_client greeter_server
)
  add_executable(${_target} "${_target}.cc"
    ${hw_proto_srcs}
    ${hw_grpc_srcs}
    elasticcdc.grpc.pb.cc
    elasticcdc.grpc.pb.h
    elasticcdc.pb.cc
    elasticcdc.pb.h)
  target_link_libraries(${_target}
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})
endforeach()




