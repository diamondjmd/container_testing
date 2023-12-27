# Container Testing with gtest
Implementing unit tests for two containers - sequential and list type (our custom container::Vector class and custom container::List class). 

## Testing scenarios
Using Gtest, the following test scenarios are implemented for each container:
- creating a container
- inserting elements at the end
- inserting elements at the beginning
- inserting elements in the middle
- removing elements from the end
- removing elements from the beginning
- removing elements from the middle
- getting elements from the container
- getting the container size (actual number of elements)

- copying a container. The test check that after copying one container object to another, the contents of
both containers are the same
- deleting a container. The test verify that all elements inside the container had their destructor called when
the container object was destroyed.
- moving the container (calling the moving assignment operator).

## Installing gtest
### Install vcpkg
Installing vcpkg is a two-step process: first, clone the repo, then run the bootstrapping script to produce the vcpkg binary. The repo can be cloned anywhere, and will include the vcpkg binary after bootstrapping as well as any libraries that are installed from the command line. It is recommended to clone vcpkg as a submodule to an existing project if possible for greater flexibility.

#### Step 1: Clone the vcpkg repo

git clone https://github.com/Microsoft/vcpkg.git

Make sure you are in the directory you want the tool installed to before doing this.

#### Step 2: Run the bootstrap script to build vcpkg

./vcpkg/bootstrap-vcpkg.sh

Install libraries for your project
vcpkg install gtest

### Using vcpkg with CMake
In order to use vcpkg with CMake outside of an IDE, you can use the toolchain file:
cmake -B [build directory] -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake

### Then build with:

cmake --build [build directory]

With CMake, you will need to find_package() to reference the libraries in your CMakeLists.txt files.


## Test Command line arguments 
### gtest_filter 
 Allows you to run only specific tests by passing a filter by name. tests of the vector container
 #### Example
 This command will lead to running only 
```
./containers_tests --gtest_filter=VectorTest.*
```

### gtest_repeat 
 Allows you to repeat running tests a specified number of times, which is very useful
when investigating floating problems. 
#### Example
This command will cause all tests to be run 10 times.
```
./containers_tests --gtest_repeat=10
```

### gtest_output 
 Allows you to generate an xml report based on the results of running tests. 
#### Example:
```
./containers_tests --gtest_output=xml:report.xml
```
