//
//  command_line.hpp
//  Observer
//
//

#ifndef command_line_hpp
#define command_line_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "i_notifiable.h"
#include "events.h"

class notifiable_printer: public i_notifiable {
public:
    void notify(void* data) override;
};

class command_line: public i_notifiable {
    std::string m_text;
    enum colors {
        red, green, yellow
    };
    colors m_current_color;
    bool m_is_active = false;
public:
    command_line(std::string text): m_text(text) {
        m_current_color = colors::green;
        std::cout << m_text << "\t\r" << std::flush;
    }
    void notify(void* data);
};


#endif /* command_line_hpp */
