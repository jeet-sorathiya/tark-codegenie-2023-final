#include <bits/stdc++.h>
using namespace std;
class Train
{  
    
    public:
    static int totalTrain;

    string trainNO;
    string start;
    int startDistance;
    string end;
    int endDistance;

    //coach
    

    Train(string trainNo, string start, int startDistance, string end, int endDistance)
    {
       // totalTrain++;
      
        this->trainNO = trainNo;
        this->start = start;
        this->startDistance = startDistance;
        this->end = end;
        this->endDistance = endDistance;
    }

   

    void print(Train *t)
    {
        cout<<t->trainNO<<endl;
        cout<<t->start<<endl;
        cout<<t->startDistance<<endl;
        cout<<t->end<<endl;
        cout<<t->endDistance<<endl;

    }

};

class Coach
{
    public:
    unordered_map<string,int> S;
    unordered_map<string,int> B;
    unordered_map<string,int> A;
    unordered_map<string,int> H;

     void setCoach(string coachName, int sloat)
    {
        if(coachName[0] == 'S')
        {
            S[coachName]=sloat;
        }
        else if(coachName[0] == 'B')
        {
            B[coachName]=sloat;
        }
         else if(coachName[0] == 'A')
        {
            A[coachName]=sloat;
        }
         else if(coachName[0] == 'H')
        {
            H[coachName]=sloat;
        }
    }


};

vector<string> splitInput(string input, char ch)
{
    vector<string> ans;
    string temp;
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == ch)
        {
           ans.push_back(temp);
          //  cout<<ch<<" "<<temp<<endl;
           temp = "";
           
        }
        else
        {
             temp += input[i];
        }
    }
    ans.push_back(temp);
   //  cout<<ch<<" "<<temp<<endl;
    return ans;

}
int main()
{

    int noOfTrain;
    cin>>noOfTrain;
    string objName = "t1";
    string input1;
    string input2;
    cin.ignore();
    while(noOfTrain--)
    {
        getline(cin,input1);
        getline(cin,input2);
        vector<string> trainDetails = splitInput(input1,' ');
        vector<string> starting = splitInput(trainDetails[1],'-');
        vector<string> ending = splitInput(trainDetails[2],'-');
        
        string trainNo = trainDetails[0];
         string start = starting[0];
         string temp1 = starting[1];
         int startDistance = stoi(temp1);
         string end = ending[0];
         string temp2 = ending[1];
         int endDistance = stoi(temp2);

        Train *t1 = new Train(trainNo,start,startDistance,end,endDistance); 
        objName[1] += 1;
        
        getline(cin,input1);
        Coach *c1 = new Coach();
        vector<string> coachDetails = splitInput(input1,' ');
        for(int i = 1; i < coachDetails.size(); i++)
        {
            vector<string> coach = splitInput(coachDetails[i],'-');
            string coachName = coach[0];
            string temp = coach[1];
            int slot = stoi(temp);
            c1->setCoach(coachName,slot);

           
            
        }


    }


// end
return 0;
}