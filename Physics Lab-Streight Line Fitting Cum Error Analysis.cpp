//this program has been written by JYOthish K.J. 
#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	int i;
	int j;
	cout<<"HOW MANY READINGS DID YOU TAKE ? : ";
	cin>>(n);
	cout<<endl;
	
	double xi[n];
	cout<<"Feed in your Xi values as being prompted (follow each value-input with an 'enter' :)"<<endl;
	
	for(i = 0; i<n ; i++){
		cout<<"## Enter Xi data number "<<i+1<<" :";
		cin>>xi[i];
	}
	
cout<<endl;
	
double yi[n];
cout<<"Similarly now let's proceed feeding in the Yi values :)"<<endl;

for(j = 0; j<n ; j++){
	cout<<"## Enter Yi data number "<<j+1<<" :";
		cin>>yi[j];
}

cout<<endl;
int xi2[n];

double sumxi;
double sumyi;
double sumxiyi;
double sumxi2;

cout<<"S.T.R.E.I.G.H.T__L.I.N.E__F.I.T.T.I.N.G"<<endl;
cout<<"------------------------------------------------------------------------------------"<<endl;

cout<<"The following are the values for the streight line fitting table: "<<endl;
cout<<"Xi			Yi			XiYi			Xi^2"<<endl;
cout<<"_____________________________________________________________________________________"<<endl;

for(i=0,j=0; i<n,j<n; i++, j++){
	cout<<xi[i]<<"			"<<yi[j]<<"			"<<(xi[i]*yi[j])<<"			"<<(xi[i]*xi[i])<<endl;
	
	xi2[i]=(xi[i]*xi[i]);
	
	sumxi= sumxi+ xi[i];
	sumyi= sumyi+ yi[j];
	sumxiyi= sumxiyi + (xi[i]*yi[j]);
	sumxi2 = sumxi2 + (xi[i]*xi[i]);
	
}

cout<<"---------------------------------------------------------------------------------------"<<endl;

cout<<sumxi<<"			"<<sumyi<<"			"<<sumxiyi<<"			"<<sumxi2<<"			<=====SUMMATION"<<endl;

cout<<"=================================================================================="<<endl;


cout<<"The general formulas for streight line fitting are:"<<endl;
cout<<"						sum Yi = na + b(sum Xi)  ..........................(1)"<<endl; 
cout<<"						sum XiYi = a(sum Xi) + b(sum Xi^2)  ..........................(2)"<<endl; 
cout<<endl;
cout<<"														## here 'b' is the slope of the streight line"<<endl;
cout<<"														## and 'a' is the y intercept of the streight line"<<endl;
cout<<endl;
cout<<"Thus our equations for streight  line fitting are:"<<endl;
cout<<"						"<<sumyi<<" = ("<<n<<")a + b("<<sumxi<<")  ..........................(1)"<<endl; 
cout<<"						"<<sumxiyi<<" = a("<<sumxi<<") + b("<<sumxi2<<")  ..........................(2)"<<endl; 

float a, b;

b = ((sumyi*sumxi) - (n*sumxiyi))/((sumxi*sumxi)- (sumxi2*n));
a=(sumyi-(b*sumxi))/n;

cout<<"The value of Y-intercept 'a' is: "<<a<<endl;
cout<<"The value of Slope of this streight line is 'b' = "<<b<<endl;
cout<<endl;

cout<<"# Now we need to find the corresponding Y-new (let's call Yn)."<<endl;
cout<<endl;
cout<<"# Thats calculated simply by 'Y= bX + a' " <<endl; 
cout<<endl;
cout<<"# The Yn values for the corresponding Xi values have been listed below: "<<endl;
double yn[n];
for(i=0; i<n; i++){
	yn[i]= a+b*(xi[i]);
	cout<<"- The new Y"<<i<<" : "<<yn[i]<<endl;
}

cout<<"============================================================================="<<endl;
cout<<"============================================================================="<<endl;
cout<<endl;

cout<<"E.R.R.O.R______A.N.A.L.Y.S.I.S"<<endl;
cout<<"-----------------------------------------------------------------------------"<<endl;
cout<<endl;
cout<<"The error in Y (let's call it DelY) can be found out through the mean daviation in Y w.r.t. the new calculated values: "<<endl;
cout<<endl;
cout<<"i.e. ' DelY = (sum((Yn-Yi)^2))/N ' ___ which is valid for N < 10;     |or|   ' (sum((Yn-Yi)^2))/(N-2)' ___for N > 10"<<endl;
cout<<endl;
cout<<"That calculates out our error i.e. Del-Y = ";


double delytemp;
for(i=0; i<n; i++){
	delytemp = delytemp + ((yn[i]-yi[i])*(yn[i]-yi[i]));
}
double dely;
if(n<10){
dely = (sqrt(delytemp/(n)));
}
else{
	dely = (sqrt (delytemp/(n-2)));
}
cout<<dely<<endl;
cout<<endl;

cout<<"Now, the errors in the slope (b) and intercept (a) can be calculated using : "<<endl;
cout<<"			## delA = DelY*(sumX^2/((N*sumX^2) - (sumX)^2)) "<<endl;
cout<<" 		## delB = DelY*(N/((N*sumX^2) - (sumX)^2)) "<<endl;
cout<<endl;

double dela, delb, deltemp;
deltemp=(n*sumxi2)-((sumxi)*(sumxi));
dela = dely*(sqrt((sumxi2)/deltemp));
delb = dely*(sqrt((n)/deltemp));

cout<<deltemp<<" bakchodi"<<endl;
cout<<"calculating, we get: ** Error in the slope (delB) is : "<<delb<<endl;
cout<<"		**And the error in the Y intercept (delA) is : "<<dela<<endl;

cout<<"_________________________________________________________"<<endl;
cout<<"Therefore the final value of slope 'b' is :'"<<b<<"' with an error of (+/-)"<<delb<<"."<<endl;
cout<<"And the final value of intercept 'a' is :'"<<a<<"' with an error of (+/-) "<<dela<<"."<<endl;
cout<<endl;
cout<<endl;
cout<<"~ Jyo :)"<<endl;
cout<<endl;


	

	
	return 0;
	
}
