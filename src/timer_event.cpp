#pragma once

#include <functional>
#include <vector>
#include "config/constants.hpp"
#include <iostream>
#include "timer_event.hpp"

using namespace std;

TimerEvent::TimerEvent(function<void()> event) : event(event) {}
