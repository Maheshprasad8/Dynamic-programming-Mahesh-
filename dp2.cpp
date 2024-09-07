Problem statement
Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.

code in cpp
1.recursion
2.top-down
3.bottom-up


Solve by 3 method
#include<vector>
// int solve(int n, vector<int>&days, vector<int>&cost,int index,vector<int>&dp){
//     if(index>=n){
//         return 0;
//     }
//     // for day 1
//     int option1=cost[0]+solve(n,days,cost,index+1,dp);
// // for day2
// int i;
// for(i=index;i<n && days[i]<days[index]+7;i++);
// int option2=cost[1]+solve(n,days,cost,i,dp);
// // here i is 7 din ke baad agla index
// for(i=index;i<n && days[i]<days[index]+30;i++);
// int option3=cost[2]+solve(n,days,cost,i,dp);
// // here i is 30 din ke baad agla index
// dp[index]=min(option1,min(option2,option3));
// return dp[index];
// }


// 3rd method Tabulation bottom Up approach

// int solve(int n, vector<int>&days, vector<int>&cost){
//    vector<int>dp(n+1,-1);
//   dp[n]=0;
//   for(int k=n-1;k>=0;k--){
//     int option1=cost[0]+dp[k+1];
//     int i;
//     for(i=k;i<n && days[i]<days[k]+7;i++);
//       int option2=cost[1]+dp[i];
    

//     for(i=k;i<n && days[i]<days[k]+30;i++);
//       int option3=cost[2]+dp[i];
    
//     dp[k]=min(option1,min(option2,option3));
//   }
//   return dp[0];
//   }
   
   //3rd method space optimization




int minimumCoins(int n, vector<int> days, vector<int> cost)
{
  // vector<int>dp(n+1,-1);
  // return solve(n,days,cost,0,dp); 


  // return solve(n,days,cost);
  int ans=0;
  queue<pair<int,int>>month;
  queue<pair<int,int>>week;
  for(int day:days){
    while(!month.empty() && month.front().first+30<=day){
      month.pop();

    }
    while(!week.empty() && week.front().first+7<=day){
      week.pop();
    }
    week.push(make_pair(day,ans+cost[1]));
    month.push(make_pair(day,ans+cost[2]));
    ans=min(ans+cost[0],min(week.front().second,month.front().second));
  }
   return ans;
}
