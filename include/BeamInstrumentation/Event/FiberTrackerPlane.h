#ifndef FIBER_TRACKER_PLANE_H
#define FIBER_TRACKER_PLANE_H

#include <vector>
#include <stdint.h>
#include <string>

#include "TObject.h"

namespace beaminstrumentation {
	class FiberTrackerPlane {
	public:
		FiberTrackerPlane() = default;
    FiberTrackerPlane(std::vector<uint> hitsDownstreamHorizontal, std::vector<uint> hitsDownstreamVertical, std::vector<uint> hitsUpstreamHorizontal, std::vector<uint> hitsUpstreamVertical): 
      hitsDownstreamHorizontal(hitsDownstreamHorizontal), hitsDownstreamVertical(hitsDownstreamVertical), hitsUpstreamHorizontal(hitsUpstreamHorizontal), hitsUpstreamVertical(hitsUpstreamVertical) {} 
		~FiberTrackerPlane() = default;

		void Print(Option_t* option = "") const {};
		void Clear(Option_t* option = "") {};
		bool operator <(const FiberTrackerPlane &rhs) const {
			return true;
		}

	private:
    std::vector<uint> hitsDownstreamHorizontal; //FT50
    std::vector<uint> hitsDownstreamVertical; //FT51 
    std::vector<uint> hitsUpstreamHorizontal; //FT41
    std::vector<uint> hitsUpstreamVertical; //FT42

		ClassDef(FiberTrackerPlane, 1);
	};
} // namespace beaminstrumentation

#endif //FIBER_TRACKER_PLANE_H
