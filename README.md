# BeamInstrumentation
ldmx-sw submodule for test beam instrumentation

# Build Instructions
Following the same procedure as for the TrigScint module.

In the top ldmx-sw CMakeLists.txt add:
```
add_subdirectory(BeamInstrumentation ${CMAKE_BINARY_DIR}/BeamInstrumentationEvent)
```

and in the if(BUILD_ALL OR BUILD_RECON_ONLY) conditional add:
```
add_subdirectory(BeamInstrumentation)
```
Then comes the hacky part I have yet to understand. Build the project once, and some new files will appear in Framework/

In Framework/include/Framework/EventDef.h add the lines
```
#include "BeamInstrumentation/Event/FiberTracker.h"
#include "BeamInstrumentation/Event/WhiteRabbitResult.h"
```

In Framework/include/Framework/EventLinkDef.h add the lines
```
#pragma link C++ namespace beaminstrumentation;
#pragma link C++ class beaminstrumentation::FiberTracker+;
#pragma link C++ class std::vector< ldmx::FiberTracker >+;
#pragma link C++ class beaminstrumentation::WhiteRabbitResult+;
```
Now build the project again.
