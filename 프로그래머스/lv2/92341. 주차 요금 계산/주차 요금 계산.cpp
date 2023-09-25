#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int basicTime = fees[0];
    int basicPrice = fees[1];
    int unitTime = fees[2];
    int unitPrice = fees[3];
    
    map<int,int> total;
    map<int,int> in;
    int hour=0;
    string minute ="";
    int carNum=0;
    string inOut = "";
    for(auto r : records)
    {
        istringstream ss(r);
        
        //분이 :@@ 이런식으로 저장됨
        ss >> hour >> minute >> carNum >> inOut;
        
        if(inOut == "IN")
        {
            in[carNum] = hour*60 + stoi(minute.substr(1,2));
        }
        else if(inOut == "OUT")
        {
            total[carNum] += ((hour*60 + stoi(minute.substr(1,2))) - in[carNum]);
            in[carNum] = -1;
        }
    }
    
    for(auto iter : in)
    {
        if(iter.second != -1)
        {
            //23:59분 출차로 잡음
            total[iter.first] += (1439 - iter.second);
        }
    }
    
    for(auto iter : total)
    {
        int totalTime = iter.second - basicTime;
        int totalPrice = basicPrice;
        
        //기본시간내에 출차
        if(totalTime <=0)
        {
            answer.push_back(totalPrice);
        }
        else
        {
            totalPrice += (totalTime / unitTime) * unitPrice;
            
            if((totalTime%unitTime) >0)
                totalPrice += unitPrice;
            answer.push_back(totalPrice);
        }
    }
    
    return answer;
}