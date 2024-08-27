#pragma once

#include "timer_event.hpp"

#include <functional>
#include <iostream>
#include <vector>

#include "config/constants.hpp"

using namespace std;

TimerEvent::TimerEvent(function<void()> event) : event(event) {}
