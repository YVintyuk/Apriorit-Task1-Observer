//
//  command_line.cpp
//  Observer
//
//

#include "command_line.hpp"

void notifiable_printer::notify(void* data) {
    std::cout<<(char*)data<<"\n";
};

void command_line::notify(void* data) {
    event e = *(event*)data;
    switch (e) {
        case event::mouse_in:
            std::cout<<"COLOR RED ";
            std::cout<< m_text << "\t\r" << std::flush;
            break;
        case event::mouse_out:
            std::cout<<"COLOR GREEN ";
            std::cout<< m_text << "\t\r" << std::flush;
            break;
        default:
            break;
    }
};
