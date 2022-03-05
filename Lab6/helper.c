#include <math.h>
#include <stdio.h>

float subjectScores[7][3]={{1.0,1.0,1},{1.5,2.0,2},{3.0,4.0,3},{5.0,7.0,4},{3.5,5.0,5},{4.5,5.0,6},{3.5,4.5,7}};

float manhattanDistance(float x1, float y1, float mean[]){

  float x2=mean[0];
  float y2=mean[1];

  return (fabsf(x1-x2)+fabsf(y1-y2));
}

int main(int argc, char const *argv[]) {

  // manhattanDistance();

  float sumA=0.0;
  float sumB=0.0;

  for (int i = 0; i < 7; i++) {
    sumA+=subjectScores[i][0];
    sumB+=subjectScores[i][1];
  }

  sumA-=1;
  sumB-=1;

  printf("%f\t",sumA );
  printf("%f\n",sumB );

  sumA/=6;
  sumB/=6;

  printf("%f\t",sumA );
  printf("%f\n",sumB );

  return 0;
}
/*
0     1.5
1.5   0
5     3.5
10    8.5
6.5   5
7.5   6
6     4.5

Cluster 1 -> 1
Cluster 2 -> 2,3,4,5,6,7

1 & 7 not input in the clusters

New Mean 1-> (1,1)
New Mean 2-> (3.5, 4.583)






*/
