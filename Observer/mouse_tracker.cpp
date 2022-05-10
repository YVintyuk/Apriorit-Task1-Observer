//
//  mouse_tracker.cpp
//  Observer
//
//

#include "mouse_tracker.hpp"

void base_observer::event_loop() {
    while (!should_exit) {
        // std::cout<<"event_loop\n";
        if (should_notify()) {
            for (const auto& sub:m_subscribers) {
                sub.second(this->get_data());
            }
        }
        std::this_thread::sleep_for(m_timer);
    };
};

bool mouse_tracker::is_mouse_in() {
    CGEventRef event = CGEventCreate(NULL);
    CGPoint cursor = CGEventGetLocation(event);
                                                       
    // std::cout << "Mouse on (" << cursor.x << "," << cursor.y << ")\n";
    
    // TODO: Get window coordinates instead of 100
    if (cursor.x > 100 && cursor.y > 100) {
        return false;
    } else {
        return true;
    }
    
    // FIXME: Release event - linkage issue
    // CFRelease(event);
    return !mouse_in;
};

bool mouse_tracker::should_notify() {
    if (mouse_in != is_mouse_in()){
        if (mouse_in) {
            last_event = event::mouse_out;
        } else {
            last_event = event::mouse_in;
        }
        mouse_in = !mouse_in;
        return true;
    } else {
        return false;
    }
};

void* mouse_tracker::get_data() {
    static event buff;
    buff = last_event;
    return &buff;
};
