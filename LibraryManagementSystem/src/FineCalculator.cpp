
#include "../include/FineCalculator.h"

double FineCalculator::calculateFine(int lateDays) {
    if(lateDays <= 0)
        return 0;

    return lateDays * 10;
}
