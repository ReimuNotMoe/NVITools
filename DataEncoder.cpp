#include <cstdio>
#include <cstdlib>
#include <cinttypes>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char **argv) {

	if (argc < 2) {
		printf("Usage: DataEncoder <file>\n");
		exit(1);
	}

	int fd = open(argv[1], O_RDONLY);

	struct stat statat;

	fstat(fd, &statat);

	auto *m = (uint8_t *)mmap(NULL, statat.st_size, PROT_READ, MAP_SHARED, fd, 0);

	for (size_t j=0; j<statat.st_size; j++) {
		printf("%u, ", m[j]);
	}

	return 0;
}