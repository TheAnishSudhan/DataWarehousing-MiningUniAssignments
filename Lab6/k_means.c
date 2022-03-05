#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float A[7]={1.0,1.5,3.0,5.0,3.5,4.5,3.5};
float B[7]={1.0,2.0,4.0,7.0,5.0,5.0,4.5};
int row_ID[7]={1,2,3,4,5,6,7};
float distances1[7],distances2[7];
float m1[2]={1.0,1.0};
float m2[2]={1.5,2.0};
float oldM1[2], oldM2[2];
int cluster1[7],cluster2[7];

void displayMean(float m[2], int j){
  printf("\nMean Value %d\n", j);
  for (int i = 0; i < 2; i++) {
    printf("%f\t",m[i] );
  }
  printf("\n");
}

void displayCluster(int cluster[]){

  for (int i = 0; i < 7; i++) {
    if (cluster[i]==1) {
      printf("%d\t",row_ID[i] );
    }
  }
  printf("\n");
}

float distanceCalculator(float m[2], int i){
  float distance=0.0;
  distance=fabsf(m[0]-A[i])+fabsf(m[1]-B[i]);
  return distance;
}

void meanDistanceCalculator(float m1[2], float m2[2]){

  printf("\nDistance Matrix\n\n");

  for (int i = 0; i < 10; i++) {
    distances1[i]=distanceCalculator(m1,i);
    distances2[i]=distanceCalculator(m2,i);
    printf("%f\t%f\n",distances1[i],distances2[i]);
  }
}

void clusterValues(){

  for (int i = 0; i < 7; i++) {
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

void preserveMeanValues(float m[2], float oldM[2]) {
  for (int i = 0; i < 3; i++) {
    oldM1[i]=m1[i];
    oldM2[i]=m2[i];
  }
}

bool meanEqual(){

  int count=0;
  for (int i = 0; i < 2; i++) {
    if ((m1[i]==oldM1[i])&&(m2[i]==oldM2[i])) {
      count++;
    }
    if (count==2) {
      return true;
    }
  }
  return false;
}

void newMeanValue(int cluster[7], float m[]){

  float sumA=0, sumB=0;
  int number=0;

  for (int i = 0; i < 7; i++) {
    if (cluster[i]==1) {
      sumA+=A[i];
      sumB+=B[i];
      number++;
    }
  }
  sumA/=number;
  sumB/=number;

  m[0]=sumA;
  m[1]=sumB;
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

  return 0;
}
