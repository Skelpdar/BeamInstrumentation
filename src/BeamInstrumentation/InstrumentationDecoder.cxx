#include "BeamInstrumentation/InstrumentationDecoder.h"

namespace instrumentation {

	void InstrumentationDecoder::configure(framework::config::Parameters &ps){
		outputCollection_ = ps.getParameter<std::string>("output_collection");
		inputCollection_ = ps.getParameter<std::string>("input_collection");
	}

	void InstrumentationDecoder::produce(framework::Event &event){
		std::cout << "In InstrumentationDecoder: " << event.getEventHeader().getEventNumber();

		std::vector<instrumentation::WRTimestampDigis> outDigis;

		//uint8_t tIDword = eventStream.at(pos);


		WRTimestampDigis digi;
		std::vector<uint32_t> dummyData = {(uint32_t)event.getEventHeader().getEventNumber()};
		digi.setData(dummyData);
		outDigis.push_back(digi);

		event.add(outputCollection_, outDigis);
	}

	void InstrumentationDecoder::onFileOpen() {
		ldmx_log(debug) << "Opening file!";

		return;
	}	

	void InstrumentationDecoder::onFileClose() {
		ldmx_log(debug) << "Closing file!";

		return;
	}

	void InstrumentationDecoder::onProcessStart() {
		ldmx_log(debug) << "Process start!";

		return;
	}

	void InstrumentationDecoder::onProcessEnd(){
		ldmx_log(debug) << "Process ends!";

		return;
	}

}

DECLARE_PRODUCER_NS(instrumentation, InstrumentationDecoder);
