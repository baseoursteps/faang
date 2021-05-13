#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool
isDuo(int no)
{
  unsigned char bits = 0;
  unsigned char count = 0;

  for (no = abs(no); no; no /= 10) {

    unsigned char d = no % 10;

    if (bits & (1 << d))
      continue;
    else {
      bits |= (1 << d);
      count++;
    }

    if (count > 2)
      return false;
  }

  return true;
}

int
main()
{
  printf("%d %d %d %d\n", isDuo(0), isDuo(102), isDuo(-2020), isDuo(3333));

  return 0;
}
