export module collectionsstack;
import collectionsapi;
import std;

export template<typename T>
class StackEnumerator : public IEnumerator<T> {
	std::stack<T> _stack;
	bool isfirst = true;
public:
	StackEnumerator(std::stack<T> stack) {
		_stack = stack;
	}
	bool MoveNext() override {
		if (_stack.empty()) {
			return false;
		}
		if (!isfirst) {
			_stack.pop();
		}
		isfirst = false;
		return !_stack.empty();
	}
	const T& Current() const override {
		if (_stack.empty()) {
			throw std::out_of_range("Отсутсвует текущий элемент");
		}
		return _stack.top();
	}
};

export template<typename T>
class Stack : public IEnumerable<T> {
private:
	std::stack<T> _stack;
public:
	int Count() const {
		return _stack.size();
	}
	void Push(T item) {
		_stack.push(item);
	}
	T Peek() const {
		if (_stack.empty()) {
			throw std::out_of_range("Стек пуст");
		}
		return _stack.top();
	}
	T Pop() {
		if (_stack.empty()) {
			throw std::out_of_range("Стек пуст");
		}
		T element = _stack.top();
		_stack.pop();
		return element;
	}
	std::unique_ptr<IEnumerator<T>> GetEnumerator() const override {
		return std::make_unique<StackEnumerator<T>>(_stack);
	}
};
