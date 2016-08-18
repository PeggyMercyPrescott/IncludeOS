// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef KERNEL_SYSCALLS_HPP
#define KERNEL_SYSCALLS_HPP

#include <sys/unistd.h>

extern "C" {
  int  kill(pid_t pid, int sig);
  void panic(const char* why) __attribute__((noreturn));
  void default_exit() __attribute__((noreturn));
  
  // used to set a message that will be printed on crash the message is to 
  // be contextual helping to identify the reason for crashes
  // Example: copy HTTP requests into buffer during stress or malformed request 
  // testing if server crashes we can inspect the HTTP request to identify which 
  // one caused the crash
  char*  get_crash_context_buffer();
  size_t get_crash_context_length();
}
extern void print_backtrace();

#define SET_CRASH_CONTEXT(X,...)  snprintf( \
      get_crash_context_buffer(), get_crash_context_length(), \
      X, ##__VA_ARGS__);

#endif //< KERNEL_SYSCALLS_HPP
