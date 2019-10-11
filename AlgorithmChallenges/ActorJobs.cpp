#include <iostream>

enum Months
{
	jan,
	feb,
	mar,
	apr,
	may,
	jun,
	jul,
	aug,
	sep,
	oct,
	nov,
	dec
};

class Job
{
public:
	
	int startMonth;
	int endMonth;

	Job(Months start, Months end) 
	{
		startMonth = start;
		endMonth = end;
	}

};

bool Overlaping(Job jobOne, Job jobTwo)
{
	if (jobOne.startMonth < jobTwo.endMonth && jobOne.endMonth > jobTwo.startMonth) return true;
	else false;
}

int main() 
{
	Job allJobs[11] =
	{
		Job(jan, oct),
		Job(may, jun),
		Job(jan, apr),
		Job(oct, dec),
		Job(aug, oct),
		Job(apr, aug),
		Job(feb, jul),
		Job(sep, nov),
		Job(may, jul),
		Job(jan, feb),
		Job(feb, mar)
	};

	int jobMemo[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int memoSize = 0;

	for (int i = 0; i < 11; i++)
	{
		memoSize = 1;
		jobMemo[memoSize - 1] = i;

		for (int n; n < 11; n++) 
		{
			bool addJob = true;
			for (int k; k < memoSize; k++)
			{
				if (jobMemo[k] != n && Overlaping(allJobs[jobMemo[k]], allJobs[n])) 
				{
					addJob = false;
					break;
				}
			}
			if (addJob) 
			{
				memoSize++;
				jobMemo[memoSize - 1] = n;
			}
		}

		std::cout << "job count is : " << memoSize << " the job list no : ";
		for (size_t i = 0; i < memoSize; i++)
		{
			std::cout << jobMemo[i] << " | ";
		}
		std::cout << "\n";
	}


}

