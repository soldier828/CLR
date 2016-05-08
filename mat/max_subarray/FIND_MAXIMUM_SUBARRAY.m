function  [final_low,final_high,final_sum]=FIND_MAXIMUM_SUBARRAY(A,low,high)
if low==high
    final_low = low;
    final_high = high;
    final_sum = A(low);
    return;
else
    mid=round((low+high)/2-0.5);
    [left_low,left_high,left_sum]  = FIND_MAXIMUM_SUBARRAY(A,low,mid);
    [right_low,right_high,right_sum] = FIND_MAXIMUM_SUBARRAY(A,mid+1,high);
    [cross_low,cross_high,cross_sum] = FIND_MAX_CROSS_SUBARRAY(A,low,mid,high);
    if left_sum > right_sum && left_sum > cross_sum
        final_low = left_low;
        final_high = left_high;
        final_sum = left_sum;
    elseif  right_sum > left_sum && right_sum > cross_sum
        final_low = right_low;
        final_high = right_high;
        final_sum = right_sum;
    else
        final_low = cross_low;
        final_high = cross_high;
        final_sum = cross_sum;
    end
end
        