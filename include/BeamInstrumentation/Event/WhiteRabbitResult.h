#ifndef WHITE_RABBIT_RESULT_H
#define WHITE_RABBIT_RESULT_H

#include <vector>
#include <stdint.h>

#include "TObject.h"

namespace beaminstrumentation {
	class WhiteRabbitResult {
	public:
		WhiteRabbitResult() = default;
		WhiteRabbitResult(uint32_t deltaTTrigger, uint32_t deltaTDownstreamHorizontal, uint32_t deltaTDownstreamVertical) : deltaTTrigger(deltaTTrigger), deltaTDownstreamHorizontal(deltaTDownstreamHorizontal), deltaTDownstreamVertical(deltaTDownstreamVertical) {};
		~WhiteRabbitResult() = default;

		void Print(Option_t* option = "") const {};
		void Clear(Option_t* option = "") {};
		bool operator <(const WhiteRabbitResult &rhs) const {
			return true;
		}

	private:
    //Order in serialized event data:
    uint32_t deltaTTrigger; //deltaT between TS event and scintillator plate trigger
    uint32_t deltaTDownstreamHorizontal; //deltaT between TS event and downstream horizontal fiber tracker
    uint32_t deltaTDownstreamVertical; //deltaT between TS event and downstream vertical fiber tracker
    
    uint32_t deltaTUpstreamHorizontal;
    uint32_t deltaTUpstreamVertical;
    uint32_t deltaTLowPressure;
    uint32_t deltaTHighPressure;
    uint64_t deltaTSpillStart;
    uint32_t spillNumber;
    

    /*
     * Possible additions
     */
    //TS timestamp in atomic time
    //The offsets used in alignment
    //deltaTs to the second closest events, to see systematic effects
    //Actual number of raw triggers in spill
    //Actual number of fiber tracker events in spill
    //Number of cherenkov hits etc. in spill

		ClassDef(WhiteRabbitResult, 1);
	};
} // namespace beaminstrumentation

#endif //WHITE_RABBIT_RESULT_H
