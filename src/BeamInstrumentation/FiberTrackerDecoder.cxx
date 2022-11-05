#include "BeamInstrumentation/FiberTrackerDecoder.h"

namespace beaminstrumentation {

	void FiberTrackerDecoder::configure(framework::config::Parameters &ps){
		outputCollection_ = ps.getParameter<std::string>("output_collection");
		inputCollectionDownstreamHorizontal_ = ps.getParameter<std::string>("input_collection_downstream_horizontal");
		inputCollectionDownstreamVertical_ = ps.getParameter<std::string>("input_collection_downstream_vertical");
		inputCollectionUpstreamHorizontal_ = ps.getParameter<std::string>("input_collection_upstream_horizontal");
		inputCollectionUpstreamVertical_ = ps.getParameter<std::string>("input_collection_upstream_vertical");
    inputPassName_ = ps.getParameter<std::string>("input_pass_name");
	}

	void FiberTrackerDecoder::produce(framework::Event &event){
		std::cout << "\nIn FiberTrackerDecoder: " << event.getEventHeader().getEventNumber();

    const auto eventStreamDownstreamHorizontal{event.getCollection<uint8_t>( inputCollectionDownstreamHorizontal_, inputPassName_)}; //FT50

    std::vector<uint> hitsDownstreamHorizontal;
    if(eventStreamDownstreamHorizontal.size() == 40){
      for(int i = 0; i < 24; i++){
        for(int k = 0; k < 8; k++){
          if((eventStreamDownstreamHorizontal.at(16+i) >> k) & 0x1 == 1){
            hitsDownstreamHorizontal.push_back(i*8+k);
          }
        }
      }
    }
    std::cout << "\n" <<eventStreamDownstreamHorizontal.size() << "\n";

    std::vector<uint> hits;
    
    FiberTrackerPlane out(hitsDownstreamHorizontal, hits, hits,  hits); // Order  hitsDownstreamHorizontal, hitsDownstreamVertical, hitsUpstreamHorizontal, hitsUpstreamVertical)

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

} // namespace beaminstrumentation

DECLARE_PRODUCER_NS(beaminstrumentation, FiberTrackerDecoder);
