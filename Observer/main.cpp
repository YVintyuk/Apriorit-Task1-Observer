//
//  main.cpp
//  Observer
//
//  Created by Yuliana Vintyuk on 09.05.22.
//

#include <iostream>
#include <chrono>
#include <thread>
#include "command_line.hpp"
#include "mouse_tracker.hpp"

using namespace std::chrono_literals;

int main(int argc, const char * argv[]) {
    // insert code here...
    mouse_tracker obs(100ms);
    command_line cli("Hello World");
    obs.subscribe(&cli,
                  [&cli](void* data){cli.notify(data);});
    std::this_thread::sleep_for(20s);
    return 0;
}
