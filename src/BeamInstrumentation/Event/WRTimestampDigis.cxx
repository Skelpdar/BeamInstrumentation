#include "BeamInstrumentation/Event/WRTimestampDigis.h"

ClassImp(instrumentation::WRTimestampDigis)

namespace instrumentation {

	void WRTimestampDigis::Print(Option_t* option) const {
		std::cout << "This is a white rabbit timestamp :)" << std::endl;
	}

	void WRTimestampDigis::Clear(Option_t* option) {}

}
