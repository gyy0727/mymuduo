# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/muqiu0614/desktop/muduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/muqiu0614/desktop/muduo/build

# Include any dependencies generated for this target.
include CMakeFiles/muduo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/muduo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/muduo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/muduo.dir/flags.make

CMakeFiles/muduo.dir/src/Acceptor.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/Acceptor.cc.o: ../src/Acceptor.cc
CMakeFiles/muduo.dir/src/Acceptor.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/muduo.dir/src/Acceptor.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/Acceptor.cc.o -MF CMakeFiles/muduo.dir/src/Acceptor.cc.o.d -o CMakeFiles/muduo.dir/src/Acceptor.cc.o -c /home/muqiu0614/desktop/muduo/src/Acceptor.cc

CMakeFiles/muduo.dir/src/Acceptor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/Acceptor.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/Acceptor.cc > CMakeFiles/muduo.dir/src/Acceptor.cc.i

CMakeFiles/muduo.dir/src/Acceptor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/Acceptor.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/Acceptor.cc -o CMakeFiles/muduo.dir/src/Acceptor.cc.s

CMakeFiles/muduo.dir/src/Buffer.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/Buffer.cc.o: ../src/Buffer.cc
CMakeFiles/muduo.dir/src/Buffer.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/muduo.dir/src/Buffer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/Buffer.cc.o -MF CMakeFiles/muduo.dir/src/Buffer.cc.o.d -o CMakeFiles/muduo.dir/src/Buffer.cc.o -c /home/muqiu0614/desktop/muduo/src/Buffer.cc

CMakeFiles/muduo.dir/src/Buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/Buffer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/Buffer.cc > CMakeFiles/muduo.dir/src/Buffer.cc.i

CMakeFiles/muduo.dir/src/Buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/Buffer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/Buffer.cc -o CMakeFiles/muduo.dir/src/Buffer.cc.s

CMakeFiles/muduo.dir/src/Channel.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/Channel.cc.o: ../src/Channel.cc
CMakeFiles/muduo.dir/src/Channel.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/muduo.dir/src/Channel.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/Channel.cc.o -MF CMakeFiles/muduo.dir/src/Channel.cc.o.d -o CMakeFiles/muduo.dir/src/Channel.cc.o -c /home/muqiu0614/desktop/muduo/src/Channel.cc

CMakeFiles/muduo.dir/src/Channel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/Channel.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/Channel.cc > CMakeFiles/muduo.dir/src/Channel.cc.i

CMakeFiles/muduo.dir/src/Channel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/Channel.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/Channel.cc -o CMakeFiles/muduo.dir/src/Channel.cc.s

CMakeFiles/muduo.dir/src/CurrentThreadId.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/CurrentThreadId.cc.o: ../src/CurrentThreadId.cc
CMakeFiles/muduo.dir/src/CurrentThreadId.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/muduo.dir/src/CurrentThreadId.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/CurrentThreadId.cc.o -MF CMakeFiles/muduo.dir/src/CurrentThreadId.cc.o.d -o CMakeFiles/muduo.dir/src/CurrentThreadId.cc.o -c /home/muqiu0614/desktop/muduo/src/CurrentThreadId.cc

CMakeFiles/muduo.dir/src/CurrentThreadId.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/CurrentThreadId.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/CurrentThreadId.cc > CMakeFiles/muduo.dir/src/CurrentThreadId.cc.i

CMakeFiles/muduo.dir/src/CurrentThreadId.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/CurrentThreadId.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/CurrentThreadId.cc -o CMakeFiles/muduo.dir/src/CurrentThreadId.cc.s

CMakeFiles/muduo.dir/src/DefaultPoller.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/DefaultPoller.cc.o: ../src/DefaultPoller.cc
CMakeFiles/muduo.dir/src/DefaultPoller.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/muduo.dir/src/DefaultPoller.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/DefaultPoller.cc.o -MF CMakeFiles/muduo.dir/src/DefaultPoller.cc.o.d -o CMakeFiles/muduo.dir/src/DefaultPoller.cc.o -c /home/muqiu0614/desktop/muduo/src/DefaultPoller.cc

CMakeFiles/muduo.dir/src/DefaultPoller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/DefaultPoller.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/DefaultPoller.cc > CMakeFiles/muduo.dir/src/DefaultPoller.cc.i

CMakeFiles/muduo.dir/src/DefaultPoller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/DefaultPoller.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/DefaultPoller.cc -o CMakeFiles/muduo.dir/src/DefaultPoller.cc.s

