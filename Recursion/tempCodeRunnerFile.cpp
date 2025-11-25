f(i == n){
            if(target == 0){
                result.push_back(temp);
            }
            else return;
        }

        if(candidates[i] <= target){
            target -= candidates[i];
            temp.push_back(candidates[i]);
            helper(i,target,temp,result,candidates,n);
            target += candidates[i];
        }

        helper(i+1,target,temp,result,candidates,n);