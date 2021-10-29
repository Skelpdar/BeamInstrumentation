from LDMX.Framework import ldmxcfg
from LDMX.BeamInstrumentation.instrumentationDecoder import InstrumentationDecoder
p = ldmxcfg.Process( "test" )

#Decode a White Rabbit timestamp binary file
decWR = InstrumentationDecoder.WR("file")
decWR.input_collection="Events"
decWR.input_pass_name="pack"
decWR.output_collection="WRTimestampsDigi"
p.maxEvents = 10
p.logFrequency = 1
p.termLogLevel = 0
p.outputFiles = ["wrdigisTest.root"]
p.sequence.append( decWR )
