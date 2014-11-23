#include "header.h"

int compare(const void* unit_1, const void* unit_2){
  const student A = *(const student*)unit_1;
  const student B = *(const student*)unit_2;
  return strcmp(A.name,B.name);
}
