//
//  i_observer.h
//  Observer
//
//

#ifndef i_observer_h
#define i_observer_h
#include <chrono>
#include <functional>

class i_observer {
public:
    virtual void subscribe(void* key, std::function<void (void*)>callback) {}
};

#endif /* i_observer_h */
