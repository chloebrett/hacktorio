#include "timer_event.hpp"

#include <functional>
#include <iostream>
#include <vector>

#include "config/constants.hpp"

TimerEvent::TimerEvent(std::function<void()> event) : event(event) {}
