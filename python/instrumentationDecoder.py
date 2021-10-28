from LDMX.Framework import ldmxcfg

class InstrumentationDecoder(ldmxcfg.Producer):
	def __init__(self, filename, name = "InstrumentationDecoder"):
		super().__init__(f'{name}', 'instrumentation::InstrumentationDecoder', "BeamInstrumentation")
		self.name = name

	def WR(filename):
		dec = InstrumentationDecoder(filename, 'WR')
		dec.input_collection = "WRTimestampTag"
		dec.output_collection = "decodedWRTimestampTag"
		return dec

	"""	
	def XBPF(filename):
		dec = InstrumentationDecoder(filename, 'XBPF')
		return dec
	"""

