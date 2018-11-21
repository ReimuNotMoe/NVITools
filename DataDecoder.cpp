#include <cstdio>
#include <cstdlib>
#include <cinttypes>
#include <vector>
#include <cstring>

int main(int argc, char **argv) {

	int base = 10;
	int i = 1;

	if (argv[1]) {
		if (0 == strcmp(argv[1], "--hex")) {
			base = 16;
			i = 2;
			printf("Using hex mode.\n");
		}
	}

	std::vector<uint8_t> buf;

	for (; i<argc; i++) {
		auto byte = (uint8_t)strtol(argv[i], NULL, base);
		buf.push_back(byte);
	}

	printf("Length: %zu\n", buf.size());

//	printf("Data: ");
//
//	for (auto &it : buf) {
//		printf("%" PRIu8 " ", it);
//	}
//
//	printf("\n\n");

	if (buf.size() == 4) {
		printf("x32: %" PRIx32 "\n", *(uint32_t *)buf.data());
		printf("u32: %" PRIu32 "\n", *(uint32_t *)buf.data());
		printf("d32: %" PRId32 "\n", *(uint32_t *)buf.data());

		printf("\n\n");
	}

	if (buf.size() == 8) {
		printf("x64: %" PRIx64 "\n", *(uint64_t *)buf.data());
		printf("u64: %" PRIu64 "\n", *(uint64_t *)buf.data());
		printf("d64: %" PRId64 "\n", *(uint64_t *)buf.data());

		printf("\n\n");
	}

	buf.push_back(0);
	printf("String: %s\n", buf.data());

	return 0;

}