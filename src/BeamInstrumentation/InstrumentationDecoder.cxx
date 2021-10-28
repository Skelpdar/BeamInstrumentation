#import "BeamInstrumentation/InstrumentationDecoder.h"

namespace instrumentation {

	void InstrumentationDecoder::configure(framework::config::Parameters &ps){
		outputCollection_ = ps.getParameter<std::string>("output_collection");
		inputCollection_ = ps.getParameter<std::string>("input_collection");
	}

	void InstrumentationDecoder::produce(framework::Event &event){
		std::cout << event.getEventHeader().getEventNumber();

		std::vector<instrumentation::WRTimestampDigis> outDigis;

		WRTimestampDigis digi;
		digi.setData

		event.add(outputCollection_, outDigis);
	}

	

}

DECLARE_PRODUCER_NS(instrumentation, InstrumentationDecoder);
