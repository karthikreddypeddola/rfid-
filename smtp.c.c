#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
  FILE *pip;

  printf("sending ...\n");
  assert(pip = popen("sendmail hermann@stamm-wilbrandt.de", "w"));

  fprintf(pip, "Subject: foobar\n");

  fprintf(pip, "foo\n");
  fprintf(pip, "bar\n");
  fprintf(pip, "bye\n");

  fprintf(pip, ".\n");
  pclose(pip);
  printf("... sent\n");

  exit(0);
}