#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int n; 
  double *a;
} Poly;

Poly createPoly(int n) {
  Poly p;
  p.n = n;
  p.a = (double*)malloc((n + 1) * sizeof(double));
  return p;
}

void inputPoly(Poly p) {
  for (int i = 0; i <= p.n; i++) {
    printf("Nhap he so cua x^%d: ", i);
    scanf("%lf", &p.a[i]);
  }
}

void deletePoly(Poly p) {
  free(p.a);
}

void outputPoly(Poly p) {
  for (int i = p.n; i >= 0; i--) {
    if (i == 0) {
      printf("%.2lf", p.a[i]);
    } else if (p.a[i] == 0) {
      continue;
    } else if (p.a[i] > 0) {
      printf(" + %.2lfx^%d", p.a[i], i);
    } else {
      printf(" %.2lfx^%d", p.a[i], i);
    }
  }
  printf("\n");
}

Poly addPoly(Poly p, Poly q) {
  int max_n = (p.n > q.n) ? p.n : q.n;
  Poly r = createPoly(max_n);
  for (int i = 0; i <= max_n; i++) {
    double coef_p = (i <= p.n) ? p.a[i] : 0;
    double coef_q = (i <= q.n) ? q.a[i] : 0;
    r.a[i] = coef_p + coef_q;
  }
  return r;
}

int main() {
  Poly p = createPoly(2);
  Poly q = createPoly(3);

  printf("Nhap da thuc P(x):\n");
  inputPoly(p);
  printf("Nhap da thuc Q(x):\n");
  inputPoly(q);

  Poly r = addPoly(p, q);

  printf("Tong P(x) va Q(x) la: ");
  outputPoly(r);

  deletePoly(p);
  deletePoly(q);
  deletePoly(r);

  return 0;
}
