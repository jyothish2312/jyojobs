#include<iostream>
using namespace std;
int main(){
//THE AUTHOR OF THIS PROGRAM IS || ***JYOthish K. J.*** || . ALL RIGHTS ASSOCIATED WITH THIS PROGRAM ARE RESERVED BY THE AUTHOR.
cout<<endl;
cout<<endl;

int t;
cout<<"PLEASE ENTER THE NUMBER OF SUBJECTS YOU HAVE ENROLLED FOR:\n";
cin>>t;
int grade[t];
int cr[t];
int q=0;


cout<<"PLEASE REFER TO THE FOLLOWING CONVERSION CHART FOR ENTERING THE GRADE SCORED:"<<endl;
cout<<endl;

cout<<"*GRADE*\t*POINTS*"<<endl;
cout<<"========================"<<endl;


int i=65;
int j=65;
int n = 1;
int g=10;

for(n=7; g>=4; n++){
if((n%2)==0){
j++;
cout<< char(i)<<char(j)<<"\t"<<g<<"\n";

}
else{
cout<< char(i)<<char(j)<<"\t"<<g<<"\n";
}
i=j;
g=g-1;
}

cout<<"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = ="<<endl;


cout<<"For reference of 1st year students, the credits for individual subjects are as follows: "<<endl;
cout<<"C101 : 3 || ";
cout<<"P101 : 3 ||";
cout<<"M101 : 3 ||";
cout<<"B101 : 3 ||";
cout<<"CS141 : 2 ||";
cout<<"C141 : 2 ||";
cout<<"P141 : 2 ||";
cout<<"B141 : 2 ||";
cout<<"H101 : 2 ||";
cout<<"H109 : 2 "<<endl;
cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
cout<<"Other's can refer to *** https://drive.google.com/file/d/1b1Ns8fU0Jp_bbeUH3AGI1NYOsL___Fx0/view?usp=sharing *** for knowing the credits associated with their subjects. "<<endl;
cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
while(q<t){
cout<<"PLEASE ENTER THE CREDITS FOR SUBJECT "<<(q+1)<<" : ";
cin>>cr[q];
cout<<endl;
cout<<"PLEASE ENTER THE POINTS OBTAINED: ";
cin>>grade[q];
cout<<endl;
cout<<"-----------------------------------------------------------------"<<endl;
q++;
}
q=0;
int m=0;
while(q<t){
m = ((cr[q]*grade[q])+m);
q++;
}
cout<<"========================================================="<<endl;
cout<<"YOUR GPA IS : "<<(m/24)<<endl;
cout<<"-----------------------------------------------------------------"<<endl;
cout<<"****the above calculation is valid only for 24 credit system (as applicable in NISER)"<<endl;



return 0;
}
