

from LDMX.Framework import ldmxcfg

class FiberTrackerDecoder(ldmxcfg.Producer):
    def __init__(self, name = 'FiberTrackerDecode'):
        super().__init__(f'{name}', 'beaminstrumentation::FiberTrackerDecoder', "BeamInstrumentation")
        self.name = name
        self.input_pass_name = 'raw'
        self.input_collection = ''
        self.output_collection = ''
        self.is_real_data=True

    def FT50():
        dec = FiberTrackerDecoder()
        dec.input_collection = 'FiberTrackerFT50'
        dec.output_collection = 'decodedFiberTrackerFT50'

        return dec
    
    def FT51():
        dec = FiberTrackerDecoder()
        dec.input_collection = 'FiberTrackerFT51'
        dec.output_collection = 'decodedFiberTrackerFT51'

        return dec


