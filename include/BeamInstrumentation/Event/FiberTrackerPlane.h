#ifndef FIBER_TRACKER_PLANE_H
#define FIBER_TRACKER_PLANE_H

#include <vector>
#include <stdint.h>

#include "TObject.h"

namespace beaminstrumentation {
	class FiberTrackerPlane {
	public:
		FiberTrackerPlane() = default;
    FiberTrackerPlane(std::vector<uint> hits): hits(hits) {} 
		~FiberTrackerPlane() = default;

		void Print(Option_t* option = "") const;
		void Clear(Option_t* option = "");
		bool operator <(const FiberTrackerPlane &rhs) const {
			return true;
		}

	private:
    std::vector<uint> hits;

		ClassDef(FiberTrackerPlane, 1);
	};
} //beaminstrumentation

#endif //FIBER_TRACKER_PLANE_H
