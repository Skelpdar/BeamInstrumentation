from LDMX.Framework import ldmxcfg

p = ldmxcfg.Process('unpack') 
import sys

p.inputFiles=[sys.argv[1]]
p.outputFiles = [sys.argv[2]]

from LDMX.BeamInstrumentation.FiberTrackerDecoder import FiberTrackerDecoder

dec = FiberTrackerDecoder.decode()

p.sequence = [
        dec
]
