import std;
import collectionslist;
import collectionshashset;
import collectionsdictionary;
import collectionsstack;
import collectionsqueue;

void DictionaryTest() {
	std::println("Тест Dictionary");
	Dictionary<std::string, int> d;
	d.Add({ "apple", 1 });
	d.Add({ "banana", 2 });
	d.Add({ "cherry", 3 });
	std::println("[Add/Count] Добавлено 3 элемента: {}", d.Count());
	std::println("[Contains] 'apple': {}", d.Contains({ "apple",1 }));
	std::println("[Remove] Удаление 'banana': {}", d.Remove({ "banana",2 }));
	d["apple"] = 4;
	std::println("[opeator[]] Значение 'apple': {}", d["apple"]);
	std::println("Old capacity: {}", d.Capacity());
	d.SetCapacity(15);
	std::println("New capacity: {}", d.Capacity());
	auto enumerator = d.GetEnumerator();
	while (enumerator->MoveNext()) {
		std::println("[Enumerator] {} -> {}", enumerator->Current().first, enumerator->Current().second);
	}
	d.Clear();
	std::println("[Clear] Count после Clear: {} ", d.Count());
}

void ListsTest() {
	std::println("Тест List");
	List<int> test;
	test.Add(5);
	test.Add(10);
	test.Add(12);
	std::println("Count = {}, Contains(10) = {}, Capacity = {}", test.Count(), test.Contains(10), test.Capacity());
	test[1] = 13;
	std::println("test[1]: {}", test[1]);
	test.Remove(5);
	test.RemoveAt(0);
	test.Insert(1, 18);
	std::println("Count = {}", test.Count());
	test.SetCapacity(10);
	std::println("New capacity = {}", test.Capacity());

	auto enumerator = test.GetEnumerator();
	while (enumerator->MoveNext()) {
		std::println("[Enumerator] {}", enumerator->Current());
	}
	test.Clear();
	std::println("Count после Clear: {}", test.Count());
}

void HashSetTest() {
	std::println("Тест HashSet");
	HashSet<int> set;
	set.SetCapacity(10);
	std::println("Ёмкость (bucket_count): {}", set.Capacity());
	set.Add(5);
	set.Add(10);
	set.Add(15);
	set.Add(10);
	std::println("Кол-во элементов после Add: {}", set.Count());
	std::println("Содержит 10?: {}", set.Contains(10));
	std::println("Содержит 20?: {}", set.Contains(20));
	std::println("Удаление 10: {}", set.Remove(10));
	std::println("Кол-во: {}", set.Count());
	std::println("Элементы мн-ва через итератор: ");
	auto enumerator = set.GetEnumerator();
	while (enumerator->MoveNext()) {
		std::println("[Enumerator] {}", enumerator->Current());
	}
	set.Clear();
	std::println("Count после Clear: {}", set.Count());
}

void StackTest() {
	std::println("Тест Stack");
	Stack<int> stack;
	std::println("Начальный размер: {}", stack.Count());

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);

	std::println("Count после добавления: {}", stack.Count());
	std::println("Верхний элемент: {}", stack.Peek());

	std::println("Удаляемый элемент: {}", stack.Pop());

	auto enumerator = stack.GetEnumerator();
	while (enumerator->MoveNext()) {
		std::println("[Enumerator] {}", enumerator->Current());
	}
}


void QueueTest() {
	std::println("Тест Queue");
	Queue<int> queue;
	std::println("Начальное количество:{}", queue.Count());
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);

	std::println("Count после добавления: {}", queue.Count());
	std::println("первый элемент:{}", queue.Peek());

	std::println("удаляемый элемент: {}", queue.Dequeue());

	auto enumerator = queue.GetEnumerator();
	while (enumerator->MoveNext()) {
		std::println("[Enumerator] {}", enumerator->Current());
	}

}

int main() {
	DictionaryTest();
	std::println("");
	ListsTest();
	std::println("");
	HashSetTest();
	std::println("");
	StackTest();
	std::println("");
	QueueTest();
	return 0;
};
