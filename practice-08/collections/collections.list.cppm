export module collectionslist;
import collectionsapi;
import std;

export template<typename T>
class ListEnumerator : public IEnumerator<T> {
private:
	const std::vector<T>& _vec;
	int _index = -1;
public:
	ListEnumerator(const std::vector<T>& vec) : _vec(vec){ }
	bool MoveNext() override {
		if (_index < static_cast<int>(_vec.size()) - 1)
		{
			_index++;
			return true;
		}
		return false;
	}
	 const T& Current() const override {
		return _vec[_index];
	}
};


export template<typename T>
class List :public ICollection<T> {
private:
	std::vector<T> _collection;
public:
	List() {}
	std::unique_ptr<IEnumerator<T>> GetEnumerator() const override {
		return std::make_unique <ListEnumerator<T>>(_collection);
	}
	int Count()const override {
		return _collection.size();
	}
	void Add(T item)override {
		_collection.push_back(item);
	}
	void Clear()override {
		_collection.clear();
	}
	bool Contains(T item) const override {
		return std::find(_collection.begin(), _collection.end(), item) != _collection.end();
	}
	bool Remove(T item) override {
		auto it = std::find(_collection.begin(), _collection.end(), item);
		if (it != _collection.end()) {
			_collection.erase(it);
			return true;
		}
		return false;
	}
	int Capacity() const {
		return _collection.capacity();
	}
	void SetCapacity(int capacity) {
		_collection.reserve(capacity);
	}
	T operator[](int idx) const {
		if (idx < 0 || idx >= static_cast<int>(_collection.size())) {
			throw std::out_of_range("Индекс вышел за границы");
		}
		return _collection[idx];
	}
	T& operator[](int idx) {
		if (idx < 0 || idx >= static_cast<int>(_collection.size())) {
			throw std::out_of_range("Индекс вышел за границы");
		}
		return _collection[idx];
	}
	void Insert(int idx, T item) {
		if (idx < 0 || idx > static_cast<int>(_collection.size())) {
			throw std::out_of_range("Индекс вышел за границы");
		}
		_collection.insert(_collection.begin() + idx, item);
	}
	void RemoveAt(int idx) {
		if (idx < 0 || idx >= static_cast<int>(_collection.size())) {
			throw std::out_of_range("Индекс вышел за границы");
		}
		_collection.erase(_collection.begin() + idx);
	}
};
