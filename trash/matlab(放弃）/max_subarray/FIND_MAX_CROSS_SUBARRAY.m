function [max_left,max_right,sum]=FIND_MAX_CROSS_SUBARRAY(A,low,mid,high)
left_sum=-realmax;
sum=0;
for i=mid:-1:low
    sum=sum+A(i);
    if sum > left_sum
        left_sum = sum;
        max_left = i;
    end
end

right_sum=-realmax;
sum=0;
for i=mid+1:high
    sum=sum+A(i);
    if sum > right_sum
        right_sum = sum;
        max_right = i;
    end
end
sum=left_sum+right_sum;
