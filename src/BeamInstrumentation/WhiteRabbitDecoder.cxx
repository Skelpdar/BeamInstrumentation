#include "BeamInstrumentation/WhiteRabbitDecoder.h"

namespace beaminstrumentation {
  
	void WhiteRabbitDecoder::configure(framework::config::Parameters &ps){
		outputCollection_ = ps.getParameter<std::string>("output_collection");
		inputCollection_ = ps.getParameter<std::string>("input_collection");
    inputPassName_ = ps.getParameter<std::string>("input_pass_name");
	}

	void WhiteRabbitDecoder::produce(framework::Event &event){
		std::cout << "\nIn WhiteRabbitDecoder: " << event.getEventHeader().getEventNumber();

    const auto eventStream{event.getCollection<uint32_t>( inputCollection_, inputPassName_)}; 
   
    uint32_t deltaTTrigger = eventStream.at(0); 
    uint32_t deltaTDownstreamHorizontal = eventStream.at(1); 
    uint32_t deltaTDownstreamVertical = eventStream.at(2); 
    std::cout << std::endl << deltaTTrigger << " " << deltaTDownstreamHorizontal << " " << deltaTDownstreamVertical << std::endl;

    uint32_t deltaTUpstreamHorizontal = eventStream.at(3);
    uint32_t deltaTUpstreamVertical = eventStream.at(4);
    uint32_t deltaTLowPressure = eventStream.at(5);
    uint32_t deltaTHighPressure = eventStream.at(6);
    uint32_t deltaTSpillStartms = eventStream.at(7);
    uint32_t deltaTSpillStartls = eventStream.at(8);
    //int64_t deltaTSpillStart;
    uint32_t spillNumber = eventStream.at(9);

    WhiteRabbitResult out(deltaTTrigger, deltaTDownstreamHorizontal, deltaTDownstreamVertical); 


		event.add(outputCollection_, out);
	}

  
	void WhiteRabbitDecoder::onFileOpen() {
		ldmx_log(debug) << "WhiteRabbitDecoder Opening file!";

		return;
	}	

	void WhiteRabbitDecoder::onFileClose() {
		ldmx_log(debug) << "WhiteRabbitDecoder Closing file!";

		return;
	}

	void WhiteRabbitDecoder::onProcessStart() {
		ldmx_log(debug) << "WhiteRabbitDecoder Process start!";

		return;
	}

	void WhiteRabbitDecoder::onProcessEnd(){
		ldmx_log(debug) << "WhiteRabbitDecoder Process ends!";

		return;
	}
  

} // namespace beaminstrumentation

DECLARE_PRODUCER_NS(beaminstrumentation, WhiteRabbitDecoder);
