#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int age[10]={49,37,21,29,66,25,36,49,59,52};
int income[10]={39,20,33,79,63,24,87,62,71,23};
int score[10]={28,13,81,83,48,73,10,56,11,29};
int c_ID[10]={45,15,36,162,110,22,173,105,129,19};
float distances1[10],distances2[10];
float m1[3]={21,33,81};
float m2[3]={25,24,73};
float oldM1[3], oldM2[3];
int cluster1[10],cluster2[10];

void displayMean(float m[3], int j){
  printf("\nMean Value %d\n", j);
  for (int i = 0; i < 3; i++) {
    printf("%f\t",m[i] );
  }
  printf("\n");
}

void displayCluster(int cluster[]){

  for (int i = 0; i < 10; i++) {
    if (cluster[i]==1) {
      printf("%d\t",c_ID[i] );
    }
  }
  printf("\n");
}

float distanceCalculator(float m[3], int i){
  float distance=0.0;
  distance=fabsf(m[0]-age[i])+fabsf(m[1]-income[i])+fabsf(m[2]-score[i]);
  return distance;
}

void meanDistanceCalculator(float m1[3], float m2[3]){

  printf("\nDistance Matrix\n\n");

  for (int i = 0; i < 10; i++) {
    distances1[i]=distanceCalculator(m1,i);
    distances2[i]=distanceCalculator(m2,i);
    printf("%f\t%f\n",distances1[i],distances2[i]);
  }
}

void clusterValues(){

  for (int i = 0; i < 10; i++) {
    if (distances1[i]<distances2[i]) {
      cluster1[i]=1;
    }
    else {
      cluster2[i]=1;
    }
  }

  printf("\nCluster 1: \n");
  displayCluster(cluster1);
  printf("\nCluster 2: \n");
  displayCluster(cluster2);

}

void preserveMeanValues(float m[3], float oldM[3]) {
  for (int i = 0; i < 3; i++) {
    oldM1[i]=m1[i];
    oldM2[i]=m2[i];
  }
}

bool meanEqual(){

  int count=0;
  for (int i = 0; i < 3; i++) {
    if ((m1[i]==oldM1[i])&&(m2[i]==oldM2[i])) {
      count++;
    }
    if (count==3) {
      return true;
    }
  }
  return false;
}

void newMeanValue(int cluster[10], float m[]){

  float sumAge=0, sumIncome=0, sumScore=0;
  int number=0;

  for (int i = 0; i < 10; i++) {
    if (cluster[i]==1) {
      sumAge+=age[i];
      sumIncome+=income[i];
      sumScore+=score[i];
      number++;
    }
  }
  sumAge/=number;
  sumIncome/=number;
  sumScore/=number;

  m[0]=sumAge;
  m[1]=sumIncome;
  m[2]=sumScore;
}


int main(){

  do {
    displayMean(m1,1);
    displayMean(m2,2);
    meanDistanceCalculator(m1,m2);
    clusterValues();
    preserveMeanValues(m1, oldM1);
    preserveMeanValues(m2, oldM2);
    newMeanValue(cluster1, m1);
    newMeanValue(cluster2, m2);
  } while(!(meanEqual()));

  displayMean(m1,1);
  displayMean(m2,2);

  printf("Hence we verified \n");

  // while (!(meanEqual())) {
  //   displayMean(m1,1);
  //   displayMean(m2,2);
  //   meanDistanceCalculator(m1,m2);
  //   clusterValues();
  //   preserveMeanValues(m1, oldM1);
  //   preserveMeanValues(m2, oldM2);
  //   newMeanValue(cluster1, m1);
  //   newMeanValue(cluster2, m2);
  // }

  return 0;
}
