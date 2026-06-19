import std;


class ICounter
{
public:
	virtual void increment() = 0;
	virtual void reset() = 0;
	virtual int getValue() const = 0;
	virtual bool IsLimitedReached() const = 0;
	virtual std::string getType() const = 0;
	virtual ~ICounter() = default;
};


class BoundedCounter final : public ICounter {
private:
	int value_ = 0;
	const int max_value_;
public:
	explicit BoundedCounter(int max_value) : max_value_(max_value) {}
	void increment() override {
		if (value_ < max_value_) {
			++value_;
		}
	}
	void reset() override {
		value_ = 0;
	}
	int getValue() const override {
		return value_;
	}
	bool IsLimitedReached() const override {
		return value_ == max_value_;
	}
	std::string getType() const override {
		return "BoundedCounter(max=" + std::to_string(max_value_) + ")";
	}
};


class CyclicCounter final : public ICounter
{
	int value = 0;
	int max;

public :
	explicit CyclicCounter(int max) : max(max) {}

	int getValue() const override {
		return value;
	}
	void reset() override {
		value = 0;
	}
	void increment() override
	{
		if (IsLimitedReached())
			value = 0;
		else
			value++;
	}
	bool IsLimitedReached() const override {
		return value == max;
	}
	std::string getType() const override
	{
		return "CyclicCounter(max=" + std::to_string(max) + ")";
	}
};

class StepCounter final : public ICounter {
private:
	int _value = 0;
	int _step, _maxValue;
public:
	explicit StepCounter(int max, int step) : _step(step), _maxValue(max) {}


	void increment() override {
		if (_value < _maxValue) {
			_value = std::min(_value + _step, _maxValue);
		}
	}
	void reset() override {
		_value = 0;
	}
	int getValue() const override {
		return _value;
	}
	bool IsLimitedReached() const override {
		return _value == _maxValue;
	}
	std::string getType() const override {
		return "StepCounter(max=" + std::to_string(_maxValue) + ", step=" + std::to_string(_step) + ")";
 	}
};



int main() {
	BoundedCounter bounded_counter(5);
	std::println("{}", bounded_counter.getType());
	for (int i = 0; i < 7; ++i) {
		bounded_counter.increment();
		std::println("Значение: {}, лимит достигнут: {}", bounded_counter.getValue(), bounded_counter.IsLimitedReached());
	}
	bounded_counter.reset();
	std::println("После reset: {}", bounded_counter.getValue());

	std::println("");

	CyclicCounter cyclic_counter(5);
	std::println("{}", cyclic_counter.getType());
	for (int i = 0; i < 7; ++i) {
		cyclic_counter.increment();
		std::println("Значение: {}, лимит достигнут: {}", cyclic_counter.getValue(), cyclic_counter.IsLimitedReached());
	}
	cyclic_counter.reset();
	std::println("После reset: {}", cyclic_counter.getValue());

	std::println("");

	StepCounter step_counter(10, 3);
	std::println("{}", step_counter.getType());
	for (int i = 0; i < 5; ++i) {
		step_counter.increment();
		std::println("Значение: {}, лимит достигнут: {}", step_counter.getValue(), step_counter.IsLimitedReached());
	}
	step_counter.reset();
	std::println("После reset: {}", step_counter.getValue());

	return 0;
}
