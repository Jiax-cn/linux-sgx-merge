# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/linux-sgx-merge/psw/ae/aesm_service/source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/linux-sgx-merge/psw/ae/aesm_service/source/build

# Utility rule file for qe3_logic_lib.

# Include the progress variables for this target.
include bundles/ecdsa_quote_service_bundle/CMakeFiles/qe3_logic_lib.dir/progress.make

bundles/ecdsa_quote_service_bundle/CMakeFiles/qe3_logic_lib: /root/linux-sgx-merge/external/dcap_source/QuoteGeneration/build/linux/libsgx_qe3_logic.so


/root/linux-sgx-merge/external/dcap_source/QuoteGeneration/build/linux/libsgx_qe3_logic.so:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/linux-sgx-merge/psw/ae/aesm_service/source/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating /root/linux-sgx-merge/external/dcap_source/QuoteGeneration/build/linux/libsgx_qe3_logic.so"
	cd /root/linux-sgx-merge/external/dcap_source/QuoteGeneration/quote_wrapper/quote/linux && make all

qe3_logic_lib: bundles/ecdsa_quote_service_bundle/CMakeFiles/qe3_logic_lib
qe3_logic_lib: /root/linux-sgx-merge/external/dcap_source/QuoteGeneration/build/linux/libsgx_qe3_logic.so
qe3_logic_lib: bundles/ecdsa_quote_service_bundle/CMakeFiles/qe3_logic_lib.dir/build.make

.PHONY : qe3_logic_lib

# Rule to build all files generated by this target.
bundles/ecdsa_quote_service_bundle/CMakeFiles/qe3_logic_lib.dir/build: qe3_logic_lib

.PHONY : bundles/ecdsa_quote_service_bundle/CMakeFiles/qe3_logic_lib.dir/build

bundles/ecdsa_quote_service_bundle/CMakeFiles/qe3_logic_lib.dir/clean:
	cd /root/linux-sgx-merge/psw/ae/aesm_service/source/build/bundles/ecdsa_quote_service_bundle && $(CMAKE_COMMAND) -P CMakeFiles/qe3_logic_lib.dir/cmake_clean.cmake
.PHONY : bundles/ecdsa_quote_service_bundle/CMakeFiles/qe3_logic_lib.dir/clean

bundles/ecdsa_quote_service_bundle/CMakeFiles/qe3_logic_lib.dir/depend:
	cd /root/linux-sgx-merge/psw/ae/aesm_service/source/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/linux-sgx-merge/psw/ae/aesm_service/source /root/linux-sgx-merge/psw/ae/aesm_service/source/bundles/ecdsa_quote_service_bundle /root/linux-sgx-merge/psw/ae/aesm_service/source/build /root/linux-sgx-merge/psw/ae/aesm_service/source/build/bundles/ecdsa_quote_service_bundle /root/linux-sgx-merge/psw/ae/aesm_service/source/build/bundles/ecdsa_quote_service_bundle/CMakeFiles/qe3_logic_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bundles/ecdsa_quote_service_bundle/CMakeFiles/qe3_logic_lib.dir/depend
