#include <democlass.h>
#include <DbApi.h>

int main() {
	Db::open("data.txt");
	DemoClass dc{};
	dc.HelloWorld();

	return 0;
}