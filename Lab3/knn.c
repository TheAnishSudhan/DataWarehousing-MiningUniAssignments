#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// store acid, strength and class
// take value of k from user, here 3
//take tuple from user
//calc distance array
//then sort in ascending order
//based on value of k=3, top 3, if k=5, look at top5 vaues
//look at corresponding class
//max one would be the classfying class

//acid,stremght, class, distance -> structure
//array of strcutures

//Swap elements of array (the elements are structures)

struct tissue{
  int acidTissue;
  int strengthTissue;
  char classTissue;
  int distanceTissue;
};

struct tissue tissueArray[8];
int acidArray[8]={7,7,3,1,2,6,2,5};
int strengthArray[8]={7,4,4,4,3,3,5,4};
char class[8]={"b","b","g","g","g","b","g","b"};
int distanceArray[8];


float euclideanDistance(int acid, int strength, int i){

  int x=acid-acidArray[i];
  int y=strength-strengthArray[i];

  float distance=sqrt(pow(x,2)+pow(y,2));

  return distance;
}

int distanceSort(){

  struct tissue Temp;
  for (int i = 0; i < 8; i++) {
    for (int j = i; j < 8; j++) {
      if (tissueArray[j].distanceTissue>tissueArray[i].distanceTissue) {
        Temp=tissueArray[i];
        tissueArray[i]=tissueArray[j];
        tissueArray[i]=Temp;
      }
    }
  }
  return 0;
}

int classifier(int k){

  int badCount=0, goodCount=0;

  for (int i = 0; i < k; i++) {
    if (tissueArray[i].classTissue=="b") {
      badCount++;
    }
    else {
      goodCount++;
    }
  }

  if (badCount>goodCount) {
    printf("The Tuple is classified as bad\n");
  }
  else {
    printf("The Tuple is classified as good\n");
  }

  return 0;
}

int main() {


  int k, acid_durability, strength;

  printf("Enter value of k: ");
  scanf("%d",&k);

  fflush(stdin);

  printf("Working??");

  //CRIES IN CODE

  printf("\nEnter acid durability of tissue: ");
  scanf("%d",&acid_durability);

  fflush(stdin);

  printf("\nEnter strength of tissue: ");
  scanf("%d",&strength);

  fflush(stdin);


//Distance Caclulation
  for (int i = 0; i < 8; i++) {
    distanceArray[i]=euclideanDistance(acid_durability, strength, i);
    tissueArray[i].acidTissue=acidArray[i];
    tissueArray[i].strengthTissue=strengthArray[i];
    tissueArray[i].classTissue=class[i];
    tissueArray[i].distanceTissue=distanceArray[i];
  }

//Sorting

  distanceSort();

//Classifying

  classifier(k);

  return 0;
}
