export module collectionsapi;
import std;

export template<typename T>
class IEnumerator {
public:
	virtual bool MoveNext() = 0;
	virtual const T& Current() const = 0;
	virtual ~IEnumerator() = default;
};

export template<typename T>
class IEnumerable {
public:
	virtual std::unique_ptr<IEnumerator<T>> GetEnumerator() const = 0;
	virtual ~IEnumerable() = default;
};

export template<typename T>
class ICollection : public IEnumerable<T> {
public:
	virtual int Count()const = 0;
	virtual void Add(T item) = 0;
	virtual void Clear() = 0;
	virtual bool Contains(T item)const = 0;
	virtual bool Remove(T item) = 0;
	virtual ~ICollection() = default;
};