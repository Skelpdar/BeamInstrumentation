# BeamInstrumentation
ldmx-sw submodule for test beam instrumentation

# How to build submodule
Following the same procedure as for the TrigScint module.

In the top ldmx-sw CMakeLists.txt add:
add\_subdirectory(BeamInstrumentation ${CMAKE\_BINARY\_DIR}/BeamInstrumentationEvent)

and in the if(BUILD\_ALL OR BUILD\_RECON\_ONLY) conditional add:
add\_subdirectory(BeamInstrumentation)

Then comes the hacky part I have yet to understand. Build the project once, and some new files will appear in ../Framework/

In ../Framework/include/Framework/EventDef.h add the lines

\#include "BeamInstrumentation/Event/FiberTracker.h"
\#include "BeamInstrumentation/Event/WhiteRabbitResult.h"

In ../Framework/include/Framework/EventLinkDef.h add the lines

\#pragma link C++ namespace beaminstrumentation;
\#pragma link C++ class beaminstrumentation::FiberTracker+;
\#pragma link C++ class std::vector< ldmx::FiberTracker >+;
\#pragma link C++ class beaminstrumentation::WhiteRabbitResult+;

Now you build the project again, for real.
