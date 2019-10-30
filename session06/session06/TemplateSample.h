#ifndef TEMPLATE_SAMPLE_H
#define TEMPLATE_SAMPLE_H

//struct intPoint {
//	int X;
//	int Y;
//};
//struct Point<int> {
//	int X;
//	int Y;
//	RealPoint operator+(const RealPoint& aFirst, const RealPoint& aSecond){
//		return RealPoint{aFirst.X + aSecond.X, aFirst.Y + aSecond.Y}
//		/*RealPoint result;
//		result.X = aFirst.X + aSecond.X;
//		result.Y = aFirst.Y + aSecond.Y;
//		return result;*/
//	}
//};

//template <class T>
template <typename T>
struct Point {
	T X;
	T Y;
	template<typename T>
	Point<T> operator+(const Point<T>& aFirst, const Point<T>& aSecond) {
		return Point<T>{ aFirst.X + aSecond.X, aFirst.Y + aSecond.Y }
	}
};


template<typename TKey, typename TValue = std::string>
struct Pair {
	TKey key;
	TValue value;
};

template <typename T>
class Tree {
public:
	template<typename U, int Capacity = 10>
	struct Node {
		U Value;
		Node* left;
		Node* right;
	};

	typedef Node<T> value_type;

	Tree() {
		_array = new Node<T>[Capacity];
	}

private:
	Node<T>* _array;
};
template <typename T>
void appendFunction(const T& aWhat, const T&where) {

}

enum StructType {Mutable, Immutable};
template<StructType>
class MyCollection {

};

template<>
class MyCollection<Mutable> {

};class MyCollection<Immutable> {

};
#endif // !Temlate_SAMPLE_H
