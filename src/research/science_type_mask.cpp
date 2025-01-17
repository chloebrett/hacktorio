#include "science_type_mask.hpp"

#include <vector>

#include "science_type.hpp"

std::vector<ScienceType> fromMask(int mask) {
    std::vector<ScienceType> scienceTypes;
    for (int i = 0; i < 8; i++) {
        if (mask & (1 << i)) {
            scienceTypes.push_back(static_cast<ScienceType>(i));
        }
    }
    return scienceTypes;
}
