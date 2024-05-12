#include<iostream>
#include<vector>
#include<math.h>
#include<stack>

using std::vector;
using std::stack;
using std::max;
using std::min;

class Solution{
    public:
        //左右最高柱
        int trap1(vector<int>& height){
            int width=height.size();
            vector<int> LeftMax(width);
            vector<int> RightMax(width);
            int ans=0;
            LeftMax[0]=height[0];
            for(int i=1;i<width-1;i++){
                LeftMax[i]=max(LeftMax[i-1],height[i]);
            }
            RightMax[width-1]=height[width-1];
            for(int j=width-2;j>0;j--){
                RightMax[j]=max(RightMax[j+1],height[j]);
            }
            for(int k=1;k<width-1;k++){
                ans+=min(LeftMax[k],RightMax[k])-height[k];
            }
            return ans;
        }

        //单调栈
        int trap2(vector<int>& height){
            int width=height.size();
            int ans=0;
            stack<int> stk;
            for(int i=0;i<width;i++){
            while(stk.size()&&height[i]>height[stk.top()]){
                int l=height[stk.top()];
                stk.pop();
                if(stk.size()){
                    int h=min(height[i],height[stk.top()]);
                    int capacity=(h-l)*(i-stk.top()-1);
                    ans+=capacity;
                }
            }
            stk.push(i);
        }
        return ans;
        }

        //双指针
        int trap3(vector<int>& height){
            int width=height.size();
            int ans=0;
            int leftp=0, rightp=width-1;
            int LeftMax=0, RightMax=0;
            while(leftp<rightp){
                LeftMax=max(LeftMax,height[leftp]);
                RightMax=max(RightMax,height[rightp]);
                if(LeftMax<RightMax){
                    ans+=LeftMax-height[leftp];
                    leftp++;
                }else{
                    ans+=RightMax-height[rightp];
                    rightp--;
                }
            }
            return ans;
        }
};