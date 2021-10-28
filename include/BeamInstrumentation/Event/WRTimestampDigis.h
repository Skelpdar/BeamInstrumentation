#ifndef WR_TIMESTAMP_DIGIS_H
#define WR_TIMESTAMP_DIGIS_H

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

		std::vector<uint32_t> getData() {return data;};

	private:
		std::vector<uint32_t> data;

		ClassDef(WRTimestampDigis, 1);
	};
}

#endif
