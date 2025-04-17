#include<stdio.h>
#define MAX_ITEMS 100
double computemaxvalue(double w,double weight[],double value[],double ratio[],int nitems);
int getnextitem(double weight[],double value[],double ratio[],int nitems);
int main(){
int nitems,i,j;
double w,weight[MAX_ITEMS],ratio[MAX_ITEMS],value[MAX_ITEMS];
printf("enter thye number of itens");
scanf("%d",&nitems);
printf("enter the weight of the items");
for(i=0;i<nitems;i++)
{
scanf("%lf",&weight[i]);
}
printf("enter the values");
for(i=0;i<nitems;i++){
scanf("%lf",&value[i]);
}
for(i=0;i<nitems;i++){
ratio[i]=value[i]/weight[i];
}
printf("enter the capacity of the knapsack");
scanf("%lf",&w);
printf("the maximum value in a knapsack of capacity %2f is %2f",w,computemaxvalue(w,weight,value,ratio,nitems));
return 0;
}
double computemaxvalue(double w,double weight[],double value[],double ratio[],int nitems){
double cw=0,cv=0;
printf("items considered are");
while(cw<w){
int item=getnextitem(weight,value,ratio,nitems);
if(item==-1){
break;
}
printf("%d",item+1);
if(cw+weight[item]<=w){
cw+=weight[item];
cv+=value[item];
ratio[item]=0;
}else{
cv+=(ratio[item]*(w-cw));
cw+=(w-cw);
break;
}
}
return cv;
}
int getnextitem(double weight[],double value[],double ratio[],int nitems)
{
double highest=0;
int index=-1,i;
for(i=0;i<nitems;i++){
if(ratio[i]>highest){
highest=ratio[i];
index=i;
}
}
return index;
}
