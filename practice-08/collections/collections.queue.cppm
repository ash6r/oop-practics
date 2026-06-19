export module collectionsqueue;
import collectionsapi;
import std;

export template<typename T>
class QueueEnumerator : public IEnumerator<T> {
	std::queue<T> _queue;
	bool isfirst = true;
public:
	QueueEnumerator(std::queue<T> queue) {
		_queue = queue;
	}
	bool MoveNext() override {
		if (_queue.empty()) {
			return false;
		}
		if (!isfirst) {
			_queue.pop();
		}
		isfirst = false;
		return !_queue.empty();
	}
	const T& Current() const override {
		if (_queue.empty()) {
			throw std::out_of_range("Отсутсвует текущий элемент");
		}
		return _queue.front();
	}

};


export template<typename T>
class Queue : public IEnumerable<T> {
private:
	std::queue<T> _queue;
public:
	int Count() const
	{
		return _queue.size();
	}
	T Peek() const {
		if (_queue.empty()) {
			throw std::out_of_range("Очередь пуста");
		}
		return _queue.front();
	}
	T Dequeue() {
		if (_queue.empty()) {
			throw std::out_of_range("Очередь пуста");
		}
		T element = _queue.front();
		_queue.pop();
		return element;
	}
	void Enqueue(T item)
	{
		_queue.push(item);
	}
	std::unique_ptr<IEnumerator<T>> GetEnumerator() const override {
		return std::make_unique<QueueEnumerator<T>>(_queue);
	}
};
