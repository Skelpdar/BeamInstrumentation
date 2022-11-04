#include "BeamInstrumentation/FiberTrackerDecoder.h"

namespace beaminstrumentation {

	void FiberTrackerDecoder::configure(framework::config::Parameters &ps){
		outputCollection_ = ps.getParameter<std::string>("output_collection");
		inputCollection_ = ps.getParameter<std::string>("input_collection");
    inputPassName_ = ps.getParameter<std::string>("input_pass_name");
	}

	void FiberTrackerDecoder::produce(framework::Event &event){
		std::cout << "In FiberTrackerDecoder: " << event.getEventHeader().getEventNumber();

    const auto eventStream{event.getCollection<uint32_t>( inputCollection_, inputPassName_)};

    std::vector<uint> hits;
    hits.push_back((uint)eventStream.at(0));
    
    FiberTrackerPlane out(hits);

		//uint8_t tIDword = eventStream.at(pos);

		//WRTimestampDigis digi;
		//std::vector<uint32_t> dummyData = {(uint32_t)event.getEventHeader().getEventNumber()};
		//uint32_t dummyData = (uint32_t)event.getEventHeader().getEventNumber();
		//digi.setSeconds(dummyData);
		//outDigis.push_back(digi);

		event.add(outputCollection_, out);
	}

	void FiberTrackerDecoder::onFileOpen() {
		ldmx_log(debug) << "FiberTrackerDecoder Opening file!";

		return;
	}	

	void FiberTrackerDecoder::onFileClose() {
		ldmx_log(debug) << "FiberTrackerDecoder Closing file!";

		return;
	}

	void FiberTrackerDecoder::onProcessStart() {
		ldmx_log(debug) << "FiberTrackerDecoder Process start!";

		return;
	}

	void FiberTrackerDecoder::onProcessEnd(){
		ldmx_log(debug) << "FiberTrackerDecoder Process ends!";

		return;
	}

} // beaminstrumentation

DECLARE_PRODUCER_NS(beaminstrumentation, FiberTrackerDecoder);
