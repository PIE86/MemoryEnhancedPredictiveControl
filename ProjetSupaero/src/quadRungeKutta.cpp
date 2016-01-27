
// In this script both u and x are at one time instant
// therefore, the result calculated is only the one step
// further.
// Thus, in the calculation of k1,k2,k3 and k4
// the value of input u stay the same value.
#include"Functions.h"

double* quadRungeKutta(double t,double*x,double*u,int lenX,double dt)
{
	// Construction of the slopes K
	double** k = new double*[4];
	//for(int i=0;i<4;i++)
	//{
	//	k[i] = new double[lenX];
	//}


	// Intermediate variables
	// for the calculation of the slopes
	double** x1 = new double*[3];
	for(int i=0;i<3;i++)
	{
		x1[i] = new double[lenX];
	}
	double t1,t2,t3;
	t1 = t + dt/2;
	t2 = t1;
	t3 = t + dt;

	
	// Calculation of k
	k[0] = quadModel(t,x,u,lenX);
	
	for(int j=0;j<lenX;j++)
	{
		x1[0][j] = x[j] + dt/2*k[0][j];
	}
	k[1] = quadModel(t1,x1[0],u,lenX);
	
	for(int j=0;j<lenX;j++)
	{
		
		x1[1][j] = x[j] + dt/2*k[1][j];
	}
	k[2] = quadModel(t2,x1[1],u,lenX);

	for(int j=0;j<lenX;j++)
	{
		
		x1[2][j] = x[j] + dt*k[2][j];
	}
	k[3] = quadModel(t3,x1[2],u,lenX);

	
	// The result -- next step position
	double* res = new double[lenX];
	for(int i=0;i<lenX;i++)
	{
		res[i] = x[i] + dt/6*(k[0][i]+2*k[1][i]+2*k[2][i]+k[3][i]);
	}


	// Free the occupied memory
	for(int i=0;i<4;i++)
	{
		delete [] k[i];
		if(i<3)
			delete [] x1[i];
	}
	delete [] k;
	delete [] x1;

	return res;
}





