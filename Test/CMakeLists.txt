CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(DataStructure_and_Algorithm)

ADD_COMPILE_OPTIONS(-std=c++11)
EXECUTE_PROCESS(COMMAND dirname ${PROJECT_SOURCE_DIR}
                OUTPUT_VARIABLE INCLUDE_DIR)
INCLUDE_DIRECTORIES(${INCLUDE_DIR})
INCLUDE_DIRECTORIES(/usr/local/include)

# BinaryTree
ADD_EXECUTABLE(CompleteBinaryTree_test CompleteBinaryTree_test.cpp)
ADD_EXECUTABLE(BinaryTree_test BinaryTree_test.cpp)

# List
ADD_EXECUTABLE(Deque_test Deque_test.cpp)
ADD_EXECUTABLE(ForwardList_test ForwardList_test.cpp)
ADD_EXECUTABLE(CircleList_test CircleList_test.cpp)
ADD_EXECUTABLE(List_test List_test.cpp)

# Queue
ADD_EXECUTABLE(Queue_test Queue_test.cpp)
ADD_EXECUTABLE(CircleQueue_test CircleQueue_test.cpp)

# Search
ADD_EXECUTABLE(BinarySearch_test BinarySearch_test.cpp)

# Sort
ADD_EXECUTABLE(MergeSort_test MergeSort_test.cpp)

# Stack
ADD_EXECUTABLE(Stack_test Stack_test.cpp)