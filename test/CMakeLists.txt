cmake_minimum_required(VERSION 3.10)
project(KimeraVioTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)
find_package(GTSAM REQUIRED)
find_package(Eigen3 REQUIRED)
# find_package(GTSAM REQUIRED)
# You may not need this if everything is installed in standard locations:
include_directories(
  ${OpenCV_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
  ${GTSAM_INCLUDE_DIR}
  /usr/local/include          # if Kimera-VIO headers are here
)

link_directories(
  /usr/local/lib              # if Kimera-VIO .so is here
)

add_executable(test_kimera test_kimera.cpp)


# target_link_libraries(your_target PRIVATE gtsam)
target_link_libraries(test_kimera
  kimera_vio
  ${OpenCV_LIBS}
  gtsam
  Threads::Threads
)
