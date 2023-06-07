#include <stdio.h>
#include <string.h>

typedef struct Pasien_t {
  char nama[100];
  int umur;
  int prior;
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  struct Pasien_t pasien[n];
  int i, j;
  for (i = 0; i < n; i++) {
    scanf("%s %d %d", pasien[i].nama, &pasien[i].umur, &pasien[i].prior);
  }

  int current_patient = -1;
  for (i = 0; i < m; i++) {
    int highest_prior = 1001;
    int highest_umur = -1;
    int same_prior_count = 0;
    int same_prior_older = 0;

    for (j = 0; j < n; j++) {
      if (pasien[j].prior <= highest_prior && pasien[j].umur >= highest_umur) {
        if (pasien[j].prior == highest_prior){
          same_prior_count++;
          if (pasien[j].umur > highest_umur) {
            same_prior_older = 1;
            current_patient = j;
            highest_umur = pasien[j].umur;
          }
        } else {
          same_prior_count = 1;
          current_patient = j;
          highest_prior = pasien[j].prior;
          highest_umur = pasien[j].umur;
        }
      }
    }

    if (same_prior_count > 1 && same_prior_older) {
      printf("Kamu jodoh ya %s - %d && %s - %d\n", pasien[current_patient].nama,
             pasien[current_patient].prior, pasien[current_patient - 1].nama,
             pasien[current_patient - 1].prior);
    } else if (current_patient != -1) {
      printf("Pasien selanjutnya adalah: %s - %d\n", pasien[current_patient].nama,
             pasien[current_patient].prior);
    } else {
      printf("Full senyum deck\n");
    }

    if (current_patient != -1) {
      pasien[current_patient].prior = -1;
      current_patient = -1;
    }
  }
  return 0;
}