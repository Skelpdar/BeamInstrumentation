from LDMX.Framework import ldmxcfg

p = ldmxcfg.Process('unpack') 
import sys

p.inputFiles=[sys.argv[1]]
p.outputFiles = [sys.argv[2]]

from LDMX.BeamInstrumentation.FiberTrackerDecoder import FiberTrackerDecoder

dec = FiberTrackerDecoder.FT50()

dec.input_pass_name = "raw"
dec.input_collection= "FiberTrackerFT50_raw"

p.sequence = [
        dec
]
