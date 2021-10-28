#ifndef INSTRUMENTATION_DECODER_H
#define INSTRUMENTATION_DECODER_H

#include "Framework/Configure/Parameters.h"
#include "Framework/Event.h"
#include "Framework/EventProcessor.h"
#include "BeamInstrumentation/Event/WRTimestampDigis.h"

namespace instrumentation {

	class InstrumentationDecoder : public framework::Producer{
	public:
		InstrumentationDecoder(const std::string &name, framework::Process &process) : Producer(name, process) {};

		~InstrumentationDecoder() = default;
		

		virtual void configure(framework::config::Parameters &ps);

		virtual void produce(framework::Event &event);

		virtual void onFileOpen();

		virtual void onFileClose();

		virtual void onProcessStart();

		virtual void onProcessEnd();
	
	private:
		std::string inputCollection_;
		std::string outputCollection_;
		
	};

}

#endif
