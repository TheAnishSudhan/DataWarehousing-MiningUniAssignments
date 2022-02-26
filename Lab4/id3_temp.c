#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct treeAttributes{
  char name;
  char gender;
  float height;
  char heightRange;
  char output
} attribute[15];

int n=15;
char name={"Kristina","Jim","Maggie","Martha","Stephanie","Bob","Kathy","Dave","Worth","Steven","Debbie","Todd", "Kim","Amy","Wynette"};
char gender={"f","m","f","f","f","m","f","m","m","m","f","m","f","f","f"};
float height={1.6,2,1.9,1.88,1.7,1.85,1.6,1.7,2.2,2.1,1.8,1.95,1.9,1.8,1.75};
char output={"s","t","m","m","s","m","s","s","t","t","m","m","m","m","m"};


struct sample{
    int height;         //0-1.6 1.6-1.7  1.7-1.8  1.8-1.9 1.9-2.0 2.0-infinity
                        //  1       2       3       4       5       6
    char gender;        //f,m 1,2
    int output;        //s,m,t  1,2,3
}samples[15];

int main()
{
    samples[0].height=1;
    samples[0].gender=1;
    samples[0].output=1;

    samples[1].height=5;
    samples[1].gender=2;
    samples[1].output=3;

    samples[2].height=4;
    samples[2].gender=1;
    samples[2].output=2;

    samples[3].height=4;
    samples[3].gender=1;
    samples[3].output=2;

    samples[4].height=2;
    samples[4].gender=1;
    samples[4].output=1;

    samples[5].height=4;
    samples[5].gender=2;
    samples[5].output=2;

    samples[6].height=1;
    samples[6].gender=1;
    samples[6].output=1;

    samples[7].height=2;
    samples[7].gender=2;
    samples[7].output=1;

    samples[8].height=6;
    samples[8].gender=2;
    samples[8].output=3;

    samples[9].height=6;
    samples[9].gender=2;
    samples[9].output=3;

    samples[10].height=3;
    samples[10].gender=1;
    samples[10].output=2;

    samples[11].height=5;
    samples[11].gender=2;
    samples[11].output=2;

    samples[12].height=4;
    samples[12].gender=1;
    samples[12].output=2;

    samples[13].height=3;
    samples[13].gender=1;
    samples[13].output=2;

    samples[14].height=3;
    samples[14].gender=1;
    samples[14].output=2;

    float female=0,male=0;
    int block1=0,block2=0,block3=0,block4=0,block5=0,block6=0;
    int shortie=0,medium=0,tall=0;

    for(int i=0;i<15;i++){
        if(samples[i].gender==1){
                female+=1;
        }
        else{male+=1;}
    }


    for(int i=0;i<15;i++){
        if(samples[i].output==1){
                shortie+=1;
        }
        else if(samples[i].output==2){
                medium+=1;
        }
        else if(samples[i].output==3){
                tall+=1;
        }
    }
    //printf("F:%d,M:%d",female,male);

    float total=shortie+medium+tall;
    //S[short,med,tall]
    //attribute gender:
    float S=-(shortie/total)*(log2(shortie/total))-(medium/total)*(log2(medium/total))-(tall/total)*(log2(tall/total));
    float a=0,b=0,c=0,d=0,e=0,f=0;
    //male:
    for(int i=0;i<15;i++){
        if(samples[i].gender==2){
            if(samples[i].output==1){
                a+=1;
            }
            else if(samples[i].output==2){
                b+=1;
            }
            else if(samples[i].output==3){
                c+=1;
            }
        }
        else if(samples[i].gender==1){
            if(samples[i].output==1){
                d+=1;
            }
            else if(samples[i].output==2){
                e+=1;
            }
            else if(samples[i].output==3){
                f+=1;
            }
        }
    }
    float a1,b1,c1,d1,e1,f1;
    float x=a+b+c;
    float y=d+e+f;
    if(a!=0){
         a1=-(a*((log2(a/x)))/x);
    }else{a1=0;}
    if(b!=0){
         b1=-(b*((log2(b/x)))/x);
    }else{b1=0;}
    if(c!=0){
         c1=-(c*((log2(c/x)))/x);
    }else{c1=0;}
    if(d!=0){
         d1=-(d*((log2(d/y)))/y);
    }else{d1=0;}
    if(e!=0){
         e1=-(e*((log2(e/y)))/y);
    }else{e1=0;}
    if(f!=0){
         f1=-(f*((log2(f/y)))/y);
    }else{f1=0;}

    float val2=d1+e1+f1;
    float val1=a1+b1+c1;

    //printf("no1 %.3f, no2 %.3f",val1,val2);
    //printf("S=%f",S);
    float IGgender=S-(male/(male+female))*val1-(female/(male+female))*val2;

    printf("Info Gain(Gender): %f",IGgender);
    //-----------------------------------
    //height:
    for(int i=0;i<15;i++){
        if(samples[i].height==1){
                block1+=1;
        }
        else if(samples[i].height==2){
                block2+=1;
        }
        else if(samples[i].height==3){
                block3+=1;
        }
        else if(samples[i].height==4){
                block4+=1;
        }
        else if(samples[i].height==5){
                block5+=1;
        }
        else if(samples[i].height==6){
                block6+=1;
        }
    }

    total=block1+block2+block3+block4+block5+block6;
    //attribute height:
    //S=-(block1/total)*(log2(block1/total))-(block2/total)*(log2(block2/total))-(block3/total)*(log2(block3/total))-(block4/total)*(log2(block4/total))-(block5/total)*(log2(block5/total))-(block6/total)*(log2(block6/total));
    float g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0,r=0;
    a=0,b=0,c=0,d=0,e=0,f=0;
    //male:
    for(int i=0;i<15;i++){
        if(samples[i].height==1){
            if(samples[i].output==1){
                a+=1;
            }
            else if(samples[i].output==2){
                b+=1;
            }
            else if(samples[i].output==3){
                c+=1;
            }
        }
        else if(samples[i].height==2){
            if(samples[i].output==1){
                d+=1;
            }
            else if(samples[i].output==2){
                e+=1;
            }
            else if(samples[i].output==3){
                f+=1;
            }
        }
        else if(samples[i].height==3){
            if(samples[i].output==1){
                g+=1;
            }
            else if(samples[i].output==2){
                h+=1;
            }
            else if(samples[i].output==3){
                i+=1;
            }
        }
