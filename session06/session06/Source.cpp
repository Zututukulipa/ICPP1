#include "ExceptionSample.h"
#include "TemplateSample.h"
#include <iostream>
void TemplateSamples() {
	Point<int> intPoint{1,2};
	int result1 = appendFunction<int>(1,1});
	double result2 = appendFunction<double>(2.3, 2.6);
	appendFunction(2, 7); //implicit
	appendFunction<double>(2, 7.6); //explicit
	std::string a("a"), b("b");
	std::string result4 = appendFunction(a, b);
	intPoint result5 = appendFunction(Point(1, 1), Point(2, 2));
	Point<int> pointInt = Point{ 1,1 };
	auto result6 = appendFunction<Point<int>>(Point<int>{1, 1}, Point<int>{1, 1});
	Pair<int, int> pair = Pair{};
	Pair<int> pair = Pair{};
	Tree<int>::value_type value;
}
int main() {
	HandleExceptionFunction();

}