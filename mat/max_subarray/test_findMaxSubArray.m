% Answer:final_low = 8, final_high = 11, final_sum=43

testArray = [13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7];
low = 1;
high = length(testArray);
[final_low,final_high,final_sum]=FIND_MAXIMUM_SUBARRAY(testArray,low,high)