CMakeFiles/muduo.dir/src/EPollPoller.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/EPollPoller.cc.o: ../src/EPollPoller.cc
CMakeFiles/muduo.dir/src/EPollPoller.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/muduo.dir/src/EPollPoller.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/EPollPoller.cc.o -MF CMakeFiles/muduo.dir/src/EPollPoller.cc.o.d -o CMakeFiles/muduo.dir/src/EPollPoller.cc.o -c /home/muqiu0614/desktop/muduo/src/EPollPoller.cc

CMakeFiles/muduo.dir/src/EPollPoller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/EPollPoller.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/EPollPoller.cc > CMakeFiles/muduo.dir/src/EPollPoller.cc.i

CMakeFiles/muduo.dir/src/EPollPoller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/EPollPoller.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/EPollPoller.cc -o CMakeFiles/muduo.dir/src/EPollPoller.cc.s

CMakeFiles/muduo.dir/src/EventLoop.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/EventLoop.cc.o: ../src/EventLoop.cc
CMakeFiles/muduo.dir/src/EventLoop.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/muduo.dir/src/EventLoop.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/EventLoop.cc.o -MF CMakeFiles/muduo.dir/src/EventLoop.cc.o.d -o CMakeFiles/muduo.dir/src/EventLoop.cc.o -c /home/muqiu0614/desktop/muduo/src/EventLoop.cc

CMakeFiles/muduo.dir/src/EventLoop.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/EventLoop.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/EventLoop.cc > CMakeFiles/muduo.dir/src/EventLoop.cc.i

CMakeFiles/muduo.dir/src/EventLoop.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/EventLoop.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/EventLoop.cc -o CMakeFiles/muduo.dir/src/EventLoop.cc.s

CMakeFiles/muduo.dir/src/EventLoopThread.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/EventLoopThread.cc.o: ../src/EventLoopThread.cc
CMakeFiles/muduo.dir/src/EventLoopThread.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/muduo.dir/src/EventLoopThread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/EventLoopThread.cc.o -MF CMakeFiles/muduo.dir/src/EventLoopThread.cc.o.d -o CMakeFiles/muduo.dir/src/EventLoopThread.cc.o -c /home/muqiu0614/desktop/muduo/src/EventLoopThread.cc

CMakeFiles/muduo.dir/src/EventLoopThread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/EventLoopThread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/EventLoopThread.cc > CMakeFiles/muduo.dir/src/EventLoopThread.cc.i

CMakeFiles/muduo.dir/src/EventLoopThread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/EventLoopThread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/EventLoopThread.cc -o CMakeFiles/muduo.dir/src/EventLoopThread.cc.s

CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.o: ../src/EventLoopThreadPool.cc
CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.o -MF CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.o.d -o CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.o -c /home/muqiu0614/desktop/muduo/src/EventLoopThreadPool.cc

CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/EventLoopThreadPool.cc > CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.i

CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/EventLoopThreadPool.cc -o CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.s

CMakeFiles/muduo.dir/src/Fiber.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/Fiber.cc.o: ../src/Fiber.cc
CMakeFiles/muduo.dir/src/Fiber.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/muduo.dir/src/Fiber.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/Fiber.cc.o -MF CMakeFiles/muduo.dir/src/Fiber.cc.o.d -o CMakeFiles/muduo.dir/src/Fiber.cc.o -c /home/muqiu0614/desktop/muduo/src/Fiber.cc

CMakeFiles/muduo.dir/src/Fiber.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/Fiber.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/Fiber.cc > CMakeFiles/muduo.dir/src/Fiber.cc.i

CMakeFiles/muduo.dir/src/Fiber.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/Fiber.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/Fiber.cc -o CMakeFiles/muduo.dir/src/Fiber.cc.s

CMakeFiles/muduo.dir/src/InetAddress.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/InetAddress.cc.o: ../src/InetAddress.cc
CMakeFiles/muduo.dir/src/InetAddress.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/muduo.dir/src/InetAddress.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/InetAddress.cc.o -MF CMakeFiles/muduo.dir/src/InetAddress.cc.o.d -o CMakeFiles/muduo.dir/src/InetAddress.cc.o -c /home/muqiu0614/desktop/muduo/src/InetAddress.cc

CMakeFiles/muduo.dir/src/InetAddress.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/InetAddress.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/InetAddress.cc > CMakeFiles/muduo.dir/src/InetAddress.cc.i

CMakeFiles/muduo.dir/src/InetAddress.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/InetAddress.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/InetAddress.cc -o CMakeFiles/muduo.dir/src/InetAddress.cc.s

CMakeFiles/muduo.dir/src/Logger.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/Logger.cc.o: ../src/Logger.cc
CMakeFiles/muduo.dir/src/Logger.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/muduo.dir/src/Logger.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/Logger.cc.o -MF CMakeFiles/muduo.dir/src/Logger.cc.o.d -o CMakeFiles/muduo.dir/src/Logger.cc.o -c /home/muqiu0614/desktop/muduo/src/Logger.cc

