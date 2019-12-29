#include <democlass.h>
#include <DbApi.h>

int main() {
	Db *dat = Db::open("data.txt");
	auto tab = dat->openTable("TEST_TABLE");
	dat->close();
	DemoClass dc{};
	dc.HelloWorld();

	return 0;
}