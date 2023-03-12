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

    Train()
{

}    

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

class Coach : public Train
{
    public:
    unordered_map<string,int> S;
    unordered_map<string,int> B;
    unordered_map<string,int> A;
    unordered_map<string,int> H;

    Coach()
    {

    }

     void setcoach(string coachName, int sloat)
    {
        unordered_map<string,int> temp;
        temp[coachName]=sloat;
       // cout<<temp[coachName]<<endl;
        if(coachName[0] == 'S')
        {
            this->S.insert({coachName,sloat});
        }
        else if(coachName[0] == 'B')
        {
            this->B.insert({coachName,sloat});
        }
         else if(coachName[0] == 'A')
        {
            this->A.insert({coachName,sloat});
        }
         else if(coachName[0] == 'H')
        {
            this->H.insert({coachName,sloat});
        }
    }


};

class Ticket : public Coach
{
    public:
   static int pnr_counter; 
     Ticket()
     {

     }
   Ticket(string coach,int totalNeed, Train objtrain)
   {
        int distance = objtrain.endDistance - objtrain.startDistance;
        if(coach == "SL")
        {
            cout<<pnr_counter<<" "<< 1*totalNeed*distance<<endl;
        }
         if(coach == "3A")
        {
            cout<<pnr_counter<<" "<<2*totalNeed*distance<<endl;
        }
         if(coach == "2A")
        {
            cout<<pnr_counter<<" "<<3*totalNeed*distance<<endl;
        }
         if(coach == "1A")
        {
            cout<<pnr_counter<<" "<<4*totalNeed*distance<<endl;
        }
        pnr_counter++;
   }
};

int Ticket::pnr_counter = 100000001; // starting PNR number

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


bool isAvail(Coach objCoach, string coach, int totalNeed)
{
    for(int i = 0; i < objCoach.S.size(); i++)
    {
        string ch = "S1";
        if( (objCoach.S[ch] -= totalNeed ) >= 0)
        {
            objCoach.S[ch] -= totalNeed;
        }
        else
        {
            return false;
        }  
        ch[1]+=1;      
   }
   return true;
}

int main()
{

    int noOfTrain;
    cin>>noOfTrain;
    string input1;
    string input2;
    cin.ignore();
    vector<Train> objTrain;
    vector<Coach> objCoach;
    
    //step 1: input train details
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
        objTrain.push_back(*t1);
    
    
        Coach *c1 = new Coach();
        vector<string> coachDetails = splitInput(input2,' ');
        for(int i = 1; i < coachDetails.size(); i++)
        {
            vector<string> coach = splitInput(coachDetails[i],'-');
            string coachName = coach[0];
            string temp = coach[1];
            int slot = stoi(temp);
            c1->setcoach(coachName,slot);

        }
        objCoach.push_back(*c1);

     // cout<<objTrain.size();
    }
    // step 2 : booking 
    while(true)
    {
        string input;
        getline(cin,input);
        vector<string> booking = splitInput(input,' ');
        int count = 0;
        for(auto train : objTrain)
        {
           count++;
            if(train.start == booking[0] && train.end == booking[1])
            {
                 //objCoach[count-1]
                 string temp = booking[4];
                 int totalNeed = stoi(temp);
               //  cout<<"total"<<totalNeed;
                 if(booking[3] == "SL" && isAvail(objCoach[count-1],"SL",totalNeed))
                 {
                    Ticket *objticket = new Ticket("SL",totalNeed,train);
                    break;
                 }
                else if(booking[3] == "3A" && isAvail(objCoach[count-1],"3A",totalNeed))
                 {
                    Ticket *objticket = new Ticket("3A",totalNeed,train);
                    break;

                 }
                else if(booking[3] == "2A" && isAvail(objCoach[count-1],"2A",totalNeed))
                 {
                    Ticket *objticket = new Ticket("2A",totalNeed,train);
                    break;

                 }
                else if(booking[3] == "1A" && isAvail(objCoach[count-1],"1A",totalNeed))
                 {
                    Ticket *objticket = new Ticket("1A",totalNeed,train);
                    break;

                 }
                 else
                 {
                    cout<<"No Seats Available"<<endl;
                    break;

                 }
            }
             // no any train for that request.
            else
            {
                cout<<"No Trains Available"<<endl;
                break;
            }
        }
    }


// end
return 0;
}