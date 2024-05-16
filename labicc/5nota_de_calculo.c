#include <stdio.h>

int main(void) 
{
  double p1, p2, l1, l2, l3, l4;
  scanf("%lf%lf%lf%lf%lf%lf", &p1, &p2, &l1, &l2, &l3, &l4);
  
  double nlistas = (l1+l2+l3+l4)/4;
  double nfinal = (p1+p2+nlistas)/3;
  
  if (nlistas == 0) {
    printf("Reprovado\n");
  } else if (nfinal >= 5) {
    printf("Aprovado\n");
  } else if (nfinal >= 3) {
    printf("Recuperacao\n");
  } else {
    printf("Reprovado\n");
  }
  
  return 0;
}
