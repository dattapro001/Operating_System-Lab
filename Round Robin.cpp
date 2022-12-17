//Round Robin Algorithm

#include <stdio.h>
using namespace std;
int main(){
int i,n,j,q,t, count=0,temp,ex=0,p[100],at[100],bt[100],rem_bt[100]tat[100],wt[100]; //using array to take input of all process
int qt; // quantum time
float atat=0,awt=0; //total turn around time 1st initial from zero same as awt.

cout<<"Enter Process Number";  //massage to how many process do u want?
cin>>n;                       //take process from user

cout<<"Enter process sequence"; // here we will take every process input
for(i=0;i<n;i++){
    cin>>p[i];    //take process sequence
}

cout<<"Enter Arrival Time";  //here we will take arrival time for every process
for(i=0;i<n;i++){
    cin>>at[i];
}

cout<<"Enter bust Time";  //here we will take bust time for every process
for(i=0;i<n;i++){
    cin>>bt[i];
    rem_bt[i]=bt[i];   //store the input bt in rem_bt
}

cout<<"Enter time quantum";  // taking time quantum
cin>>qt;

//sorting those input with there process.Using bubble sorting
for(i=0;i<n;i++){    //taking 1st number from input to check with other number from list
    for(j=i+1;j<n;j++){ // start checking from 2nd number from input list thats why we use i+1
        if(at[i]>at[j]){  // if taken number greater than other than we will swipe the position
            //bust time sorting
            temp=bt[i];   //1st input number store in temp
            bt[i]=bt[j];  //now swiping the position and bt[j] store in bt[i]
            bt[j]=temp;   // now the smallest number in 1st position and store it to temp

            //same as remaining bust time sorting
            temp=rem_bt[i];   //1st input number store in temp
            rem_bt[i]=rem_bt[j];  //now swiping the position and rem_bt[j] store in rem_bt[i]
            rem_bt[j]=temp;   // now the smallest number in 1st position and store it to temp

            //same as process sorting
            temp=p[i];   //1st input number store in temp
            p[i]=p[j];  //now swiping the position and p[j] store in p[i]
            p[j]=temp;   // now the smallest number in 1st position and store it to temp

            //same as arrival time sorting
            temp=at[i];   //1st input number store in temp
            at[i]=at[j];  //now swiping the position and at[j] store in at[i]
            at[j]=temp;   // now the smallest number in 1st position and store it to temp

        }
    }
}
// Calculation Section
while (true){    //using while loop to calculate each process.  
   for(i=0,count=0;i<n;i++){    //checking all process  
    temp=qt;                   //store the time quntum into temp
    if(rem_bt[i]==0){          //if there are no remaining bust time
        count++;               //move forward 
        continue;              //continue checking other process
    }
    if(rem_bt[i]>qt){            //if remaining bust time greater than quntum time
        rem_bt[i]= rem_bt[i]-qt; //subtract remaining bust time to quntum time
    }
    else
    if(rem_bt[i]>=0){       //if rem_bt equal or greater than qt          
        temp=rem_bt[i];     // then we will store rem_bt into temp
        rem_bt[i]=0;        //them the rem_bt will be zero
    }
    ex=ex+temp;             //completion time adding with temp 
    tat[i]=ex-at[i];       // tat= completion time - arrival time
    wt[i]=tat[i]-bt[i];    //wt= turn around time - bust time
    }
    if(n==count){//if number of process equal to count then all process checking complete and break the checking process
        break;
    }
}
//output Section
cout<<"\n process\t arrival time\t bust time\t turn around time\t waiting time\t"<<endl;
for(i=0;i<n;i++){   //checking all input
    atat=tat[i];   //here we adding all time around time
    awt=wt[i];     //here we adding all waiting time
    cout<<"p["<<p[i]<<"]\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;     //printing all sorted inputs
    }
    atat= atat/n;  //divide total turn around time with number of process
    awt= awt/n;    ////divide total waiting with number of process

    cout<<"\n Average Turn Around Time"<<atat<<endl;  //printing atat
     cout<<"\n Average waiting Time"<<awt<<endl;      //printing awt
     return 0;

}
