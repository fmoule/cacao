
#include "numeric/NumUtils.h"

namespace cacao {

    int getNbDigits(const long value) {
        long lgValue = (value < 0 ? -value : value);
        int nbDigits = 0;
        while (lgValue > 0) {
            nbDigits++;
            lgValue = (lgValue - (lgValue % 10)) / 10;
        }
        return nbDigits;
    }
}
