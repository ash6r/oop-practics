export module collectionshashset;
import collectionsapi;
import std;

export template<typename T>
class HashSetEnumerator : public IEnumerator<T> {
	typename std::unordered_set<T>::const_iterator _iter;
	typename std::unordered_set<T>::const_iterator _end;
	bool isfirst = true;
public:
	HashSetEnumerator(const std::unordered_set<T>& set) {
		_iter = set.begin();
		_end = set.end();
	}
	bool MoveNext() override {
		if (isfirst) {
			isfirst = false;
			return _iter != _end;
		}
		_iter++;
		return _iter != _end;
	}

	const T& Current() const override {
		if (_iter == _end) {
			throw std::out_of_range("Конец множества");
		}
		return *_iter;
	}
};

export template <typename T, typename Hash = std::hash<T>, typename Equal = std::equal_to<T>>
class HashSet : public ICollection<T> {
	std::unordered_set<T, Hash, Equal> _set;
public:
	HashSet() = default;
	int Count() const override {
		return _set.size();
	}
	void Add(T item) override {
		_set.insert(item);
	}
	void Clear() override {
		_set.clear();
	}
	bool Contains(T item) const override {
		return _set.contains(item);
	}
	bool Remove(T item) override {
		if (Contains(item)) {
			_set.erase(item);
			return true;
		}
		return false;
	}
	int Capacity() const {
		return _set.bucket_count();
	}
	void SetCapacity(int capacity) {
		_set.reserve(capacity);
	}
	std::unique_ptr<IEnumerator<T>> GetEnumerator() const override {
		return std::make_unique <HashSetEnumerator<T>>(_set);
	}
};
