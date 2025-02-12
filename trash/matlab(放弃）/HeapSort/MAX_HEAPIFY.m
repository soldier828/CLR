function A = MAX_HEAPIFY(A, i, A_heapsize)
left = 2*i;
right = 2*i+1;

if left <= A_heapsize && A(left) > A(i)
    largest = left;
else
    largest = i;
end

if right <= A_heapsize && A(right) > A(largest)
    largest = right;
end

if largest ~= i
    temp = A(i);
    A(i) = A(largest);
    A(largest) = temp;
    A = MAX_HEAPIFY(A, largest, A_heapsize);
end
    