#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>


int SolveProblem(long long sizeOfCircle, long long amountOfPaint, long long result);
long double myPower(long double value, long double exp);

int main()
{
	FILE * fileIn;
	FILE * fileOut;
	int numTestCases;
	long double sizeOfCircle = 0;
	long double amountOfPaint = 0;

	fileIn = fopen("D:\\TEMP\\Google\\Small.in", "r");
	fileOut = fopen("D:\\TEMP\\Google\\res.out", "w");

	if (fileIn == NULL || fileOut == NULL)
	{
		printf("Cannot open file\n");
		getchar();
		return 0;
	}

	fscanf(fileIn, "%d", &numTestCases);

	for (int i = 0; i < numTestCases; i++)
	{
		fscanf(fileIn, "%lf %lf", &sizeOfCircle, &amountOfPaint);

		long double areaToPaint = 0;
		long long result = 0;

		amountOfPaint = amountOfPaint * (long double)M_PI;

		while (amountOfPaint > 0)
		{
			long double areaOfLastCircle = myPower(sizeOfCircle, (long double)2) * M_PI;
			long double areaOfNewCircle = myPower((sizeOfCircle + 1), (long double)2) * M_PI;
			areaToPaint = areaOfNewCircle - areaOfLastCircle;

			if (areaToPaint <= amountOfPaint)
			{
				amountOfPaint = amountOfPaint - areaToPaint;
				sizeOfCircle = sizeOfCircle + 2;
				++result;
			}
			else
			{
				break;
			}

			
		}
		fprintf(fileOut, "Case #%d: %lld\n", i + 1, result);	
	}

	fclose(fileIn);
	fclose(fileOut);
	
	return 1;
}

long double myPower(long double value, long double exp)
{
	long long index = 1;
	long double newValue = value;
	while (index < exp)
	{
		newValue = newValue * newValue;
		++index;
	}

	return newValue;
}