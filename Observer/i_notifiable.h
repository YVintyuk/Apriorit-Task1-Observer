//
//  i_notifiable.h
//  Observer
//
//

#ifndef i_observable_h
#define i_observable_h

class i_notifiable {
public:
    virtual void notify(void* data) {};
};

#endif /* i_observable_h */
