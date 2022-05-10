//
//  mouse_tracker.hpp
//  Observer
//
//

#ifndef mouse_tracker_hpp
#define mouse_tracker_hpp

#include <stdio.h>
#include <chrono>
#include <map>
#include <thread>
#include <iostream>

#include <CoreGraphics/CGEvent.h>

#include "i_observer.h"
#include "events.h"

class base_observer: public i_observer {
    std::chrono::milliseconds m_timer{1000};
    std::thread m_notification_thread;
    bool should_exit = false;
    std::map<void*, std::function<void (void*)>> m_subscribers;
    void event_loop();
protected:
    virtual bool should_notify() {
        return false;
    };
    virtual void* get_data() {
        return nullptr;
    };
public:
    void subscribe(void* key, std::function<void (void*)>callback) {
        m_subscribers[key] = callback;
    };
    base_observer(std::chrono::milliseconds _timer):m_timer(_timer) {
        m_notification_thread=std::thread(&base_observer::event_loop, this);
    };
    ~base_observer(){
        should_exit = true;
        m_notification_thread.join();
    };
};

class always_true_observer: public base_observer {
    const char* buff = "true obs";
public:
    always_true_observer(std::chrono::milliseconds _timer):base_observer(_timer) {};
protected:
    bool should_notify() override {
        return true;
    };
    void* get_data() override{
        return (void*) buff;
    };
};

class mouse_tracker: public base_observer {
    std::pair<int, int>window_top_left;
    std::pair<int, int>window_right_bottom;
    bool mouse_in = false;
    event last_event;
    bool is_mouse_in();
public:
    mouse_tracker(std::chrono::milliseconds _timer): base_observer(_timer) {};
protected:
    bool should_notify() override;
    
    void* get_data() override;
};

#endif /* mouse_tracker_hpp */
