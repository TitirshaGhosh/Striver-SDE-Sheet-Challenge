class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> mp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
            return profit(prices,0,1,1,mp);
    }
        int profit(vector<int>& prices,int currentday,int canbuy,int trans, vector<vector<vector<int>>>&mp){
                if(currentday>=prices.size()|| trans==0){
                        return 0;
                }
                 if(mp[ currentday][canbuy][trans]!= -1)
                         return mp[ currentday][canbuy][trans];
                int ans=0,idle,buy,sell;
                if(canbuy==1){
                        idle=profit(prices,currentday+1,canbuy,trans,mp);
                        buy=-prices[currentday]+profit(prices,currentday+1,0,trans,mp);
                        ans=max(idle,buy);
                }
                else{
                        idle=profit(prices,currentday+1,canbuy,trans,mp);
                        sell=prices[currentday]+profit(prices,currentday+1,1,trans-1,mp);
                         ans=max(idle,sell);
                }
               mp[currentday][canbuy][trans]=ans;
                return ans;
        }
};
