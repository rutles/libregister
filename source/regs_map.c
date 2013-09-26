// regs_map.c
// libregister member function
// Tetsuya Suzuki, 2013

#include <register.h>

// Create new mapping of registers
// offset: offset address of registers
// return: pointer to the mapped area, or MAP_FAILED on error
uint32_t *regs_map(off_t offset){
  int fd;
  void *map;

  fd = open("/dev/mem", O_RDWR | O_SYNC);
  if(fd < 0)
    return MAP_FAILED;

  map = mmap(NULL,
    getpagesize(),
    PROT_READ | PROT_WRITE,
    MAP_SHARED,
    fd,
    offset);

  close(fd);
  return map;
}