CMakeFiles/muduo.dir/src/Logger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/Logger.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/Logger.cc > CMakeFiles/muduo.dir/src/Logger.cc.i

CMakeFiles/muduo.dir/src/Logger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/Logger.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/Logger.cc -o CMakeFiles/muduo.dir/src/Logger.cc.s

CMakeFiles/muduo.dir/src/Poller.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/Poller.cc.o: ../src/Poller.cc
CMakeFiles/muduo.dir/src/Poller.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/muduo.dir/src/Poller.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/Poller.cc.o -MF CMakeFiles/muduo.dir/src/Poller.cc.o.d -o CMakeFiles/muduo.dir/src/Poller.cc.o -c /home/muqiu0614/desktop/muduo/src/Poller.cc

CMakeFiles/muduo.dir/src/Poller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/Poller.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/Poller.cc > CMakeFiles/muduo.dir/src/Poller.cc.i

CMakeFiles/muduo.dir/src/Poller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/Poller.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/Poller.cc -o CMakeFiles/muduo.dir/src/Poller.cc.s

CMakeFiles/muduo.dir/src/Socket.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/Socket.cc.o: ../src/Socket.cc
CMakeFiles/muduo.dir/src/Socket.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/muduo.dir/src/Socket.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/Socket.cc.o -MF CMakeFiles/muduo.dir/src/Socket.cc.o.d -o CMakeFiles/muduo.dir/src/Socket.cc.o -c /home/muqiu0614/desktop/muduo/src/Socket.cc

CMakeFiles/muduo.dir/src/Socket.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/Socket.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/Socket.cc > CMakeFiles/muduo.dir/src/Socket.cc.i

CMakeFiles/muduo.dir/src/Socket.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/Socket.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/Socket.cc -o CMakeFiles/muduo.dir/src/Socket.cc.s

CMakeFiles/muduo.dir/src/TcpConnection.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/TcpConnection.cc.o: ../src/TcpConnection.cc
CMakeFiles/muduo.dir/src/TcpConnection.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/muduo.dir/src/TcpConnection.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/TcpConnection.cc.o -MF CMakeFiles/muduo.dir/src/TcpConnection.cc.o.d -o CMakeFiles/muduo.dir/src/TcpConnection.cc.o -c /home/muqiu0614/desktop/muduo/src/TcpConnection.cc

CMakeFiles/muduo.dir/src/TcpConnection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/TcpConnection.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/TcpConnection.cc > CMakeFiles/muduo.dir/src/TcpConnection.cc.i

CMakeFiles/muduo.dir/src/TcpConnection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/TcpConnection.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/TcpConnection.cc -o CMakeFiles/muduo.dir/src/TcpConnection.cc.s

CMakeFiles/muduo.dir/src/TcpServer.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/TcpServer.cc.o: ../src/TcpServer.cc
CMakeFiles/muduo.dir/src/TcpServer.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/muduo.dir/src/TcpServer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/TcpServer.cc.o -MF CMakeFiles/muduo.dir/src/TcpServer.cc.o.d -o CMakeFiles/muduo.dir/src/TcpServer.cc.o -c /home/muqiu0614/desktop/muduo/src/TcpServer.cc

CMakeFiles/muduo.dir/src/TcpServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/TcpServer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/TcpServer.cc > CMakeFiles/muduo.dir/src/TcpServer.cc.i

CMakeFiles/muduo.dir/src/TcpServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/TcpServer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/TcpServer.cc -o CMakeFiles/muduo.dir/src/TcpServer.cc.s

CMakeFiles/muduo.dir/src/Thread.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/Thread.cc.o: ../src/Thread.cc
CMakeFiles/muduo.dir/src/Thread.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/muduo.dir/src/Thread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/Thread.cc.o -MF CMakeFiles/muduo.dir/src/Thread.cc.o.d -o CMakeFiles/muduo.dir/src/Thread.cc.o -c /home/muqiu0614/desktop/muduo/src/Thread.cc

CMakeFiles/muduo.dir/src/Thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/Thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/Thread.cc > CMakeFiles/muduo.dir/src/Thread.cc.i

CMakeFiles/muduo.dir/src/Thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/Thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/Thread.cc -o CMakeFiles/muduo.dir/src/Thread.cc.s

CMakeFiles/muduo.dir/src/main.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/main.cc.o: ../src/main.cc
CMakeFiles/muduo.dir/src/main.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/muduo.dir/src/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/main.cc.o -MF CMakeFiles/muduo.dir/src/main.cc.o.d -o CMakeFiles/muduo.dir/src/main.cc.o -c /home/muqiu0614/desktop/muduo/src/main.cc

