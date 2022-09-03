maxh.erase(maxh.lower_bound(lf));
}else{
minh.erase(minh.lower_bound(lf));
}
//Insert incoming
int sz1= maxh.size(), sz2 = minh.size();
if(sz1==sz2 || sz1-1==sz2){
maxh.insert(nums[i]);
}else if(sz1+1==sz2 || sz1+2 == sz2){
minh.insert(nums[i]);
}
}//for
if(k&1){
median.push_back(*(maxh.end()));
}else{
median.push_back((*(minh.begin()) + *(maxh.end()))/2);
}
return median;
}//func
};