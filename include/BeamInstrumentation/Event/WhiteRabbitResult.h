#ifndef WHITE_RABBIT_RESULT_H
#define WHITE_RABBIT_RESULT_H

#include <vector>
#include <stdint.h>

#include "TObject.h"

namespace beaminstrumentation {
	class WhiteRabbitResult {
	public:
		WhiteRabbitResult() = default;
		~WhiteRabbitResult() = default;

		void Print(Option_t* option = "") const {};
		void Clear(Option_t* option = "") {};
		bool operator <(const WhiteRabbitResult &rhs) const {
			return true;
		}

	private:
    /*
    uint64_t deltaTFT50
    uint64_t deltaTFT51
    uint64_t deltaTFT41
    uint64_t deltaTFT42
    uint64_t deltaTlowpressure
    uint64_t deltaThighpressure
    uint64_t deltaTtrigger
    uint64_t deltaTspill

    uint32_t spillNumber;
    */

    //TS timestamp

    //offsets from alignment
    
    //deltaTs to the second closest events, to see systematic effects
    
    //Actual number of raw triggers in spill
    
    //Actual number of fiber tracker events in spill
    
    //Number of cherenkov hits etc. in spill

		ClassDef(WhiteRabbitResult, 1);
	};
} // namespace beaminstrumentation

#endif //WHITE_RABBIT_RESULT_H