CMakeFiles/muduo.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/main.cc > CMakeFiles/muduo.dir/src/main.cc.i

CMakeFiles/muduo.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/main.cc -o CMakeFiles/muduo.dir/src/main.cc.s

CMakeFiles/muduo.dir/src/test.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/test.cc.o: ../src/test.cc
CMakeFiles/muduo.dir/src/test.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/muduo.dir/src/test.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/test.cc.o -MF CMakeFiles/muduo.dir/src/test.cc.o.d -o CMakeFiles/muduo.dir/src/test.cc.o -c /home/muqiu0614/desktop/muduo/src/test.cc

CMakeFiles/muduo.dir/src/test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/test.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/test.cc > CMakeFiles/muduo.dir/src/test.cc.i

CMakeFiles/muduo.dir/src/test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/test.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/test.cc -o CMakeFiles/muduo.dir/src/test.cc.s

CMakeFiles/muduo.dir/src/util.cc.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/util.cc.o: ../src/util.cc
CMakeFiles/muduo.dir/src/util.cc.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/muduo.dir/src/util.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/util.cc.o -MF CMakeFiles/muduo.dir/src/util.cc.o.d -o CMakeFiles/muduo.dir/src/util.cc.o -c /home/muqiu0614/desktop/muduo/src/util.cc

CMakeFiles/muduo.dir/src/util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/util.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/desktop/muduo/src/util.cc > CMakeFiles/muduo.dir/src/util.cc.i

CMakeFiles/muduo.dir/src/util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/util.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/desktop/muduo/src/util.cc -o CMakeFiles/muduo.dir/src/util.cc.s

# Object files for target muduo
muduo_OBJECTS = \
"CMakeFiles/muduo.dir/src/Acceptor.cc.o" \
"CMakeFiles/muduo.dir/src/Buffer.cc.o" \
"CMakeFiles/muduo.dir/src/Channel.cc.o" \
"CMakeFiles/muduo.dir/src/CurrentThreadId.cc.o" \
"CMakeFiles/muduo.dir/src/DefaultPoller.cc.o" \
"CMakeFiles/muduo.dir/src/EPollPoller.cc.o" \
"CMakeFiles/muduo.dir/src/EventLoop.cc.o" \
"CMakeFiles/muduo.dir/src/EventLoopThread.cc.o" \
"CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.o" \
"CMakeFiles/muduo.dir/src/Fiber.cc.o" \
"CMakeFiles/muduo.dir/src/InetAddress.cc.o" \
"CMakeFiles/muduo.dir/src/Logger.cc.o" \
"CMakeFiles/muduo.dir/src/Poller.cc.o" \
"CMakeFiles/muduo.dir/src/Socket.cc.o" \
"CMakeFiles/muduo.dir/src/TcpConnection.cc.o" \
"CMakeFiles/muduo.dir/src/TcpServer.cc.o" \
"CMakeFiles/muduo.dir/src/Thread.cc.o" \
"CMakeFiles/muduo.dir/src/main.cc.o" \
"CMakeFiles/muduo.dir/src/test.cc.o" \
"CMakeFiles/muduo.dir/src/util.cc.o"

# External object files for target muduo
muduo_EXTERNAL_OBJECTS =

../bin/muduo: CMakeFiles/muduo.dir/src/Acceptor.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/Buffer.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/Channel.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/CurrentThreadId.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/DefaultPoller.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/EPollPoller.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/EventLoop.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/EventLoopThread.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/EventLoopThreadPool.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/Fiber.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/InetAddress.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/Logger.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/Poller.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/Socket.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/TcpConnection.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/TcpServer.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/Thread.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/main.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/test.cc.o
../bin/muduo: CMakeFiles/muduo.dir/src/util.cc.o
../bin/muduo: CMakeFiles/muduo.dir/build.make
../bin/muduo: CMakeFiles/muduo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/muqiu0614/desktop/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Linking CXX executable ../bin/muduo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/muduo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/muduo.dir/build: ../bin/muduo
.PHONY : CMakeFiles/muduo.dir/build

CMakeFiles/muduo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/muduo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/muduo.dir/clean

CMakeFiles/muduo.dir/depend:
	cd /home/muqiu0614/desktop/muduo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/muqiu0614/desktop/muduo /home/muqiu0614/desktop/muduo /home/muqiu0614/desktop/muduo/build /home/muqiu0614/desktop/muduo/build /home/muqiu0614/desktop/muduo/build/CMakeFiles/muduo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/muduo.dir/depend
