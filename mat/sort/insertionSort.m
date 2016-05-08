% input must be row vector
function Array=insertionSort(Array)
if size(Array,1) ~= 1
    disp('input must be row vector');
    return;
else
    len=size(Array,2);
    for i=2:len
        key=Array(i);
        j=i-1;
        while(j>0 && Array(j) > key)
            Array(j+1)=Array(j);
            j=j-1;
        end
        Array(j+1)=key;
    end
end
      