
class IFillable {
	public:
		virtual IFillable() {}
		virtual ~IFillable() {}
		virtual bool ParseJson(std::string[] json);
};