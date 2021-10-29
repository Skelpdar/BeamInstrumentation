#ifndef WR_TIMESTAMP_DIGIS_H
#define WR_TIMESTAMP_DIGIS_H

#include <vector>
#include <stdint.h>
#include <iostream>

#include "TObject.h"

namespace instrumentation {
	class WRTimestampDigis {
	public:
		WRTimestampDigis() = default;
		~WRTimestampDigis() = default;

		void Print(Option_t* option = "") const;
		void Clear(Option_t* option = "");
		bool operator <(const WRTimestampDigis &rhs) const {
			return true;
		}

		uint32_t getSeconds() {return seconds;};
		void setSeconds(uint32_t s) {seconds = s;};

		uint32_t getCoarse() {return coarse;};
		uint32_t setCoarse(uint32_t c) {coarse = c;};

		uint32_t getFrac() {return frac;};
		uint32_t setFrac(uint32_t f) {frac = f;};

		void setData(uint32_t s, uint32_t c, uint32_t f) {seconds=s; coarse=c; frac=f;};

	private:
		uint32_t seconds;
		uint32_t coarse;
		uint32_t frac;

		ClassDef(WRTimestampDigis, 1);
	};
}

#endif
