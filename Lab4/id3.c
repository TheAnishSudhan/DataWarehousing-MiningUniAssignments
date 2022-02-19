#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct treeAttributes{
  char name;
  char gender;
  float height;
  char heightRange;
  char output;
} attribute[15];

int n=15;
char name[15]={"Kristina","Jim","Maggie","Martha","Stephanie","Bob","Kathy","Dave","Worth","Steven","Debbie","Todd", "Kim","Amy","Wynette"};
char gender[15]={"f","m","f","f","f","m","f","m","m","m","f","m","f","f","f"};
float height[15]={1.6,2,1.9,1.88,1.7,1.85,1.6,1.7,2.2,2.1,1.8,1.95,1.9,1.8,1.75};
char output[15]={"s","t","m","m","s","m","s","s","t","t","m","m","m","m","m"};
char genderValues[2]={"m","f"};
char heightValues[6]={"1","2","3","4","5","6"};
char heightRange[15];

char heightDiscretiser(float height){

  if ((height>0)||(height<=1.6)) {
    return "1";
  }
  if ((height>1.6)||(height<=1.7)) {
    return "2";
  }
  if ((height>1.7)||(height<=1.8)) {
    return "3";
  }
  if ((height>1.8)||(height<=1.9)) {
    return "4";
  }
  if ((height>1.9)||(height<=2.0)) {
    return "5";
  }
  if (height>2.0) {
    return "6";
  }
  return "0";
}

void valueAssigner(){

  for (int i = 0; i < 15; i++) {
    attribute[i].name=name[i];
    attribute[i].gender=gender[i];
    attribute[i].height=height[i];
    attribute[i].output=output[i];
    attribute[i].heightRange=heightDiscretiser(height[i]);
    heightRange[i]=heightDiscretiser(height[i]);
  }
}

unsigned int Log2n(float n)
{
    return (n > 1) ? 1 + Log2n(n / 2) : 0;
}

float probabilityLog(int numerator, int denominator){

  float value = -(numerator/denominator)*(Log2n(numerator/denominator));

  return value;
}

int baseCounter(char match, char array[]){

  int count=0;

  for (int i = 0; i < n; i++) {
    if (match==array[i]) {
      count++;
    }
  }

  return count;
}

int counter(char match, char array[], char condition){

  int count=0;

  for (int i = 0; i < n; i++) {
    if ((match==array[i])&&(condition==output[i])) {
      count++;
    }
  }

  return count;
}

float baseEntropy(){

  int yesShort=baseCounter("s",output); //can make a function for this
  int noShort=n-yesShort;
  int yesMedium=baseCounter("m",output);
  int noMedium=n-yesMedium;
  int yesTall=baseCounter("t",output);
  int noTall=n-yesTall;

  float entropy=probabilityLog(yesShort,n)+probabilityLog(yesMedium,n)+probabilityLog(yesTall,n);

  return entropy;
}

float attributeEntropyCalculator(char attribute, char array[]){

  //make more modular

  int denominator=baseCounter(attribute,array);
  int numeratorShort=counter(attribute,array,"s");
  int numeratorMedium=counter(attribute,array,"m");
  int numeratorTall=counter(attribute,array,"t");

  float entropy=probabilityLog(numeratorShort,denominator)+probabilityLog(numeratorMedium,denominator)+probabilityLog(numeratorTall,denominator);

  return entropy;
}

float weightedSumCalculator(char array[], char values[], int  n){

  float value;

  for (int i = 0; i < n; i++) {
    value+=attributeEntropyCalculator(values[i], array);
  }

  return value;
}

float InfoGainCalculator(float classEntropy, float weightedSum){

  float value=classEntropy-weightedSum; //these values will be recorded form baseEntropy & weightedSumCalculator in main and then passed here

  return value;
}

int main() {

  valueAssigner();

  float weightedSumGender=weightedSumCalculator(gender,genderValues,2);
  float weightedSumHeight=weightedSumCalculator(height,heightValues,7);

  float classEntropy=baseEntropy();

  float InfoGainGender=InfoGainCalculator(classEntropy, weightedSumGender); //maybe create a struct for this
  float InfoGainHeight=InfoGainCalculator(classEntropy, weightedSumHeight);

  if (InfoGainGender>+InfoGainHeight) {
    printf("The first splitting attribute is Gender\n");
  }
  else {
    printf("The first splitting attribute is Height\n");
  }

  return 0;
}
