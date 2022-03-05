#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
We take 2 means
find distance with respect to each mean
assign Clusters
find mean from new clusters 
*/

float subjectA[7]={1.0,1.5,3.0,5.0,3.5,4.5,3.5};
float subjectB[7]={1.0,2.0,4.0,7.0,5.0,5.0,4.5};
float subjectScores[7][3]={{1.0,1.0,1},{1.5,2.0,2},{3.0,4.0,3},{5.0,7.0,4},{3.5,5.0,5},{4.5,5.0,6},{3.5,4.5,7}};

float mean1[2]={1.0,1.0};
float mean2[2]={1.5,2.0};

float distancesMean1[7];
float distancesMean2[7];

float cluster1[7];
float cluster2[7];

int indexC1=-1, indexC2=-1;

//get mean
//tabulate distance
//find minimum across means and add to clusters

// struct scores{
//   float scoreA;
//   float scoreB;
//   int cluster;
//   char classTissue;
//   int distanceTissue;
// };
//
// struct score scoreArray[7];
//
// float euclideanDistance(int x, int y, int i){
//
//   int x=acid-acidArray[i];
//   int y=strength-strengthArray[i];
//
//   float distance=sqrt(pow(x,2)+pow(y,2));
//
//   return distance;
// }

/*

Mean -> 1 -> 1.0, 1.0
MEan 2 -> 3.5, 4.583



*/

float manhattanDistance(float x1, float y1, float mean[]){

  float x2=mean[0];
  float y2=mean[1];

  return (fabsf(x1-x2)+fabsf(y1-y2));
}

float clusterClassifier(float distanceMean1, float distanceMean2){
  printf("Dist 1: %f, dist 2:%f\n",distanceMean1, distanceMean2 );

  if (distanceMean1<distanceMean2) {
    //cluster1[indexC1]=subjectScores[];//distanceMean1;
    ++indexC1;
    return 1;
  }
  else {
    //cluster2[indexC2]=subjectScores[];//distanceMean1;
    ++indexC2;
    return 2;
  }

  return -1.0;
}

int distanceTable(float mean1[], float mean2[]){

  printf("\nThe distance Table: \n");

  for (int i = 0; i < 7; i++) {
    distancesMean1[i]=manhattanDistance(subjectScores[i][0],subjectScores[i][1],mean1);
    printf("%f\t",distancesMean1[i]);
    distancesMean2[i]=manhattanDistance(subjectScores[i][0],subjectScores[i][1],mean2);
    printf("%f\n",distancesMean2[i]);
    int cluster=clusterClassifier(distancesMean1[i],distancesMean2[i]);
    if (cluster==1) {
      cluster1[indexC1]=subjectScores[i][2];
    }
    else {
      cluster2[indexC2]=subjectScores[i][2];
    }
  }

  printf("Clusters: \n");
  printf("cluster1\n");
  for (int i = 0; i < indexC1; i++) {
    printf("%f\t",cluster1[i]);
  }
  printf("\ncluster2\n");
  for (int i = 0; i < indexC2; i++) {
    printf("%f\t",cluster2[i]);
  }


  return -1;
}

float meanCalculator1(float cluster[], int count){

  float sum1=0.0;
  float sum2=0.0;

  printf("COUNT VAL IN MEANCALC 1: %d\n",count );

  for (int j = 0; j < 7; j++) {
    for (int i = 0; i <= count; i++) {
      if (subjectScores[j][2]==cluster[i]) {
        sum1+=subjectScores[i][0];
        sum2+=subjectScores[i][1];
      }
    }
  }

  mean1[0]=sum1/(float)count;
  printf("Mean1 0: %f\t",mean1[0]);
  mean1[1]=sum2/(float)count;
  printf("Mean 1 1: %f\t",mean1[1]);

  return 0.0;
}

float meanCalculator2(float cluster[], int count){

  float sum1=0.0;
  float sum2=0.0;

  for (int j = 0; j < 7; j++) {
    for (int i = 0; i <= count; i++) {
      if (subjectScores[j][2]==cluster[i]) {
        sum1+=subjectScores[i][0];
        sum2+=subjectScores[i][1];
      }
    }
  }

  mean2[0]=sum1/(float)count;
  printf("Mean 2 0: %f\t",mean2[0]);
  mean2[1]=sum2/(float)count;
  printf("Mean 2 1: %f\t",mean2[1]);

  return 0.0;
}

// int classifier(int k){
//
//   int badCount=0, goodCount=0;
//
//   for (int i = 0; i < k; i++) {
//     if (tissueArray[i].classTissue=="b") {
//       badCount++;
//     }
//     else {
//       goodCount++;
//     }
//   }
//
//   if (badCount>goodCount) {
//     printf("The Tuple is classified as bad\n");
//   }
//   else {
//     printf("The Tuple is classified as good\n");
//   }
//
//   return 0;
// }

int main() {
  float oldMean1[2]={0,0};
  float oldMean2[2]={0,0};

while ((oldMean1[0]!=mean1[0])&&(
oldMean1[1]=mean1[1])&&(oldMean2[0]=mean2[0])&&(oldMean2[1]=mean2[1])) {
  distanceTable(mean1,mean2);
  oldMean1[0]=mean1[0];
  oldMean1[1]=mean1[1];
  oldMean2[0]=mean2[0];
  oldMean2[1]=mean2[1];
  // oldMean2=mean2;
  meanCalculator1(cluster1,indexC1);
  meanCalculator2(cluster2,indexC2);
  indexC1=-1;
  indexC2=-1;


  //need to reset everything after 1 iteratoion - index, cluster, etc
  // need to make the second iteration distances on the basis ofnew mean
}


//Distance Caclulation

//Sorting

  // distanceSort();

//Classifying

  // classifier(k);

  return 0;
}
