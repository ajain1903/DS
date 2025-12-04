#include <iostream>
#include <vector>
#include <algorithm>
void maxheapsort(std::vector<int> &x){
    for(int j=x.size()-1;j>0;j--){
    for (int i = 2; i <j+1; i++)
    {
        int idx=i;
        while(x[idx]>x[idx/2])
        {
            std::swap(x[idx],x[idx/2]);
            if(idx/2==1)break;
            else idx=idx/2;
        }
        
    }
    std::swap(x[1],x[j]);
}
    
    return;
}
void maxheapify(std::vector<int> &x){
    for (int i = x.size()-1; i >0; i--)
    {
        int idx=i;
        if(idx*2>x.size()-1)continue;

        while (1)
        {
            int large{-1000000};
            int tidx{-1};
            if (idx*2<x.size() && x[idx]<x[idx*2])
            {
                large=x[idx*2];
                tidx=idx*2;
            }
            if((idx*2)+1<x.size() && x[idx]<x[idx*2+1])
            {
                if (x[(idx*2)+1]>large)
                {
                    large = x[(idx*2)+1];
                    tidx = (idx*2)+1;
                    
                }  
            }
            if(tidx==-1)break;
            std::swap(x[idx],x[tidx]);
            std::cout<<"swapped "<<x[tidx]<<" "<<x[idx]<<std::endl;
            idx=tidx;
        }
    }
    
}
int main(){
    std::vector<int> x={0,10,20,15,30,40};
    maxheapsort(x);
    //std::vector<int> x={0,10,20,15,12,40,25,18};
    //maxheapify(x);
    for (auto i=1;i<x.size();i++)
    {
        std::cout<<x[i]<<" ";
    }
    
    return 0;
}