#include <iostream>
#include <vector>
using namespace std;

vector<int> findElements(int number,vector<int> num_sequence,int last_answer,int troll_answer)
{
	if(number==0)
	{
	}else{
		if(last_answer<troll_answer) //In case the previous answer was wrong
		{
			num_sequence[number-1] = 1;
		}else{ //In case the prev answer was right
			num_sequence[number-1] = 1;
			num_sequence[number-2] = 0;
		}
	}
	return num_sequence;
}

int main(int argc,const char *argv[]) {
    int troll_answer, seq_num, times=0;
	bool first_time = true; 
	vector<int> sequence,final_sequence, troll_answers;
    cin >> troll_answer;
    troll_answers.push_back(troll_answer);
    	while(times<=troll_answers[0]+2)
    {
    if(first_time)
    {
    	cout<<"Q"<<" ";
    	for(int i = 0; i<=troll_answer-1; i++)
    	{
    		sequence.push_back(0);
    		cout<<sequence[i]<<" ";
		}
		cout<<endl;
		cout.flush();
		seq_num = troll_answer;
		final_sequence = findElements(times,sequence,troll_answers[times-1],troll_answers[times]);
		times++;
		first_time = false;
	} 
	else{
        cin >> troll_answer;
        troll_answers.push_back(troll_answer);
		if(times != seq_num+1 && troll_answer!=seq_num) //Maybe the answer can be found earlier
		{
			final_sequence = findElements(times,final_sequence,troll_answers[times-1],troll_answers[times]);
			cout<<"Q ";
			for(int i = 0; i<=final_sequence.size()-1;i++)
			{
				cout<<final_sequence[i]<<" ";
			}
			cout<<endl; //Ic o?i?nauoeeu
			cout.flush();
			times++;
	}else{
		cout<<"A ";
		for(int i = 0; i<=final_sequence.size()-1;i++)
			{
				cout<<final_sequence[i]<<" ";
			}
			cout.flush();
			break;
	}
}
    }
}
