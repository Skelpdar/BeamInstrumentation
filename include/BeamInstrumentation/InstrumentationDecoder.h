#ifndef INSTRUMENTATION_DECODER_H
#define INSTRUMENTATION_DECODER_H

namespace instrumentation {

	class InstrumentationDecoder : public framework::Producer{
		InstrumentationDecoder(const std::string &name, framework::Process &process) : Producer(name, process) {}

		~InstrumentationDecoder() = default;
		

		virtual void configure(framework::config:Paramters &ps);

		virtual void produce(framework::Event &event);

		virtual void onFileOpen();

		virtual void onFileClose();

		virtual void onProcessStart();

		virtual void onProcessEnd();
	}

}

#endif
